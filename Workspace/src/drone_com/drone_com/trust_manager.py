# adhoc_comms/trust_manager.py

import rclpy

class TrustManager:
    """
    Manages the list of trusted drone IDs.
    
    This class is responsible for verifying if a discovered drone is trusted
    before a connection is established. The list of trusted IDs is loaded
    from ROS2 parameters.
    """
    def __init__(self, node):
        """
        Initializes the TrustManager.
        
        Args:
            node: The parent ROS2 node, used for logging and getting parameters.
        """
        self._node = node
        self._trusted_ids = []
        self._load_trusted_ids()

    def _load_trusted_ids(self):
        """
        Loads the list of trusted drone IDs from a ROS2 parameter.
        
        The parameter 'trusted_drone_ids' should be a list of strings.
        """
        self._node.declare_parameter('trusted_drone_ids', ['drone_2', 'drone_3']) # Default values
        self._trusted_ids = self._node.get_parameter('trusted_drone_ids').get_parameter_value().string_array_value
        self._node.get_logger().info(f"Trusted drone IDs loaded: {self._trusted_ids}")

    def is_trusted(self, drone_id):
        """
        Checks if a given drone ID is in the trusted list.
        
        Args:
            drone_id (str): The ID of the drone to verify.
            
        Returns:
            bool: True if the drone is trusted, False otherwise.
        """
        if drone_id in self._trusted_ids:
            self._node.get_logger().info(f"Drone '{drone_id}' is trusted.")
            return True
        else:
            self._node.get_logger().warn(f"Drone '{drone_id}' is NOT trusted. Connection refused.")
            return False


