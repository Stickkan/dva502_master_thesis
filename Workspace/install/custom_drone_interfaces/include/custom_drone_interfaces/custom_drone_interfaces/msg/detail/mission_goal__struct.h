// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_drone_interfaces:msg/MissionGoal.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_GOAL__STRUCT_H_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_GOAL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'json_mission_data'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/MissionGoal in the package custom_drone_interfaces.
/**
  * mission_executor/msg/missionGoal.msg
  * Define the fields in the action goal
 */
typedef struct custom_drone_interfaces__msg__MissionGoal
{
  rosidl_runtime_c__String json_mission_data;
} custom_drone_interfaces__msg__MissionGoal;

// Struct for a sequence of custom_drone_interfaces__msg__MissionGoal.
typedef struct custom_drone_interfaces__msg__MissionGoal__Sequence
{
  custom_drone_interfaces__msg__MissionGoal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_drone_interfaces__msg__MissionGoal__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_GOAL__STRUCT_H_
