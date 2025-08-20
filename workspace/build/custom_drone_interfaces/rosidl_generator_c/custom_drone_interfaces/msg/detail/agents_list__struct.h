// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_drone_interfaces:msg/AgentsList.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__AGENTS_LIST__STRUCT_H_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__AGENTS_LIST__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'agents'
#include "custom_drone_interfaces/msg/detail/agent_data__struct.h"

/// Struct defined in msg/AgentsList in the package custom_drone_interfaces.
/**
  * AgentList.msg
  * Contain a list of agents meant to avoid collision with these agents
  * Array of AgentData
 */
typedef struct custom_drone_interfaces__msg__AgentsList
{
  custom_drone_interfaces__msg__AgentData__Sequence agents;
} custom_drone_interfaces__msg__AgentsList;

// Struct for a sequence of custom_drone_interfaces__msg__AgentsList.
typedef struct custom_drone_interfaces__msg__AgentsList__Sequence
{
  custom_drone_interfaces__msg__AgentsList * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_drone_interfaces__msg__AgentsList__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__AGENTS_LIST__STRUCT_H_
