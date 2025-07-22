# adhoc_comms/discovery.py
#!/usr/bin/env python3

import socket
import threading
import json
import time
import rclpy

class Discovery:
    #* Handles the discovery of other drones on the network.
    
    #* This class uses UDP broadcasting to send out "hello" messages and listen for
    #* responses from other drones. This allows for a decentralized, ad-hoc discovery process.
    def __init__(self, node, drone_id, discovery_port=19999):
        
        #* Initializes the Discovery module.
        
        #* Args:
        #*    node: The parent ROS2 node.
        #*    drone_id (str): The unique ID of this drone.
        #*    discovery_port (int): The port to use for UDP broadcasting.
    
        self._node = node
        self._drone_id = drone_id
        self._port = discovery_port
        self._broadcast_ip = '255.255.255.255' # Broadcast to all devices on the network
        
        #* Callback to be set by the AdhocNode to handle newly discovered peers
        self.on_peer_discovered = None
        
        self._running = True
        
        #* Start broadcasting and listening in separate threads
        self._broadcast_thread = threading.Thread(target=self._broadcast_presence)
        self._listen_thread = threading.Thread(target=self._listen_for_peers)

    def start(self):
        #* Starts the discovery threads.
        self._node.get_logger().info(f"Starting discovery on port {self._port}...")
        self._broadcast_thread.start()
        self._listen_thread.start()

    def stop(self):
        #*Stops the discovery threads.
        self._running = False
        #* The sockets will timeout, and the threads will exit.
        self._broadcast_thread.join()
        self._listen_thread.join()
        self._node.get_logger().info("Discovery stopped.")

    def _broadcast_presence(self):
        #* Periodically broadcasts a "hello" message to the network.
        #* This message contains the drone's ID and its communication endpoints.
        
        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
        
        #* For simplicity, we assume the drone's IP is its communication endpoint.
        #* A more robust solution might involve discovering and broadcasting multiple IPs.
        hostname = socket.gethostname()
        ip_address = socket.gethostbyname(hostname)

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
            time.sleep(5) # Broadcast every 5 seconds

    def _listen_for_peers(self):
        
        #* Listens for "hello" messages from other drones.
        
        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        sock.bind(('', self._port))
        sock.settimeout(1.0) # Timeout to allow checking the self._running flag

        while self._running and rclpy.ok():
            try:
                data, addr = sock.recvfrom(1024)
                message = json.loads(data.decode('utf-8'))
                
                peer_id = message.get("id")
                peer_ip = message.get("ip")

                # Ignore our own broadcasts
                if peer_id == self._drone_id:
                    continue

                self._node.get_logger().info(f"Discovered peer '{peer_id}' at {peer_ip}")

                # If the callback is set, notify the main node
                if self.on_peer_discovered:
                    self.on_peer_discovered(peer_id, peer_ip)

            except socket.timeout:
                continue # Normal timeout, just loop again
            except Exception as e:
                self._node.get_logger().error(f"Error listening for peers: {e}")


