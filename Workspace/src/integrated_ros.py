# adhoc_ros_node.py

import rclpy
from rclpy.node import Node
import socket
import threading
import json
import time
import subprocess
import logging as py_logging # Use a different name to avoid conflict with ROS logger
import argparse
from collections import deque

# ROS2 Message Imports
from std_msgs.msg import Header
from geometry_msgs.msg import Point, Vector3
# Assuming your custom message is in a package named 'custom_drone_interfaces'
# Corrected the import path from the prompt
from custom_drone_interfaces.msg import DronePacket 

# --- Global Configuration ---
# We will use the ROS logger, but keep the standard logging format for subprocesses
py_logging.basicConfig(level=py_logging.INFO, format='%(asctime)s - %(name)s - %(levelname)s - %(message)s')
py_logger = py_logging.getLogger("SubprocessRunner")

# --- Discovery Class (Adapted for ROS2) ---
class Discovery:
    def __init__(self, node: Node, drone_id: str, interface: str, ssid: str, discovery_port=19999):
        self._node = node
        self._drone_id = drone_id
        self._port = discovery_port
        self.on_peer_discovered = None
        self._running = True
        
        self.adhoc_config = {
            "interface": interface,
            "ssid": ssid,
            "ip_base": "192.168.1.",
            "self_ip_ending": self._get_ip_ending_from_id()
        }
        self._original_connection = self._get_active_connection()
        self._broadcast_ip = f"{self.adhoc_config['ip_base']}255"
        self._threads = []
        
    def _get_logger(self):
        return self._node.get_logger()

    def _get_ip_ending_from_id(self):
        try:
            return str(int(''.join(filter(str.isdigit, self._drone_id))))
        except (ValueError, IndexError):
            return str(abs(hash(self._drone_id)) % 254 + 1)

    def _run_command(self, command):
        py_logger.info(f"Running command: {' '.join(command)}")
        try:
            process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            stdout, stderr = process.communicate()
            if process.returncode != 0:
                py_logger.error(f"Command failed: {stderr.decode().strip()}")
                return False
            return True
        except Exception as e:
            py_logger.error(f"Exception running command: {e}")
            return False

    def setup_adhoc_network(self):
        """Synchronously sets up the ad-hoc network. Returns True on success."""
        self._get_logger().info("Configuring ad-hoc network...")
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
                self._get_logger().error("Failed to set up ad-hoc network.")
                return False
        
        self._get_logger().info(f"Ad-hoc network '{ssid}' configured on {iface} with IP {ip_address}.")
        return True

    def teardown_adhoc_network(self):
        """Restores the original network configuration."""
        self._get_logger().info("Restoring original network state...")
        iface = self.adhoc_config["interface"]
        self._run_command(['sudo', 'ip', 'addr', 'flush', 'dev', iface])
        time.sleep(1) # Short pause
        self._run_command(['sudo', 'nmcli', 'dev', 'set', iface, 'managed', 'yes'])
        time.sleep(4) # Wait for network manager to re-assert control
        if self._original_connection:
            self._get_logger().info(f"Attempting to reconnect to '{self._original_connection}'...")
            self._run_command(['sudo', 'nmcli', 'con', 'up', 'id', self._original_connection])
        else:
            self._get_logger().warn("No known previous connection to restore.")

    def start_threads(self):
        """Starts the broadcast and listen threads."""
        self._get_logger().info(f"Starting discovery threads on port {self._port}...")
        self._running = True
        broadcast_thread = threading.Thread(target=self._broadcast_presence)
        listen_thread = threading.Thread(target=self._listen_for_peers)
        self._threads.extend([broadcast_thread, listen_thread])
        broadcast_thread.start()
        listen_thread.start()

    def stop_threads(self):
        """Stops the broadcast and listen threads."""
        if not self._threads: return
        self._get_logger().info("Stopping discovery threads...")
        self._running = False
        # Create a socket to unblock the listener
        try:
            unblock_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
            unblock_socket.sendto(b'stop', ('127.0.0.1', self._port))
            unblock_socket.close()
        except Exception as e:
            self._get_logger().warn(f"Could not send unblock packet to listener: {e}")
            
        for thread in self._threads:
            thread.join(timeout=2.0)
        self._threads = []
        self._get_logger().info("Discovery threads stopped.")

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
        own_ip = f"{self.adhoc_config['ip_base']}{self.adhoc_config['self_ip_ending']}"
        try:
             sock.bind((own_ip, 0))
        except socket.error as e:
            self._get_logger().error(f"Discovery broadcast socket failed to bind to {own_ip}: {e}")
            return
            
        message = json.dumps({"id": self._drone_id, "ip": own_ip})
        while self._running:
            try:
                sock.sendto(message.encode(), (self._broadcast_ip, self._port))
            except Exception as e:
                self._get_logger().error(f"Broadcast error: {e}")
            time.sleep(5)
        sock.close()

    def _listen_for_peers(self):
        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        try:
            sock.bind(('', self._port))
        except socket.error as e:
            self._get_logger().error(f"Discovery listener socket bind failed on port {self._port}: {e}")
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
            except Exception:
                if not self._running: break
        sock.close()


# --- Connection Manager Class (Adapted for ROS2) ---
class ConnectionManager:
    """Manages all network connections (TCP and UDP)."""
    def __init__(self, node: Node, drone_id: str, on_message_received_callback):
        self._node = node
        self._drone_id = drone_id
        self.on_message_received = on_message_received_callback
        
        self._tcp_port = 20000
        self._udp_port = 20001
        
        self._running = True
        self._threads = []
        self._clients = {} # {drone_id: socket}
        self._peers = {} # {drone_id: {"ip": str, "protocol": str}}
        self.message_queue = deque()

    def _get_logger(self):
        return self._node.get_logger()

    def start(self):
        """Starts the server and message processing threads."""
        self._get_logger().info(f"Starting connection manager for {self._drone_id}")
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
        """Stops all connections and threads."""
        if not self._threads: return
        self._get_logger().info("Stopping connection manager...")
        self._running = False
        for peer_id, client_socket in list(self._clients.items()):
            try: client_socket.close()
            except Exception: pass
        
        # Unblock server loops
        try:
            socket.socket(socket.AF_INET, socket.SOCK_STREAM).connect(('127.0.0.1', self._tcp_port))
            socket.socket(socket.AF_INET, socket.SOCK_DGRAM).sendto(b'stop', ('127.0.0.1', self._udp_port))
        except Exception: pass

        for thread in self._threads:
            thread.join(timeout=2.0)
        self._threads = []
        self._get_logger().info("Connection manager stopped.")
    
    def get_connected_peers(self):
        """Returns a list of IDs of currently connected peers."""
        return list(self._clients.keys())

    def connect_to_peer(self, peer_id, peer_ip, protocol="TCP"):
        if peer_id in self._clients:
            self._get_logger().debug(f"Already connected to {peer_id}.")
            return
        self._get_logger().info(f"Attempting to connect to {peer_id} at {peer_ip} via {protocol}...")
        try:
            if protocol == "TCP":
                sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                sock.settimeout(3.0)
                sock.connect((peer_ip, self._tcp_port))
            else: # UDP
                sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
            self._clients[peer_id] = sock
            self._peers[peer_id] = {"ip": peer_ip, "protocol": protocol}
            self._get_logger().info(f"Successfully connected to {peer_id} via {protocol}.")
        except Exception as e:
            self._get_logger().error(f"Failed to connect to {peer_id}: {e}")

    def disconnect_from_peer(self, peer_id):
        if peer_id in self._clients:
            self._get_logger().info(f"Disconnecting from peer {peer_id}.")
            try: self._clients[peer_id].close()
            except Exception: pass
            finally:
                del self._clients[peer_id]
                if peer_id in self._peers: del self._peers[peer_id]

    def send_message(self, peer_id, message_dict):
        if peer_id not in self._clients:
            self._get_logger().warn(f"Not connected to {peer_id}. Cannot send message.")
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
        except Exception as e:
            self._get_logger().error(f"Error sending message to {peer_id}: {e}")
            self._handle_disconnection(peer_id)

    def broadcast_message(self, message_dict):
        """Sends a message to all currently connected peers."""
        if not self._clients:
            self._get_logger().info("Broadcast requested, but no peers are connected.")
            return
        
        self._get_logger().info(f"Broadcasting message to {len(self._clients)} peers.")
        # Create a copy of the peer list to iterate over, in case of disconnections
        for peer_id in list(self._clients.keys()):
            self.send_message(peer_id, message_dict)
    
    def _handle_disconnection(self, peer_id):
        self._get_logger().warn(f"Peer {peer_id} disconnected unexpectedly.")
        self.disconnect_from_peer(peer_id)

    # --- Server and Queue Logic (Unchanged from original, uses self._get_logger()) ---
    def _tcp_server_loop(self):
        server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        try:
            server_socket.bind(('', self._tcp_port))
        except OSError as e:
            self._get_logger().error(f"TCP server bind failed on port {self._tcp_port}: {e}")
            return
        server_socket.listen(5)
        server_socket.settimeout(1.0)
        self._get_logger().info(f"TCP server listening on port {self._tcp_port}")
        while self._running:
            try:
                client_socket, addr = server_socket.accept()
                self._get_logger().info(f"Accepted TCP connection from {addr}")
                handler_thread = threading.Thread(target=self._handle_tcp_client, args=(client_socket,))
                handler_thread.daemon = True
                handler_thread.start()
            except socket.timeout: continue
            except Exception as e:
                if self._running: self._get_logger().error(f"TCP Server error: {e}")
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
                                self._get_logger().info(f"Identified incoming TCP peer as {peer_id}")
                        self.message_queue.append(message)
            except (ConnectionResetError, BrokenPipeError):
                break # Normal disconnection
            except Exception as e:
                self._get_logger().error(f"Error handling TCP client {peer_id or addr}: {e}")
                break
        if peer_id: self._handle_disconnection(peer_id)
        client_socket.close()

    def _udp_server_loop(self):
        server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        server_socket.bind(('', self._udp_port))
        server_socket.settimeout(1.0)
        self._get_logger().info(f"UDP server listening on port {self._udp_port}")
        while self._running:
            try:
                data, addr = server_socket.recvfrom(4096)
                message = json.loads(data.decode('utf-8'))
                self.message_queue.append(message)
            except socket.timeout: continue
            except Exception as e:
                if self._running: self._get_logger().error(f"UDP Server error: {e}")
        server_socket.close()
        
    def _process_message_queue(self):
        while self._running:
            try:
                message = self.message_queue.popleft()
                self.on_message_received(message)
            except IndexError:
                time.sleep(0.01)
            except Exception as e:
                self._get_logger().error(f"Error processing message queue: {e}")


# --- Main ROS2 Node Class ---
class AdhocNode(Node):
    """
    Main ROS2 node for ad-hoc drone communication. Integrates network setup,
    discovery, connection management, and application logic.
    """
    def __init__(self):
        super().__init__('adhoc_node')
        
        # --- Declare and get parameters ---
        self.declare_parameter('drone_id', 'drone_default')
        self.declare_parameter('interface', 'wlo1')
        self.declare_parameter('ssid', 'drone-swarm-net')
        self.drone_id = self.get_parameter('drone_id').get_parameter_value().string_value
        interface = self.get_parameter('interface').get_parameter_value().string_value
        ssid = self.get_parameter('ssid').get_parameter_value().string_value
        self.get_logger().info(f"--- Initializing AdHoc Node for {self.drone_id} on {interface} ---")
        
        # --- Internal State ---
        self.position = Point(x=1.0, y=2.0, z=3.0) # Simulated position
        self.velocity = Vector3(x=0.1, y=0.2, z=0.3) # Simulated velocity
        self.energy_level = 99.5
        self.package_number = 0
        self.discovered_peers = {}  # {peer_id: peer_ip} - Ground truth from discovery
        self.tested_peers = set()   # Peers that have completed the initial comms test

        # --- Initialize Modules ---
        # NOTE: The order is critical for startup and shutdown.
        self.discovery = Discovery(self, self.drone_id, interface, ssid)
        self.connection_manager = ConnectionManager(self, self.drone_id, self.handle_received_message)
        
        # --- CRITICAL STARTUP SEQUENCE ---
        self.get_logger().info("Step 1: Setting up Ad-Hoc Network...")
        if not self.discovery.setup_adhoc_network():
            self.get_logger().fatal("Could not set up ad-hoc network. Aborting initialization.")
            # In a real scenario, you might want to destroy the node or enter a safe mode
            # For this example, we'll stop further initialization.
            return
        
        # Give the network time to stabilize before starting services
        time.sleep(3) 

        self.get_logger().info("Step 2: Starting Connection Manager services (TCP/UDP listeners)...")
        self.connection_manager.start()

        self.get_logger().info("Step 3: Starting Discovery service (broadcast/listen)...")
        self.discovery.on_peer_discovered = self.handle_peer_discovered
        self.discovery.start_threads()
        
        # --- ROS2 Publishers and Timers ---
        self.status_publisher = self.create_publisher(DronePacket, f'/{self.drone_id}/adhoc_status', 10)
        self.status_broadcast_timer = self.create_timer(10.0, self.broadcast_status)
        self.reconnection_timer = self.create_timer(15.0, self._check_reconnections) # Timer to ensure connectivity

        self.get_logger().info("--- AdhocNode Initialized and Running ---")

    def destroy_node(self):
        """Cleanly shuts down the node and its components in the correct order."""
        self.get_logger().info("--- Shutting down AdhocNode ---")
        if hasattr(self, 'status_broadcast_timer'): self.status_broadcast_timer.cancel()
        if hasattr(self, 'reconnection_timer'): self.reconnection_timer.cancel()
        
        # Order is reverse of startup
        self.get_logger().info("Step 1: Stopping Discovery service...")
        if hasattr(self, 'discovery'): self.discovery.stop_threads()
        
        self.get_logger().info("Step 2: Stopping Connection Manager...")
        if hasattr(self, 'connection_manager'): self.connection_manager.stop()

        self.get_logger().info("Step 3: Tearing down Ad-Hoc Network...")
        if hasattr(self, 'discovery'): self.discovery.teardown_adhoc_network()

        super().destroy_node()
        self.get_logger().info("--- AdhocNode Shutdown Complete ---")

    def handle_peer_discovered(self, peer_id: str, peer_ip: str):
        """Callback for the Discovery module. Stores peer info and runs initial test."""
        # Update our ground truth of who is on the network
        self.discovered_peers[peer_id] = peer_ip
        
        # Run the initial communication test sequence only once per peer
        if peer_id not in self.tested_peers:
            self.get_logger().info(f"New peer '{peer_id}' discovered at {peer_ip}. Starting one-time communication test.")
            self.tested_peers.add(peer_id)
            # Run in a separate thread to avoid blocking the discovery listener
            sequence_thread = threading.Thread(target=self._run_comm_sequence, args=(peer_id, peer_ip))
            sequence_thread.daemon = True
            sequence_thread.start()

    def _check_reconnections(self):
        """
        Periodically checks for discovered peers that we are not connected to
        and attempts to establish a connection. This ensures robust connectivity.
        """
        self.get_logger().info("Running periodic reconnection check...")
        connected_peers = self.connection_manager.get_connected_peers()
        for peer_id, peer_ip in self.discovered_peers.items():
            if peer_id not in connected_peers:
                self.get_logger().info(f"Discovered peer '{peer_id}' is not connected. Attempting to reconnect via TCP.")
                # Default to TCP for reliable status messages.
                self.connection_manager.connect_to_peer(peer_id, peer_ip, protocol="TCP")


    def handle_received_message(self, message_dict: dict):
        """Callback for the ConnectionManager. Processes all incoming messages."""
        try:
            sender_id = message_dict.get('drone_id', 'unknown')
            self.get_logger().info(f"Received message from {sender_id}: {json.dumps(message_dict)}")
            # Here you would add logic to react to different message types
            
        except Exception as e:
            self.get_logger().error(f"Error processing received message: {e}")

    def broadcast_status(self):
        """Periodically creates and broadcasts a DronePacket with the current status."""
        self.package_number += 1
        
        message = {
            "drone_id": self.drone_id,
            "package_number": self.package_number,
            "position": {"x": self.position.x, "y": self.position.y, "z": self.position.z},
            "velocity": {"x": self.velocity.x, "y": self.velocity.y, "z": self.velocity.z},
            "energy_level": self.energy_level,
            "connected_drones": self.connection_manager.get_connected_peers(),
            "protocol": "STATUS_BROADCAST",
        }
        
        # Broadcast to all connected peers over the ad-hoc network
        self.connection_manager.broadcast_message(message)
        
        # Also publish the status locally for other ROS nodes on this drone
        ros_msg = self._dict_to_ros_msg(message)
        self.status_publisher.publish(ros_msg)
        self.get_logger().info("Broadcasted status to connected peers and local ROS topic.")

    def _dict_to_ros_msg(self, msg_dict: dict) -> DronePacket:
        """Converts a Python dictionary to a DronePacket ROS message."""
        ros_msg = DronePacket()
        ros_msg.header = Header(stamp=self.get_clock().now().to_msg(), frame_id=self.drone_id)
        ros_msg.drone_id = msg_dict.get('drone_id', '')
        ros_msg.package_number = msg_dict.get('package_number', 0)
        
        pos = msg_dict.get('position', {})
        ros_msg.position = Point(x=pos.get('x',0.0), y=pos.get('y',0.0), z=pos.get('z',0.0))
        
        vel = msg_dict.get('velocity', {})
        ros_msg.velocity = Vector3(x=vel.get('x',0.0), y=vel.get('y',0.0), z=vel.get('z',0.0))
        
        ros_msg.energy_level = msg_dict.get('energy_level', 0.0)
        ros_msg.connected_drones = msg_dict.get('connected_drones', [])
        ros_msg.protocol = msg_dict.get('protocol', '')
        return ros_msg

    def _run_comm_sequence(self, peer_id: str, peer_ip: str):
        """Runs the initial UDP and TCP communication test from the original script."""
        try:
            self.get_logger().info(f"[{peer_id}] === Starting UDP Test ===")
            self.connection_manager.connect_to_peer(peer_id, peer_ip, protocol="UDP")
            time.sleep(1)
            for i in range(3):
                self.connection_manager.send_message(peer_id, {"protocol": "UDP_TEST", "count": i + 1})
                time.sleep(0.5)
            self.connection_manager.disconnect_from_peer(peer_id)
            time.sleep(1)

            self.get_logger().info(f"[{peer_id}] === Starting TCP Test ===")
            self.connection_manager.connect_to_peer(peer_id, peer_ip, protocol="TCP")
            time.sleep(1)
            for i in range(3):
                self.connection_manager.send_message(peer_id, {"protocol": "TCP_TEST", "count": i + 1})
                time.sleep(0.5)
            # We can leave the TCP connection open for the reconnection logic to manage
            
            self.get_logger().info(f"[{peer_id}] === Initial communication test finished. ===")
        except Exception as e:
            self.get_logger().error(f"Error in communication sequence with {peer_id}: {e}", exc_info=True)


def main(args=None):
    rclpy.init(args=args)
    adhoc_node = AdhocNode()
    try:
        # Check if initialization failed (e.g., ad-hoc network setup)
        if hasattr(adhoc_node, 'discovery') and adhoc_node.discovery._running:
             rclpy.spin(adhoc_node)
        else:
            adhoc_node.get_logger().fatal("Node initialization failed. Shutting down.")
    except KeyboardInterrupt:
        adhoc_node.get_logger().info("Shutdown initiated by user (KeyboardInterrupt).")
    finally:
        adhoc_node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()