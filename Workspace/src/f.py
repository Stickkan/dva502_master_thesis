# enhanced_standalone_controller_hybrid.py

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

# --- Discovery Class ---
class Discovery:
    def __init__(self, drone_id, tcp_port, udp_port, discovery_port=19999):
        self._drone_id = drone_id
        self._port = discovery_port
        self._tcp_port = tcp_port
        self._udp_port = udp_port
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

    # In the Discovery class

    def setup_adhoc_network(self):
        """A more robust method to configure the ad-hoc network."""
        logger.info("Configuring ad-hoc network mode (robust sequence)...")
        iface = self.adhoc_config["interface"]
        ssid = self.adhoc_config["ssid"]

        commands = [
            ['sudo', 'nmcli', 'dev', 'disconnect', iface],
            ['sudo', 'nmcli', 'dev', 'set', iface, 'managed', 'no'],
            ['sudo', 'killall', 'wpa_supplicant'],
            ['sudo', 'ip', 'link', 'set', iface, 'down'],
            ['sudo', 'iwconfig', iface, 'mode', 'ad-hoc'],
            ['sudo', 'iwconfig', iface, 'essid', ssid],
            ['sudo', 'iwconfig', iface, 'channel', '6'],
            ['sudo', 'ip', 'link', 'set', iface, 'up'],
            # --- ADD THIS LINE ---
            # Disable power management to prevent the card from sleeping
            ['sudo', 'iwconfig', iface, 'power', 'off'],
            # --- END OF ADDITION ---
            ['sudo', 'ip', 'addr', 'flush', 'dev', iface],
        ]

        for cmd in commands:
            # Added a simple try-except block to handle the 'killall' case gracefully
            try:
                if not self._run_command(cmd):
                    # This is not a real error if the process wasn't running
                    if 'killall' in cmd[0] and 'no process found' in str(cmd):
                         continue
                    logger.error("A command failed during the robust setup sequence.")
            except Exception as e:
                 logger.error(f"An exception occurred running command {' '.join(cmd)}: {e}")
            time.sleep(0.5)

        logger.info(f"Ad-hoc network mode '{ssid}' configured on {iface}.")
        return True
    
    def _assign_ip_address(self):
        logger.info("Assigning IP address...")
        ip_address = f"{self.adhoc_config['ip_base']}{self.adhoc_config['self_ip_ending']}/24"
        iface = self.adhoc_config["interface"]
        if not self._run_command(['sudo', 'ip', 'addr', 'add', ip_address, 'dev', iface]):
            logger.error(f"Failed to assign IP address {ip_address} to {iface}.")
            return False
        logger.info(f"Successfully assigned IP {ip_address} to {iface}.")
        return True

    def teardown_adhoc_network(self):
        logger.info("Restoring original network state...")
        iface = self.adhoc_config["interface"]
        self._run_command(['sudo', 'ip', 'addr', 'flush', 'dev', iface])
        time.sleep(1)
        self._run_command(['sudo', 'nmcli', 'dev', 'set', iface, 'managed', 'yes'])
        time.sleep(4) 
        if self._original_connection:
            logger.info(f"Attempting to reconnect to '{self._original_connection}'...")
            self._run_command(['sudo', 'nmcli', 'con', 'up', 'id', self._original_connection])
        else:
            logger.warning("No known previous connection to restore.")

    def start_threads(self):
        logger.info(f"Starting discovery threads on port {self._port}...")
        self._running = True
        broadcast_thread = threading.Thread(target=self._broadcast_presence)
        listen_thread = threading.Thread(target=self._listen_for_peers)
        self._threads.extend([broadcast_thread, listen_thread])
        broadcast_thread.start()
        listen_thread.start()

    def stop_threads(self):
        if not self._running: return
        logger.info("Stopping discovery threads...")
        self._running = False
        try: 
            with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
                s.sendto(b'stop', ('127.0.0.1', self._port))
        except Exception: pass
            
        for thread in self._threads:
            thread.join(timeout=2.0)
        self._threads = []
        logger.info("Discovery threads stopped.")

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
        iface = self.adhoc_config["interface"]
        with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as sock:
            sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
            try:
                sock.setsockopt(socket.SOL_SOCKET, 25, iface.encode())
            except OSError: pass # Fails on non-Linux
            
            own_ip = f"{self.adhoc_config['ip_base']}{self.adhoc_config['self_ip_ending']}"
            try:
                sock.bind((own_ip, 0))
            except socket.error as e:
                logger.error(f"Discovery broadcast socket failed to bind to {own_ip}: {e}")
                return
            
            message_payload = {
                "id": self._drone_id,
                "ip": own_ip,
                "tcp_port": self._tcp_port,
                "udp_port": self._udp_port
            }
            message = json.dumps(message_payload)
            while self._running:
                try:
                    sock.sendto(message.encode(), (self._broadcast_ip, self._port))
                except Exception:
                    if self._running: logger.error(f"Broadcast error", exc_info=True)
                time.sleep(5)

    def _listen_for_peers(self):
        with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as sock:
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
                    if peer_id and message.get("ip") and peer_id != self._drone_id:
                        if self.on_peer_discovered:
                            self.on_peer_discovered(message)
                except socket.timeout:
                    continue
                except Exception:
                    if not self._running: break

# --- Connection Manager Class ---
class ConnectionManager:
    def __init__(self, drone_id, on_message_received_callback, tcp_port, udp_port, discovered_peers_ref):
        self._drone_id = drone_id
        self.on_message_received = on_message_received_callback
        self._tcp_port = tcp_port
        self._udp_port = udp_port
        self._discovered_peers = discovered_peers_ref
        self._running = True
        self._threads = []
        self._clients = {}
        self._peers = {}
        self.message_queue = deque()
        self._lock = threading.Lock()

    def start(self):
        logger.info(f"Starting connection manager for {self._drone_id}")
        self._running = True
        threads_to_start = [
            threading.Thread(target=self._tcp_server_loop),
            threading.Thread(target=self._udp_server_loop),
            threading.Thread(target=self._process_message_queue)
        ]
        for t in threads_to_start:
            t.start()
            self._threads.append(t)

    def stop(self):
        if not self._running: return
        logger.info("Stopping connection manager...")
        self._running = False
        with self._lock:
            for peer_id, client_socket in list(self._clients.items()):
                try: client_socket.close()
                except Exception: pass
        
        try:
            socket.create_connection(('127.0.0.1', self._tcp_port), timeout=0.5).close()
            with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
                s.sendto(b'stop', ('127.0.0.1', self._udp_port))
        except Exception: pass

        for thread in self._threads:
            thread.join(timeout=2.0)
        self._threads = []
        logger.info("Connection manager stopped.")
    
    def get_connected_peers(self):
        with self._lock:
            return list(self._clients.keys())
    
    def broadcast_message(self, message_dict):
        with self._lock:
            peers_to_broadcast = list(self._peers.items())
        if not peers_to_broadcast:
            logger.debug("Broadcast requested, but no peers are registered.")
            return
        logger.info(f"Broadcasting message to {len(peers_to_broadcast)} peers.")
        for peer_id, peer_info in peers_to_broadcast:
            self.send_message(peer_info, message_dict)

    def connect_to_peer(self, peer_info: dict, protocol="TCP"):
        peer_id = peer_info['id']
        with self._lock:
            if peer_id in self._clients:
                return
            logger.info(f"Attempting to connect to {peer_id} at {peer_info['ip']} via {protocol}...")
            iface = "wlo1"
            try:
                if protocol == "TCP":
                    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                    sock.setsockopt(socket.SOL_SOCKET, socket.SO_KEEPALIVE, 1)
                    try:
                        sock.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPIDLE, 5)
                        sock.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPINTVL, 3)
                        sock.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPCNT, 3)
                    except (AttributeError, OSError): pass
                    
                    try: sock.setsockopt(socket.SOL_SOCKET, 25, iface.encode())
                    except OSError: pass 
                    sock.settimeout(3.0)
                    sock.connect((peer_info['ip'], peer_info['tcp_port']))
                    
                    receive_thread = threading.Thread(target=self._handle_tcp_receive, args=(peer_id, sock))
                    receive_thread.daemon = True
                    receive_thread.start()
                    self._threads.append(receive_thread)
                else: 
                    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
                    try: sock.setsockopt(socket.SOL_SOCKET, 25, iface.encode())
                    except OSError: pass
                
                self._clients[peer_id] = sock
                self._peers[peer_id] = peer_info
                logger.info(f"Successfully connected to {peer_id} via {protocol}.")
            except Exception as e:
                logger.error(f"Failed to connect to {peer_id}: {e}")

    def disconnect_from_peer(self, peer_id):
        with self._lock:
            if peer_id in self._clients:
                logger.info(f"Disconnecting from peer {peer_id}.")
                try: self._clients[peer_id].close()
                except Exception: pass
                finally:
                    if peer_id in self._clients: del self._clients[peer_id]
                    if peer_id in self._peers: del self._peers[peer_id]

    def send_message(self, peer_info: dict, message_dict: dict):
        peer_id = peer_info['id']
        with self._lock:
            sock = self._clients.get(peer_id)
        if not sock:
            return
        try:
            protocol = "TCP" if sock.type == socket.SOCK_STREAM else "UDP"
            if 'drone_id' not in message_dict: message_dict['drone_id'] = self._drone_id
            message_json = json.dumps(message_dict)
            if protocol == "TCP":
                sock.sendall(message_json.encode('utf-8') + b'\n')
            else:
                sock.sendto(message_json.encode('utf-8'), (peer_info['ip'], peer_info['udp_port']))
        except Exception as e:
            logger.error(f"Error sending message to {peer_id}: {e}")
            self._handle_disconnection(peer_id)

    def _handle_disconnection(self, peer_id):
        logger.warning(f"Peer {peer_id} disconnected unexpectedly.")
        self.disconnect_from_peer(peer_id)

    def _tcp_server_loop(self):
        server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        try:
            server_socket.bind(('', self._tcp_port))
        except OSError as e:
            logger.error(f"TCP server bind failed on port {self._tcp_port}: {e}"); return
        server_socket.listen(5); server_socket.settimeout(1.0)
        logger.info(f"TCP server listening on port {self._tcp_port}")
        while self._running:
            try:
                client_socket, addr = server_socket.accept()
                logger.info(f"Accepted TCP connection from {addr}")
                client_socket.setsockopt(socket.SOL_SOCKET, socket.SO_KEEPALIVE, 1)
                try:
                    client_socket.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPIDLE, 5)
                    client_socket.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPINTVL, 3)
                    client_socket.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPCNT, 3)
                except (AttributeError, OSError): pass
                
                handler_thread = threading.Thread(target=self._handle_tcp_receive, args=(None, client_socket))
                handler_thread.daemon = True; handler_thread.start(); self._threads.append(handler_thread)
            except socket.timeout: continue
            except Exception as e:
                if self._running: logger.error(f"TCP Server error: {e}")
        server_socket.close()

    def _handle_tcp_receive(self, peer_id, client_socket):
        buffer = ""
        is_identified = peer_id is not None
        while self._running:
            try:
                data = client_socket.recv(4096)
                if not data: break
                buffer += data.decode('utf-8')
                while '\n' in buffer:
                    message_json, buffer = buffer.split('\n', 1)
                    if message_json:
                        message = json.loads(message_json)
                        if not is_identified:
                            with self._lock:
                                peer_id = message.get('drone_id')
                                if peer_id:
                                    self._clients[peer_id] = client_socket
                                    # Use the get method to avoid a KeyError if the peer disappears
                                    peer_full_info = self._discovered_peers.get(peer_id)
                                    if peer_full_info:
                                        self._peers[peer_id] = peer_full_info
                                        logger.info(f"Identified and registered incoming TCP peer {peer_id}")
                                    else:
                                        logger.warning(f"Incoming TCP peer {peer_id} not in discovered list.")
                                    is_identified = True
                        self.message_queue.append(message)
            except (ConnectionResetError, BrokenPipeError, OSError): break
            except Exception as e: logger.error(f"Error handling TCP client {peer_id}: {e}"); break
        if peer_id: self._handle_disconnection(peer_id)
        client_socket.close()

    def _udp_server_loop(self):
        server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        server_socket.bind(('', self._udp_port)); server_socket.settimeout(1.0)
        logger.info(f"UDP server listening on port {self._udp_port}")
        while self._running:
            try:
                data, addr = server_socket.recvfrom(4096)
                try:
                    message = json.loads(data.decode('utf-8'))
                    self.message_queue.append(message)
                except json.JSONDecodeError: logger.debug(f"Received non-JSON UDP data from {addr}, ignoring."); continue
            except socket.timeout: continue
            except Exception as e:
                if self._running: logger.error(f"UDP Server error: {e}")
        server_socket.close()
        
    def _process_message_queue(self):
        while self._running:
            try:
                message = self.message_queue.popleft()
                self.on_message_received(message)
            except IndexError: time.sleep(0.01)
            except Exception as e: logger.error(f"Error processing message queue: {e}")

# --- Main Controller Class ---
class DroneController:
    def __init__(self, drone_id, interface, ssid, tcp_port, udp_port, should_setup_net):
        self.drone_id = drone_id
        self.should_setup_net = should_setup_net
        self.discovered_peers = {}
        self.tested_peers = set()
        self._app_running = True
        self._app_threads = []
        self.PEER_TIMEOUT = 20

        self.discovery = Discovery(drone_id, tcp_port, udp_port)
        self.discovery.adhoc_config["interface"] = interface
        self.discovery.adhoc_config["ssid"] = ssid
        self.discovery.on_peer_discovered = self._handle_peer_discovery

        # Create a special dict view for the ConnectionManager to prevent thread-safety issues
        # with the more complex peer dictionary structure in this class.
        class PeerInfoView:
            def __init__(self, full_peer_dict, lock):
                self._source = full_peer_dict
                self._lock = lock
            def get(self, key):
                with self._lock:
                    peer_data = self._source.get(key)
                return peer_data['info'] if peer_data else None
            def __contains__(self, key):
                with self._lock:
                    return key in self._source

        # The connection manager's lock will be used to protect the shared discovered_peers dict
        self.connection_manager = ConnectionManager(
            self.drone_id, 
            self._handle_message_received, 
            tcp_port, 
            udp_port,
            PeerInfoView(self.discovered_peers, threading.Lock())
        )
    
    def start(self):
        logger.info(f"--- Starting Drone Controller for {self.drone_id} ---")
        
        logger.info("Step 1a: This instance is setting up the Ad-Hoc Network Mode...")
        if not self.discovery.setup_adhoc_network():
            logger.critical("Could not set up ad-hoc network. Aborting.")
            self.discovery.teardown_adhoc_network(); return False
        
        logger.info("Step 1b: Assigning self IP address to the interface...")
        if not self.discovery._assign_ip_address():
            logger.critical("Could not assign IP address. Aborting."); return False

        time.sleep(2)
        logger.info("Step 2: Starting Connection Manager..."); self.connection_manager.start()
        logger.info("Step 3: Starting Discovery Service..."); self.discovery.start_threads()
        
        logger.info("Step 4: Starting Application Logic Threads...")
        self._app_running = True
        prune_thread = threading.Thread(target=self._prune_peers_loop)
        recon_thread = threading.Thread(target=self._periodic_reconnection_check)
        status_thread = threading.Thread(target=self._periodic_status_broadcast)
        self._app_threads.extend([prune_thread, recon_thread, status_thread])
        for t in self._app_threads: t.start()

        logger.info("--- Controller is Running ---"); return True

    def stop(self):
        logger.info(f"--- Stopping Drone Controller for {self.drone_id} ---")
        
        logger.info("Step 1: Stopping Application Logic Threads...")
        self._app_running = False
        for thread in self._app_threads: thread.join(timeout=2.0)

        logger.info("Step 2: Stopping Discovery Service..."); self.discovery.stop_threads()
        logger.info("Step 3: Stopping Connection Manager..."); self.connection_manager.stop()

        if self.should_setup_net:
            logger.info("This drone was run with --setup-net, tearing down the network.")
            self.discovery.teardown_adhoc_network()
        elif not self.discovered_peers:
            logger.info("This drone is the last one in the swarm. Tearing down the network.")
            self.discovery.teardown_adhoc_network()
        else:
            logger.info(f"Leaving ad-hoc network running for {len(self.discovered_peers)} other peer(s).")

        logger.info("--- Controller Stopped ---")

    def _prune_peers_loop(self):
        while self._app_running:
            time.sleep(10)
            now = time.time()
            peers_to_prune = [pid for pid, data in list(self.discovered_peers.items()) if now - data['last_seen'] > self.PEER_TIMEOUT]
            
            for pid in peers_to_prune:
                logger.info(f"Peer {pid} timed out. Removing from discovered list.")
                with self.connection_manager._lock:
                    if pid in self.discovered_peers:
                        del self.discovered_peers[pid]
                self.connection_manager.disconnect_from_peer(pid)

    def _handle_peer_discovery(self, peer_info: dict):
        peer_id = peer_info['id']
        with self.connection_manager._lock:
            self.discovered_peers[peer_id] = {'info': peer_info, 'last_seen': time.time()}

        if peer_id not in self.tested_peers:
            self.tested_peers.add(peer_id)
            if self.drone_id > peer_id:
                logger.info(f"New peer '{peer_id}' discovered. My ID is greater, so I will initiate the connection.")
                sequence_thread = threading.Thread(target=self._run_comm_sequence, args=(peer_info,))
                sequence_thread.daemon = True; sequence_thread.start()
            else:
                logger.info(f"New peer '{peer_id}' discovered. My ID is smaller, so I will wait for their connection.")

    def _periodic_reconnection_check(self):
        while self._app_running:
            time.sleep(15)
            peers_to_check = list(self.discovered_peers.items())
            connected_peers = self.connection_manager.get_connected_peers()
            
            for peer_id, data in peers_to_check:
                if peer_id not in connected_peers:
                    if self.drone_id > peer_id:
                        logger.info(f"Discovered peer '{peer_id}' is not connected. Attempting TCP connection.")
                        self.connection_manager.connect_to_peer(data['info'], protocol="TCP")

    def _periodic_status_broadcast(self):
        package_number = 0
        while self._app_running:
            time.sleep(10)
            if not self._app_running: break
            package_number += 1
            status_message = {"protocol": "STATUS_BROADCAST", "package_number": package_number, "energy_level": 98.5, "position": {"x": 1.0, "y": 2.0, "z": 3.0}}
            self.connection_manager.broadcast_message(status_message)
            
    def _handle_message_received(self, message):
        sender = message.get('drone_id', 'Unknown')
        if sender == self.drone_id:
            logger.debug(f"Ignoring own message: {json.dumps(message)}")
            return
        protocol = message.get('protocol', 'N/A')
        logger.info(f"RECEIVED from {sender} via {protocol}: {json.dumps(message)}")

    def _run_comm_sequence(self, peer_info: dict):
        peer_id = peer_info['id']
        try:
            logger.info(f"[{peer_id}] === Starting UDP Test ===")
            self.connection_manager.connect_to_peer(peer_info, protocol="UDP"); time.sleep(1)
            for i in range(3):
                self.connection_manager.send_message(peer_info, {"protocol": "UDP_TEST", "count": i + 1}); time.sleep(0.5)
            self.connection_manager.disconnect_from_peer(peer_id); time.sleep(1)
            logger.info(f"[{peer_id}] === Starting TCP Test ===")
            self.connection_manager.connect_to_peer(peer_info, protocol="TCP"); time.sleep(1)
            for i in range(3):
                self.connection_manager.send_message(peer_info, {"protocol": "TCP_TEST", "count": i + 1}); time.sleep(0.5)
            logger.info(f"[{peer_id}] === Initial communication test finished. TCP connection will be maintained. ===")
        except Exception as e:
            logger.error(f"Error in communication sequence with {peer_id}: {e}", exc_info=True)

# --- Main Execution ---
def main():
    parser = argparse.ArgumentParser(description='Decentralized Standalone Ad-Hoc Drone Controller')
    parser.add_argument('--drone-id', required=True, help='Unique ID for this drone (e.g., drone_1)')
    parser.add_argument('--interface', default='wlo1', help='Wireless interface for ad-hoc mode (e.g., wlan0)')
    parser.add_argument('--ssid', default='drone-swarm-net', help='Ad-hoc network SSID')
    parser.add_argument('--tcp-port', type=int, required=True, help='TCP port for the connection manager')
    parser.add_argument('--udp-port', type=int, required=True, help='UDP port for the connection manager')
    parser.add_argument('--setup-net', action='store_true', help='Designate this drone as the master for network cleanup in local tests.')
    args = parser.parse_args()

    controller = DroneController(
        args.drone_id, 
        args.interface, 
        args.ssid, 
        args.tcp_port, 
        args.udp_port,
        args.setup_net
    )
    
    try:
        if controller.start():
            while True: time.sleep(1)
    except KeyboardInterrupt:
        logger.info("Shutdown initiated by user.")
    finally:
        controller.stop()

if __name__ == "__main__":
    main()