// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_drone_interfaces:msg/ObjectProximityData.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__OBJECT_PROXIMITY_DATA__STRUCT_H_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__OBJECT_PROXIMITY_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/ObjectProximityData in the package custom_drone_interfaces.
/**
  * ObjectData.msg
  * Represent one objects id, velocity and position meant for Traffic collision avoidance
  * ID
 */
typedef struct custom_drone_interfaces__msg__ObjectProximityData
{
  uint32_t agentid;
  /// Priority
  uint8_t priority;
  /// Velocity component
  float vx;
  float vy;
  float vz;
  /// Position Component
  double lat;
  double lon;
  float alt;
  /// Time component
  uint64_t time;
} custom_drone_interfaces__msg__ObjectProximityData;

// Struct for a sequence of custom_drone_interfaces__msg__ObjectProximityData.
typedef struct custom_drone_interfaces__msg__ObjectProximityData__Sequence
{
  custom_drone_interfaces__msg__ObjectProximityData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_drone_interfaces__msg__ObjectProximityData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__OBJECT_PROXIMITY_DATA__STRUCT_H_
