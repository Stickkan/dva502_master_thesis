import rclpy
from rclpy.node import Node
import json
import time
from std_msgs.msg import Header
from geometry_msgs.msg import Point, Vector3

# Local imports
from .trust_manager import TrustManager
from .discovery import Discovery
from .connection_manager import ConnectionManager
from custom_drone_interfaces.msg import drone_message.msg # Import the custom message

class AdhocNode(Node):
    """
    Main ROS2 node for ad-hoc drone communication.
    
    This node integrates all the components:
    - Discovery: Finds other drones.
    - TrustManager: Verifies discovered drones.
    - ConnectionManager: Manages network connections.
    
    It also publishes its own status and subscribes to topics for position, etc.
    (For this example, we will simulate status updates).
    """
    def __init__(self):
        super().__init__('adhoc_node')
        
        # Declare and get parameters
        self.declare_parameter('drone_id', 'drone_1') # Default ID
        self.drone_id = self.get_parameter('drone_id').get_parameter_value().string_value
        self.get_logger().info(f"Initializing node for drone: {self.drone_id}")
        
        # --- Internal State ---
        self.position = Point(x=1.0, y=2.0, z=3.0) # Simulated position
        self.velocity = Vector3(x=0.1, y=0.2, z=0.3) # Simulated velocity
        self.energy_level = 99.5
        self.package_number = 0

        # --- Initialize Modules ---
        self.trust_manager = TrustManager(self)
        self.connection_manager = ConnectionManager(self, self.drone_id, self.handle_received_message)
        self.discovery = Discovery(self, self.drone_id)
        
        # Set the callback for when a peer is discovered
        self.discovery.on_peer_discovered = self.handle_peer_discovered
        
        # --- Start Communication ---
        self.discovery.start()
        self.connection_manager.start()
        
        # --- ROS2 Publishers and Timers ---
        self.status_publisher = self.create_publisher(DronePacket, f'/{self.drone_id}/adhoc_status', 10)
        self.broadcast_timer = self.create_timer(5.0, self.broadcast_status) # Broadcast status every 5s

        self.get_logger().info("AdhocNode has been initialized successfully.")

    def handle_peer_discovered(self, peer_id, peer_ip):
        """
        Callback for the Discovery module.
        Handles logic for when a new peer is found on the network.
        """
        self.get_logger().info(f"Node handling discovered peer: {peer_id} at {peer_ip}")
        
        # 1. Check if the peer is trusted
        if self.trust_manager.is_trusted(peer_id):
            # 2. If trusted, attempt to connect
            # For now, we default to TCP. A more advanced logic could decide based on network conditions.
            self.connection_manager.connect_to_peer(peer_id, peer_ip, protocol="TCP")
        else:
            self.get_logger().warn(f"Ignoring untrusted peer {peer_id}.")

    def handle_received_message(self, message_dict):
        """
        Callback for the ConnectionManager.
        Processes messages received from other drones.
        """
        try:
            # For now, we just log the received message.
            # In a real application, you would process this data.
            sender_id = message_dict.get('drone_id', 'unknown')
            self.get_logger().info(f"Received message from {sender_id}: {message_dict}")
            
            # Here you could update a local model of the swarm state,
            # trigger responses, or forward the message if acting as a router.
            
        except Exception as e:
            self.get_logger().error(f"Error processing received message: {e}")

    def broadcast_status(self):
        """
        Periodically creates and broadcasts a DronePacket with the current status.
        """
        self.package_number += 1
        
        # Create the message payload
        message = {
            "drone_id": self.drone_id,
            "package_number": self.package_number,
            "checksum": 0, # Placeholder for checksum logic
            "position": {"x": self.position.x, "y": self.position.y, "z": self.position.z},
            "velocity": {"x": self.velocity.x, "y": self.velocity.y, "z": self.velocity.z},
            "energy_level": self.energy_level,
            "connected_drones": self.connection_manager.get_connected_peers(),
            "protocol": "STATUS_BROADCAST",
            "interface": "WIFI_5GHZ" # Simulated
        }
        
        # A simple checksum example (XORing bytes of the drone ID)
        checksum = 0
        for byte in self.drone_id.encode('utf-8'):
            checksum ^= byte
        message['checksum'] = checksum

        # Broadcast to all connected peers
        self.connection_manager.broadcast_message(message)
        
        # Also publish the status locally for other ROS nodes on this drone
        ros_msg = self._dict_to_ros_msg(message)
        self.status_publisher.publish(ros_msg)
        self.get_logger().info("Broadcasted status to connected peers.")

    def _dict_to_ros_msg(self, msg_dict):
        """Converts a Python dictionary to a DronePacket ROS message."""
        ros_msg = DronePacket()
        ros_msg.header = Header(stamp=self.get_clock().now().to_msg(), frame_id=self.drone_id)
        ros_msg.drone_id = msg_dict.get('drone_id', '')
        ros_msg.package_number = msg_dict.get('package_number', 0)
        ros_msg.checksum = msg_dict.get('checksum', 0)
        
        pos = msg_dict.get('position', {})
        ros_msg.position = Point(x=pos.get('x',0.0), y=pos.get('y',0.0), z=pos.get('z',0.0))
        
        vel = msg_dict.get('velocity', {})
        ros_msg.velocity = Vector3(x=vel.get('x',0.0), y=vel.get('y',0.0), z=vel.get('z',0.0))
        
        ros_msg.energy_level = msg_dict.get('energy_level', 0.0)
        ros_msg.connected_drones = msg_dict.get('connected_drones', [])
        ros_msg.protocol = msg_dict.get('protocol', '')
        ros_msg.interface = msg_dict.get('interface', '')
        return ros_msg

    def destroy_node(self):
        """Cleanly shuts down the node and its components."""
        self.get_logger().info("Shutting down AdhocNode...")
        self.discovery.stop()
        self.connection_manager.stop()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    adhoc_node = AdhocNode()
    try:
        rclpy.spin(adhoc_node)
    except KeyboardInterrupt:
        pass
    finally:
        adhoc_node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
