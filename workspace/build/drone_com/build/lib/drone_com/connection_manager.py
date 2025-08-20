# adhoc_comms/connection_manager.py

import socket
import threading
import json
import time
from collections import deque

class ConnectionManager:
    """
    Manages all network connections (TCP and UDP).
    
    This class is responsible for:
    - Acting as a server to accept incoming connections.
    - Acting as a client to connect to discovered peers.
    - Handling data transmission and reception.
    - Providing a modular way to switch between protocols.
    """
    def __init__(self, node, drone_id, on_message_received_callback):
        """
        Initializes the ConnectionManager.
        
        Args:
            node: The parent ROS2 node.
            drone_id (str): The unique ID of this drone.
            on_message_received_callback: Function to call when a message is received.
        """
        self._node = node
        self._drone_id = drone_id
        self.on_message_received = on_message_received_callback
        
        self._hostname = socket.gethostname()
        self._ip = socket.gethostbyname(self._hostname)
        self._tcp_port = 20000
        self._udp_port = 20001
        
        self._running = True
        self._threads = []
        self._clients = {} # {drone_id: socket}
        self._peers = {} # {drone_id: {"ip": str, "protocol": str}}
        self.message_queue = deque()

    def start(self):
        """Starts the server threads for TCP and UDP."""
        self._node.get_logger().info(f"Starting connection manager for {self._drone_id} at {self._ip}")
        
        # Start TCP server thread
        tcp_thread = threading.Thread(target=self._tcp_server_loop)
        tcp_thread.start()
        self._threads.append(tcp_thread)
        
        # Start UDP server thread
        udp_thread = threading.Thread(target=self._udp_server_loop)
        udp_thread.start()
        self._threads.append(udp_thread)
        
        # Start message processing thread
        process_thread = threading.Thread(target=self._process_message_queue)
        process_thread.start()
        self._threads.append(process_thread)


    def stop(self):
        """Stops all connections and threads."""
        self._running = False
        for drone_id, client_socket in self._clients.items():
            try:
                client_socket.close()
            except Exception as e:
                self._node.get_logger().error(f"Error closing client socket for {drone_id}: {e}")
        
        for thread in self._threads:
            thread.join()
        self._node.get_logger().info("Connection manager stopped.")

    def get_connected_peers(self):
        """Returns a list of IDs of connected drones."""
        return list(self._clients.keys())

    def connect_to_peer(self, peer_id, peer_ip, protocol="TCP"):
        """
        Establishes a client connection to a peer.
        
        Args:
            peer_id (str): The ID of the peer to connect to.
            peer_ip (str): The IP address of the peer.
            protocol (str): "TCP" or "UDP".
        """
        if peer_id in self._clients:
            self._node.get_logger().info(f"Already connected to {peer_id}.")
            return

        self._node.get_logger().info(f"Attempting to connect to {peer_id} at {peer_ip} via {protocol}...")
        
        try:
            if protocol == "TCP":
                sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                sock.connect((peer_ip, self._tcp_port))
            else: # UDP
                # For UDP, "connecting" is just about setting a default destination
                sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
                sock.connect((peer_ip, self._udp_port))

            self._clients[peer_id] = sock
            self._peers[peer_id] = {"ip": peer_ip, "protocol": protocol}
            self._node.get_logger().info(f"Successfully connected to {peer_id} via {protocol}.")

        except Exception as e:
            self._node.get_logger().error(f"Failed to connect to {peer_id}: {e}")

    def send_message(self, peer_id, message_dict):
        """
        Sends a JSON message to a specific peer.
        
        Args:
            peer_id (str): The ID of the recipient drone.
            message_dict (dict): The message to send.
        """
        if peer_id not in self._clients:
            self._node.get_logger().warn(f"Not connected to {peer_id}. Cannot send message.")
            return

        try:
            sock = self._clients[peer_id]
            protocol = self._peers[peer_id]['protocol']
            message_json = json.dumps(message_dict)
            
            if protocol == "TCP":
                # Add a delimiter for stream-based protocol
                sock.sendall(message_json.encode('utf-8') + b'\n')
            else: # UDP
                sock.send(message_json.encode('utf-8'))
                
            self._node.get_logger().debug(f"Sent message to {peer_id}: {message_json}")
        except Exception as e:
            self._node.get_logger().error(f"Error sending message to {peer_id}: {e}")
            # Handle connection loss
            self._handle_disconnection(peer_id)
            
    def broadcast_message(self, message_dict):
        """Sends a message to all connected peers."""
        for peer_id in list(self._clients.keys()):
            self.send_message(peer_id, message_dict)

    def _handle_disconnection(self, peer_id):
        """Cleans up after a peer disconnects."""
        self._node.get_logger().warn(f"Peer {peer_id} disconnected.")
        if peer_id in self._clients:
            self._clients[peer_id].close()
            del self._clients[peer_id]
        if peer_id in self._peers:
            del self._peers[peer_id]

    def _tcp_server_loop(self):
        """Listens for and handles incoming TCP connections."""
        server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        server_socket.bind(('', self._tcp_port))
        server_socket.listen(5)
        server_socket.settimeout(1.0)
        self._node.get_logger().info(f"TCP server listening on port {self._tcp_port}")

        while self._running:
            try:
                client_socket, addr = server_socket.accept()
                self._node.get_logger().info(f"Accepted TCP connection from {addr}")
                # We don't know the drone_id yet, so we start a handler thread
                # to wait for the first message which should contain the ID.
                handler_thread = threading.Thread(target=self._handle_tcp_client, args=(client_socket,))
                handler_thread.start()
                self._threads.append(handler_thread)
            except socket.timeout:
                continue
            except Exception as e:
                if self._running:
                    self._node.get_logger().error(f"TCP Server error: {e}")
        server_socket.close()

    def _handle_tcp_client(self, client_socket):
        """Handles an individual TCP client connection."""
        buffer = ""
        peer_id = None
        while self._running:
            try:
                data = client_socket.recv(4096)
                if not data:
                    break # Connection closed by peer
                
                buffer += data.decode('utf-8')
                
                # Process all complete JSON objects in the buffer
                while '\n' in buffer:
                    message_json, buffer = buffer.split('\n', 1)
                    if message_json:
                        message = json.loads(message_json)
                        # The first message identifies the peer
                        if peer_id is None:
                            peer_id = message.get('drone_id')
                            if peer_id:
                                self._clients[peer_id] = client_socket
                                self._peers[peer_id] = {"ip": client_socket.getpeername()[0], "protocol": "TCP"}
                                self._node.get_logger().info(f"Identified TCP peer as {peer_id}")
                        
                        self.message_queue.append(message)

            except Exception as e:
                self._node.get_logger().error(f"Error handling TCP client {peer_id}: {e}")
                break
        
        if peer_id:
            self._handle_disconnection(peer_id)
        client_socket.close()


    def _udp_server_loop(self):
        """Listens for and handles incoming UDP packets."""
        server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        server_socket.bind(('', self._udp_port))
        server_socket.settimeout(1.0)
        self._node.get_logger().info(f"UDP server listening on port {self._udp_port}")

        while self._running:
            try:
                data, addr = server_socket.recvfrom(4096)
                message = json.loads(data.decode('utf-8'))
                self.message_queue.append(message)
            except socket.timeout:
                continue
            except Exception as e:
                if self._running:
                    self._node.get_logger().error(f"UDP Server error: {e}")
        server_socket.close()
        
    def _process_message_queue(self):
        """Processes received messages from the queue in a separate thread."""
        while self._running:
            try:
                message = self.message_queue.popleft()
                self.on_message_received(message)
            except IndexError:
                time.sleep(0.01) # Queue is empty, wait a bit
            except Exception as e:
                self._node.get_logger().error(f"Error processing message queue: {e}")


