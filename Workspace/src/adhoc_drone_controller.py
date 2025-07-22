# File: adhoc_drone_controller_revised.py

import socket
import threading
import json
import time
import subprocess
import logging
import argparse
from collections import deque

# --- Global Configuration ---
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(name)s - %(levelname)s - %(message)s')
logger = logging.getLogger("DroneController")

# --- Discovery Class (Revised) ---
class Discovery:
    def __init__(self, drone_id, discovery_port=19999):
        self._drone_id = drone_id
        self._port = discovery_port
        self.on_peer_discovered = None
        self._running = True
        
        self.adhoc_config = {
            "interface": "wlo1",
            "ssid": "drone-swarm-net",
            "ip_base": "192.168.1.",
            "self_ip_ending": self._get_ip_ending_from_id()
        }
        self._original_connection = self._get_active_connection()
        self._broadcast_ip = f"{self.adhoc_config['ip_base']}255"
        self._threads = []

    def _get_ip_ending_from_id(self):
        try:
            return str(int(''.join(filter(str.isdigit, self._drone_id))))
        except (ValueError, IndexError):
            return str(abs(hash(self._drone_id)) % 254 + 1)

    def _run_command(self, command):
        logger.info(f"Running command: {' '.join(command)}")
        try:
            process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            stdout, stderr = process.communicate()
            if process.returncode != 0:
                logger.error(f"Command failed: {stderr.decode().strip()}")
                return False
            return True
        except Exception as e:
            logger.error(f"Exception running command: {e}")
            return False

    def setup_adhoc_network(self):
        """Synchronously sets up the ad-hoc network. Returns True on success."""
        logger.info("Configuring ad-hoc network...")
        iface = self.adhoc_config["interface"]
        ssid = self.adhoc_config["ssid"]
        ip_address = f"{self.adhoc_config['ip_base']}{self.adhoc_config['self_ip_ending']}/24"

        commands = [
            ['sudo', 'nmcli', 'dev', 'set', iface, 'managed', 'no'],
            ['sudo', 'ip', 'link', 'set', iface, 'down'],
            ['sudo', 'iwconfig', iface, 'mode', 'ad-hoc'],
            ['sudo', 'iwconfig', iface, 'essid', ssid],
            ['sudo', 'iwconfig', iface, 'channel', '6'],
            ['sudo', 'ip', 'link', 'set', iface, 'up'],
            ['sudo', 'ip', 'addr', 'flush', 'dev', iface],
            ['sudo', 'ip', 'addr', 'add', ip_address, 'dev', iface],
        ]

        for cmd in commands:
            if not self._run_command(cmd):
                logger.error("Failed to set up ad-hoc network.")
                return False
        
        logger.info(f"Ad-hoc network '{ssid}' configured on {iface} with IP {ip_address}.")
        return True

    def teardown_adhoc_network(self):
        """Restores the original network configuration."""
        logger.info("Restoring original network state...")
        iface = self.adhoc_config["interface"]
        self._run_command(['sudo', 'ip', 'addr', 'flush', 'dev', iface])
        self._run_command(['sudo', 'nmcli', 'dev', 'set', iface, 'managed', 'yes'])
        if self._original_connection:
            self._run_command(['sudo', 'nmcli', 'con', 'up', 'id', self._original_connection])
        else:
            logger.warning("No known previous connection to restore.")

    def start_threads(self):
        """Starts the broadcast and listen threads."""
        logger.info(f"Starting discovery threads on port {self._port}...")
        broadcast_thread = threading.Thread(target=self._broadcast_presence)
        listen_thread = threading.Thread(target=self._listen_for_peers)
        self._threads.extend([broadcast_thread, listen_thread])
        broadcast_thread.start()
        listen_thread.start()

    def stop_threads(self):
        """Stops the broadcast and listen threads."""
        if not self._threads: return
        logger.info("Stopping discovery threads...")
        self._running = False
        for thread in self._threads:
            thread.join()
        self._threads = []
        self._running = True # Reset for potential restart

    def _get_active_connection(self):
        try:
            result = subprocess.check_output(['nmcli', '-t', '-f', 'NAME,DEVICE', 'con', 'show', '--active'], stderr=subprocess.DEVNULL).decode()
            for line in result.strip().split('\n'):
                if not line.strip(): continue
                name, dev = line.split(':')
                if dev == self.adhoc_config["interface"]:
                    return name
        except Exception:
            return None
        return None

    def _broadcast_presence(self):
        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
        ip_address = f"{self.adhoc_config['ip_base']}{self.adhoc_config['self_ip_ending']}"
        message = json.dumps({"id": self._drone_id, "ip": ip_address})
        while self._running:
            try:
                sock.sendto(message.encode(), (self._broadcast_ip, self._port))
            except Exception as e:
                logger.error(f"Broadcast error: {e}")
            time.sleep(5)

    def _listen_for_peers(self):
        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        try:
            sock.bind(('', self._port))
        except socket.error as e:
            logger.error(f"Socket bind failed on port {self._port}: {e}")
            return
        sock.settimeout(1.0)
        while self._running:
            try:
                data, addr = sock.recvfrom(1024)
                message = json.loads(data.decode())
                peer_id = message.get("id")
                peer_ip = message.get("ip")
                if peer_id and peer_ip and peer_id != self._drone_id:
                    if self.on_peer_discovered:
                        self.on_peer_discovered(peer_id, peer_ip)
            except socket.timeout:
                continue
            except Exception as e:
                logger.error(f"Listener error: {e}")

# --- Connection Manager Class (Unchanged) ---
class ConnectionManager:
    """Manages all network connections (TCP and UDP)."""
    def __init__(self, drone_id, on_message_received_callback):
        self._drone_id = drone_id
        self.on_message_received = on_message_received_callback
        
        # NOTE: This IP will be updated after network setup.
        self._ip = None 
        self._tcp_port = 20000
        self._udp_port = 20001
        
        self._running = True
        self._threads = []
        self._clients = {} # {drone_id: socket}
        self._peers = {} # {drone_id: {"ip": str, "protocol": str}}
        self.message_queue = deque()

    def update_ip(self):
        """Updates the internal IP address after network changes."""
        self._ip = socket.gethostbyname(socket.gethostname())
        logger.info(f"Connection Manager IP updated to {self._ip}")

    def start(self):
        """Starts the server and message processing threads."""
        self.update_ip()
        logger.info(f"Starting connection manager for {self._drone_id} at {self._ip}")
        threads_to_start = [
            threading.Thread(target=self._tcp_server_loop),
            threading.Thread(target=self._udp_server_loop),
            threading.Thread(target=self._process_message_queue)
        ]
        for t in threads_to_start:
            t.start()
            self._threads.append(t)

    def stop(self):
        """Stops all connections and threads."""
        if not self._threads: return
        self._running = False
        for peer_id, client_socket in list(self._clients.items()):
            try: client_socket.close()
            except Exception: pass
        for thread in self._threads:
            thread.join()
        self._threads = []
        self._running = True # Reset
        logger.info("Connection manager stopped.")

    # ... (The rest of the ConnectionManager class is identical to the previous version) ...
    def connect_to_peer(self, peer_id, peer_ip, protocol="TCP"):
        if peer_id in self._clients:
            logger.info(f"Already connected to {peer_id}.")
            return
        logger.info(f"Attempting to connect to {peer_id} at {peer_ip} via {protocol}...")
        try:
            if protocol == "TCP":
                sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                sock.connect((peer_ip, self._tcp_port))
            else: # UDP
                sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
            self._clients[peer_id] = sock
            self._peers[peer_id] = {"ip": peer_ip, "protocol": protocol}
            logger.info(f"Successfully connected to {peer_id} via {protocol}.")
        except Exception as e:
            logger.error(f"Failed to connect to {peer_id}: {e}")

    def disconnect_from_peer(self, peer_id):
        if peer_id in self._clients:
            logger.info(f"Disconnecting from peer {peer_id}.")
            try: self._clients[peer_id].close()
            except Exception: pass
            finally:
                del self._clients[peer_id]
                if peer_id in self._peers: del self._peers[peer_id]
        else:
            logger.warning(f"No active client connection found for {peer_id} to disconnect.")

    def send_message(self, peer_id, message_dict):
        if peer_id not in self._clients:
            logger.warning(f"Not connected to {peer_id}. Cannot send message.")
            return
        try:
            sock = self._clients[peer_id]
            protocol = self._peers[peer_id]['protocol']
            if 'drone_id' not in message_dict: message_dict['drone_id'] = self._drone_id
            message_json = json.dumps(message_dict)
            if protocol == "TCP":
                sock.sendall(message_json.encode('utf-8') + b'\n')
            else: # UDP
                dest_ip = self._peers[peer_id]['ip']
                sock.sendto(message_json.encode('utf-8'), (dest_ip, self._udp_port))
            logger.debug(f"Sent message to {peer_id}: {message_json}")
        except Exception as e:
            logger.error(f"Error sending message to {peer_id}: {e}")
            self._handle_disconnection(peer_id)

    def _handle_disconnection(self, peer_id):
        logger.warning(f"Peer {peer_id} disconnected.")
        self.disconnect_from_peer(peer_id)

    def _tcp_server_loop(self):
        server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        server_socket.bind(('', self._tcp_port))
        server_socket.listen(5)
        server_socket.settimeout(1.0)
        logger.info(f"TCP server listening on port {self._tcp_port}")
        while self._running:
            try:
                client_socket, addr = server_socket.accept()
                logger.info(f"Accepted TCP connection from {addr}")
                handler_thread = threading.Thread(target=self._handle_tcp_client, args=(client_socket,))
                handler_thread.start()
                self._threads.append(handler_thread)
            except socket.timeout: continue
            except Exception as e:
                if self._running: logger.error(f"TCP Server error: {e}")
        server_socket.close()

    def _handle_tcp_client(self, client_socket):
        buffer = ""
        peer_id = None
        addr = client_socket.getpeername()
        while self._running:
            try:
                data = client_socket.recv(4096)
                if not data: break
                buffer += data.decode('utf-8')
                while '\n' in buffer:
                    message_json, buffer = buffer.split('\n', 1)
                    if message_json:
                        message = json.loads(message_json)
                        if peer_id is None:
                            peer_id = message.get('drone_id')
                            if peer_id:
                                self._clients[peer_id] = client_socket
                                self._peers[peer_id] = {"ip": addr[0], "protocol": "TCP"}
                                logger.info(f"Identified TCP peer as {peer_id}")
                        self.message_queue.append(message)
            except Exception as e:
                logger.error(f"Error handling TCP client {peer_id or addr}: {e}")
                break
        if peer_id: self._handle_disconnection(peer_id)
        client_socket.close()

    def _udp_server_loop(self):
        server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        server_socket.bind(('', self._udp_port))
        server_socket.settimeout(1.0)
        logger.info(f"UDP server listening on port {self._udp_port}")
        while self._running:
            try:
                data, addr = server_socket.recvfrom(4096)
                message = json.loads(data.decode('utf-8'))
                self.message_queue.append(message)
            except socket.timeout: continue
            except Exception as e:
                if self._running: logger.error(f"UDP Server error: {e}")
        server_socket.close()
        
    def _process_message_queue(self):
        while self._running:
            try:
                message = self.message_queue.popleft()
                self.on_message_received(message)
            except IndexError:
                time.sleep(0.01)
            except Exception as e:
                logger.error(f"Error processing message queue: {e}")

# --- Main Controller Class (Revised) ---
class DroneController:
    """Orchestrates discovery and communication in the correct order."""
    def __init__(self, drone_id, interface, ssid):
        self.drone_id = drone_id
        self.processed_peers = set()
        
        self.discovery = Discovery(drone_id)
        self.discovery.adhoc_config["interface"] = interface
        self.discovery.adhoc_config["ssid"] = ssid
        self.discovery.on_peer_discovered = self._handle_peer_discovery

        self.connection_manager = ConnectionManager(self.drone_id, self._handle_message_received)

    def start(self):
        """Starts all drone services in the correct sequence."""
        logger.info(f"--- Starting Drone Controller for {self.drone_id} ---")
        
        logger.info("Step 1: Setting up Ad-Hoc Network...")
        if not self.discovery.setup_adhoc_network():
            logger.critical("Could not set up ad-hoc network. Aborting.")
            self.discovery.teardown_adhoc_network() # Attempt cleanup
            return
        
        time.sleep(2) # Give network time to stabilize

        logger.info("Step 2: Starting Connection Manager...")
        self.connection_manager.start()

        logger.info("Step 3: Starting Discovery Service...")
        self.discovery.start_threads()
        logger.info("--- Controller is Running ---")


    def stop(self):
        """Stops all drone services gracefully."""
        logger.info(f"--- Stopping Drone Controller for {self.drone_id} ---")
        self.discovery.stop_threads()
        self.connection_manager.stop()
        self.discovery.teardown_adhoc_network()
        logger.info("--- Controller Stopped ---")

    def _handle_message_received(self, message):
        sender = message.get('drone_id', 'Unknown')
        protocol = message.get('protocol', 'N/A')
        count = message.get('count', '?')
        logger.info(f"RECEIVED message from {sender} via {protocol} (Count: {count}): {message}")

    def _handle_peer_discovery(self, peer_id, peer_ip):
        if peer_id in self.processed_peers: return
        self.processed_peers.add(peer_id)
        logger.info(f"New peer '{peer_id}' discovered. Starting communication test sequence.")
        sequence_thread = threading.Thread(target=self._run_comm_sequence, args=(peer_id, peer_ip))
        sequence_thread.daemon = True
        sequence_thread.start()

    def _run_comm_sequence(self, peer_id, peer_ip):
        try:
            logger.info(f"[{peer_id}] === Starting UDP Test ===")
            self.connection_manager.connect_to_peer(peer_id, peer_ip, protocol="UDP")
            time.sleep(1)
            for i in range(3):
                self.connection_manager.send_message(peer_id, {"protocol": "UDP", "count": i + 1})
                time.sleep(0.5)
            self.connection_manager.disconnect_from_peer(peer_id)
            time.sleep(2)

            logger.info(f"[{peer_id}] === Starting TCP Test ===")
            self.connection_manager.connect_to_peer(peer_id, peer_ip, protocol="TCP")
            time.sleep(1)
            for i in range(3):
                self.connection_manager.send_message(peer_id, {"protocol": "TCP", "count": i + 1})
                time.sleep(0.5)
            self.connection_manager.disconnect_from_peer(peer_id)
            
            logger.info(f"[{peer_id}] === Communication sequence finished. ===")
        except Exception as e:
            logger.error(f"Error in communication sequence with {peer_id}: {e}", exc_info=True)

# --- Main Execution ---
def main():
    parser = argparse.ArgumentParser(description='Integrated Ad-Hoc Drone Discovery and Communication')
    parser.add_argument('--drone-id', required=True, help='Unique ID for this drone (e.g., drone_1)')
    parser.add_argument('--interface', default='wlo1', help='Wireless interface for ad-hoc mode (e.g., wlan0, wlo1)')
    parser.add_argument('--ssid', default='drone-swarm-net', help='Ad-hoc network SSID')
    args = parser.parse_args()

    controller = DroneController(args.drone_id, args.interface, args.ssid)
    
    try:
        controller.start()
        while True: time.sleep(1)
    except KeyboardInterrupt:
        logger.info("Shutdown initiated by user.")
    finally:
        controller.stop()

if __name__ == "__main__":
    main()