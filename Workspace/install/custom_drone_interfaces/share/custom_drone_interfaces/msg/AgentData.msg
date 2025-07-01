# AgentData.msg
# Represent one objects id, velocity and position meant for Traffic collision avoidance
# ID
uint32 agentid
#Priority
uint8 priority
# Velocity component
float32 vx
float32 vy
float32 vz
# Position Component
float64 lat
float64 lon
float32 alt
#Time component
uint64 time

