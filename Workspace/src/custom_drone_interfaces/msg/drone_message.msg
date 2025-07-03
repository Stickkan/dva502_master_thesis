# DronePacket.msg
# This message structure is used for all drone-to-drone communication.

# Standard ROS2 Header
# Contains timestamp and frame_id
std_msgs/Header header

# --- Packet Metadata ---
# Unique identifier for the sending drone
string drone_id

# Sequential number for this packet from the sender
uint64 package_number

# A simple checksum to verify data integrity (e.g., XOR of bytes)
uint32 checksum

# --- Drone State Information ---
# Current position of the drone
geometry_msgs/Point position

# Current velocity of the drone
geometry_msgs/Vector3 velocity

# --- Network & Status Information ---
# Estimated energy expenditure or remaining battery level
float32 energy_level

# List of drone IDs this drone is currently connected to
string[] connected_drones

# The communication protocol used to send this message (e.g., "TCP", "UDP")
string protocol

# The communication interface used (e.g., "WIFI_5GHZ", "BT")
string interface

