// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_drone_interfaces:msg/Waypoint.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__WAYPOINT__STRUCT_H_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__WAYPOINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'point'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'velocity'
#include "geometry_msgs/msg/detail/vector3__struct.h"
// Member 'subtrajectory'
#include "custom_drone_interfaces/msg/detail/sub_waypoint__struct.h"
// Member 'task'
#include "custom_drone_interfaces/msg/detail/task_specification__struct.h"
// Member 'commandid'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/Waypoint in the package custom_drone_interfaces.
/**
  * Waypoint.msg
 */
typedef struct custom_drone_interfaces__msg__Waypoint
{
  /// point to reach
  geometry_msgs__msg__Point point;
  /// Defines the final velocity at the point
  geometry_msgs__msg__Vector3 velocity;
  /// path to the waypoint
  custom_drone_interfaces__msg__SubWaypoint__Sequence subtrajectory;
  /// is the point a stopping location or not
  bool stop;
  /// Heading in radians
  double heading;
  /// Time in seconds to reach this waypoint
  double time_in_seconds;
  /// how long to stay at the point
  double hold_time;
  /// Accepted max distance from waypoint
  float acceptence_radius;
  /// What task to be performed. Check MMT definition
  custom_drone_interfaces__msg__TaskSpecification task;
  rosidl_runtime_c__int32__Sequence commandid;
} custom_drone_interfaces__msg__Waypoint;

// Struct for a sequence of custom_drone_interfaces__msg__Waypoint.
typedef struct custom_drone_interfaces__msg__Waypoint__Sequence
{
  custom_drone_interfaces__msg__Waypoint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_drone_interfaces__msg__Waypoint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__WAYPOINT__STRUCT_H_
