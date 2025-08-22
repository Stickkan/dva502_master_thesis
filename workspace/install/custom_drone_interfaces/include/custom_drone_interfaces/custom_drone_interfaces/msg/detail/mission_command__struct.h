// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_drone_interfaces:msg/MissionCommand.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_COMMAND__STRUCT_H_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/MissionCommand in the package custom_drone_interfaces.
/**
  * mission_executor/msg/missionCommand.msg
  * MISSION_ABORT 1
  * MISSION_SUSPEND 2
  * MISSION_RESUME 3
 */
typedef struct custom_drone_interfaces__msg__MissionCommand
{
  uint16_t command_flag;
} custom_drone_interfaces__msg__MissionCommand;

// Struct for a sequence of custom_drone_interfaces__msg__MissionCommand.
typedef struct custom_drone_interfaces__msg__MissionCommand__Sequence
{
  custom_drone_interfaces__msg__MissionCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_drone_interfaces__msg__MissionCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_COMMAND__STRUCT_H_
