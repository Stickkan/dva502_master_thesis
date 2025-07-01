// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_drone_interfaces:msg/SubWaypoint.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__SUB_WAYPOINT__STRUCT_H_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__SUB_WAYPOINT__STRUCT_H_

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
// Member 'acceleration'
#include "geometry_msgs/msg/detail/vector3__struct.h"

/// Struct defined in msg/SubWaypoint in the package custom_drone_interfaces.
/**
  * SubWaypoint.msg
 */
typedef struct custom_drone_interfaces__msg__SubWaypoint
{
  /// Point to reach
  geometry_msgs__msg__Point point;
  /// Defines the final velocity at the point
  geometry_msgs__msg__Vector3 velocity;
  /// Acceleration sample
  geometry_msgs__msg__Vector3 acceleration;
  /// Heading in radians
  double heading;
  /// Time sample
  double time_sec;
} custom_drone_interfaces__msg__SubWaypoint;

// Struct for a sequence of custom_drone_interfaces__msg__SubWaypoint.
typedef struct custom_drone_interfaces__msg__SubWaypoint__Sequence
{
  custom_drone_interfaces__msg__SubWaypoint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_drone_interfaces__msg__SubWaypoint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__SUB_WAYPOINT__STRUCT_H_
