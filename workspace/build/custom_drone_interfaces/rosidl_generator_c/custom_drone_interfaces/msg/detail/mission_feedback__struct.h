// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_drone_interfaces:msg/MissionFeedback.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_FEEDBACK__STRUCT_H_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_FEEDBACK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'feedback_message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/MissionFeedback in the package custom_drone_interfaces.
/**
  * mission_executor/msg/missionFeedback.msg
  * Define the fields in the action feedback
  * Update, becouse i dont know yet what i want
 */
typedef struct custom_drone_interfaces__msg__MissionFeedback
{
  rosidl_runtime_c__String feedback_message;
} custom_drone_interfaces__msg__MissionFeedback;

// Struct for a sequence of custom_drone_interfaces__msg__MissionFeedback.
typedef struct custom_drone_interfaces__msg__MissionFeedback__Sequence
{
  custom_drone_interfaces__msg__MissionFeedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_drone_interfaces__msg__MissionFeedback__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_FEEDBACK__STRUCT_H_
