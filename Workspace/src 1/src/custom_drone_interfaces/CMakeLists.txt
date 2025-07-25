cmake_minimum_required(VERSION 3.5)
project(custom_drone_interfaces)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(action_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

set(msg_files
  "msg/MissionFeedback.msg"
  "msg/MissionGoal.msg"
  "msg/MissionResult.msg"
  "msg/MissionCommand.msg"
  "msg/AgentData.msg"
  "msg/AgentsList.msg"
  "msg/SensorDataCollection.msg"
  "msg/StatusDataCollection.msg"
  "msg/ObjectProximityData.msg"
  "msg/Waypoint.msg"
  "msg/SubWaypoint.msg"
  "msg/Path3D.msg"
  "msg/TaskSpecification.msg"
  "msg/SetPoint.msg"


)
set(srv_files
  "srv/ComputePath.srv"
)
set(action_files
  "action/MissionExecutor.action"
  "action/Tracker.action"
)

rosidl_generate_interfaces(${PROJECT_NAME}
  ${msg_files}
  ${srv_files}
  ${action_files}
  DEPENDENCIES std_msgs action_msgs geometry_msgs
)

ament_package()
