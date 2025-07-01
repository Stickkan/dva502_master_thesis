// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_drone_interfaces:msg/Path3D.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__PATH3_D__STRUCT_H_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__PATH3_D__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'waypoints'
#include "custom_drone_interfaces/msg/detail/waypoint__struct.h"

/// Struct defined in msg/Path3D in the package custom_drone_interfaces.
/**
  * an array of waypoints, defining a path that should be followed
 */
typedef struct custom_drone_interfaces__msg__Path3D
{
  custom_drone_interfaces__msg__Waypoint__Sequence waypoints;
} custom_drone_interfaces__msg__Path3D;

// Struct for a sequence of custom_drone_interfaces__msg__Path3D.
typedef struct custom_drone_interfaces__msg__Path3D__Sequence
{
  custom_drone_interfaces__msg__Path3D * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_drone_interfaces__msg__Path3D__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__PATH3_D__STRUCT_H_
