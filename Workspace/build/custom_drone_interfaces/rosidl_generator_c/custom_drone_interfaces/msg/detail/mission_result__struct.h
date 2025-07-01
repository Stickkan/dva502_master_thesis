// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_drone_interfaces:msg/MissionResult.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_RESULT__STRUCT_H_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_RESULT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'result_message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/MissionResult in the package custom_drone_interfaces.
/**
  * mission_executor/msg/missionResult.msg
  * Define the fields in the action result
  * Update, becouse i dont know yet what i want
 */
typedef struct custom_drone_interfaces__msg__MissionResult
{
  rosidl_runtime_c__String result_message;
} custom_drone_interfaces__msg__MissionResult;

// Struct for a sequence of custom_drone_interfaces__msg__MissionResult.
typedef struct custom_drone_interfaces__msg__MissionResult__Sequence
{
  custom_drone_interfaces__msg__MissionResult * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_drone_interfaces__msg__MissionResult__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_RESULT__STRUCT_H_
