# Header
std_msgs/Header header

# Packet Info
uint32 package_number
float32 energy_expenditure
uint32 checksum

# State Info
geometry_msgs/Point position
geometry_msgs/Vector3 velocity

# Network Info
string[] connected_drones
builtin_interfaces/Time timestamp
