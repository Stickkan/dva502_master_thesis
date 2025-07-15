# adhoc_comms/discovery.py

import socket
import threading
import json
import time
import subprocess
import rclpy

class Discovery:
    """
    Handles the discovery of other drones on the network.
    
    This modified version includes logic to first establish a true Wi-Fi ad-hoc
    network if no existing network is available. It uses system commands
    to configure the wireless interface.
    
    NOTE: This requires the script to be run with sufficient permissions (e.g., sudo)
    to manage network interfaces. The commands are specific to Linux.
    """
    def __init__(self, node, drone_id, discovery_port=19999):
        """
        Initializes the Discovery module.
        """
        self._node = node
        self._drone_id = drone_id
        self._port = discovery_port
        self._broadcast_ip = '255.255.255.255'
        
        # --- Ad-Hoc Network Configuration ---
        self.adhoc_config = {
            "interface": "wlan0",       # The wireless interface to use
            "ssid": "drone-swarm-net",  # The name for the ad-hoc network
            "frequency": "2412",        # 2.4GHz, Channel 1
            "ip_base": "10.0.0.",       # Base for static IP addresses
            "self_ip_ending": self._get_ip_ending_from_id()
        }
        
        self.on_peer_discovered = None
        self._running = True
        
        self._broadcast_thread = threading.Thread(target=self._broadcast_presence)
        self._listen_thread = threading.Thread(target=self._listen_for_peers)

    def _get_ip_ending_from_id(self):
        """Creates a unique IP ending from the drone_id (e.g., 'drone_1' -> '1')."""
        try:
            return str(int(''.join(filter(str.isdigit, self._drone_id))))
        except (ValueError, IndexError):
            # Fallback for IDs without numbers, hash the ID to get a number
            return str(abs(hash(self._drone_id)) % 254 + 1)

    def _run_command(self, command):
        """Helper function to run a shell command and log its output."""
        self._node.get_logger().info(f"Running command: {' '.join(command)}")
        try:
            process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            stdout, stderr = process.communicate()
            if process.returncode != 0:
                self._node.get_logger().error(f"Command failed: {stderr.decode('utf-8').strip()}")
                return False
            self._node.get_logger().info(f"Command output: {stdout.decode('utf-8').strip()}")
            return True
        except Exception as e:
            self._node.get_logger().error(f"Exception running command: {e}")
            return False

    def _setup_adhoc_network(self):
        """Configures the wireless interface for ad-hoc (IBSS) mode."""
        self._node.get_logger().info("Attempting to configure ad-hoc network...")
        iface = self.adhoc_config["interface"]
        ssid = self.adhoc_config["ssid"]
        freq = self.adhoc_config["frequency"]
        ip_address = f"{self.adhoc_config['ip_base']}{self.adhoc_config['self_ip_ending']}/24"

        # Sequence of commands to set up an IBSS network on Linux
        commands = [
            ['ip', 'link', 'set', iface, 'down'],
            ['iw', 'dev', iface, 'set', 'type', 'ibss'],
            ['ip', 'link', 'set', iface, 'up'],
            ['iw', 'dev', iface, 'ibss', 'join', ssid, freq],
            # Wait a moment for the network to be joined before assigning an IP
            # In a real scenario, you would poll `iw dev wlan0 link` until it shows connected
            # For simplicity, we just sleep.
            # time.sleep(5), 
            ['ip', 'addr', 'add', ip_address, 'dev', iface]
        ]

        for cmd in commands:
            # A simple sleep command in the list
            if isinstance(cmd, float) or isinstance(cmd, int):
                time.sleep(cmd)
                continue
            
            if not self._run_command(cmd):
                self._node.get_logger().error("Failed to set up ad-hoc network. Discovery may not work.")
                return False
        
        self._node.get_logger().info(f"Ad-hoc network '{ssid}' should be configured on {iface} with IP {ip_address}.")
        return True

    def start(self):
        """Sets up the ad-hoc network and then starts discovery."""
        if not self._setup_adhoc_network():
            self._node.get_logger().warn("Could not set up ad-hoc network. Proceeding with existing network state.")
        
        # Give the network a moment to stabilize before starting broadcasts
        time.sleep(3)
        
        self._node.get_logger().info(f"Starting discovery on port {self._port}...")
        self._broadcast_thread.start()
        self._listen_thread.start()

    def stop(self):
        """Stops the discovery threads."""
        self._running = False
        self._broadcast_thread.join()
        self._listen_thread.join()
        self._node.get_logger().info("Discovery stopped.")
        # Optional: Add command to tear down the ad-hoc network
        # self._run_command(['ip', 'link', 'set', self.adhoc_config["interface"], 'down'])
        # self._run_command(['iw', 'dev', self.adhoc_config["interface"], 'set', 'type', 'managed'])


    def _broadcast_presence(self):
        """Periodically broadcasts a "hello" message to the network."""
        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
        
        # The IP address is now the static one we assigned
        ip_address = f"{self.adhoc_config['ip_base']}{self.adhoc_config['self_ip_ending']}"

        message = {
            "id": self._drone_id,
            "ip": ip_address
        }
        
        while self._running and rclpy.ok():
            try:
                sock.sendto(json.dumps(message).encode('utf-8'), (self._broadcast_ip, self._port))
                self._node.get_logger().debug(f"Broadcasted presence: {message}")
            except Exception as e:
                self._node.get_logger().error(f"Error broadcasting presence: {e}")
            time.sleep(5)

    def _listen_for_peers(self):
        """Listens for "hello" messages from other drones."""
        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        # Allow multiple instances on the same machine to listen on the same port
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        sock.bind(('', self._port))
        sock.settimeout(1.0)

        while self._running and rclpy.ok():
            try:
                data, addr = sock.recvfrom(1024)
                message = json.loads(data.decode('utf-8'))
                
                peer_id = message.get("id")
                peer_ip = message.get("ip")

                if peer_id == self._drone_id:
                    continue

                self._node.get_logger().info(f"Discovered peer '{peer_id}' at {peer_ip}")

                if self.on_peer_discovered:
                    self.on_peer_discovered(peer_id, peer_ip)

            except socket.timeout:
                continue
            except Exception as e:
                self._node.get_logger().error(f"Error listening for peers: {e}")
