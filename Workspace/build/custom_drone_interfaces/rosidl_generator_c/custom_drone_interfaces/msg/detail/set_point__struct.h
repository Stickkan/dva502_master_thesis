// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_drone_interfaces:msg/SetPoint.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__SET_POINT__STRUCT_H_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__SET_POINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'setpoint_data'
#include "custom_drone_interfaces/msg/detail/sub_waypoint__struct.h"

/// Struct defined in msg/SetPoint in the package custom_drone_interfaces.
typedef struct custom_drone_interfaces__msg__SetPoint
{
  custom_drone_interfaces__msg__SubWaypoint setpoint_data;
  float frequency;
  bool r_t_f;
} custom_drone_interfaces__msg__SetPoint;

// Struct for a sequence of custom_drone_interfaces__msg__SetPoint.
typedef struct custom_drone_interfaces__msg__SetPoint__Sequence
{
  custom_drone_interfaces__msg__SetPoint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_drone_interfaces__msg__SetPoint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__SET_POINT__STRUCT_H_
