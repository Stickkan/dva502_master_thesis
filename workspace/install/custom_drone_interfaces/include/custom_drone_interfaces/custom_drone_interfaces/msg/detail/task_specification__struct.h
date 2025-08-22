// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_drone_interfaces:msg/TaskSpecification.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__TASK_SPECIFICATION__STRUCT_H_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__TASK_SPECIFICATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/TaskSpecification in the package custom_drone_interfaces.
/**
  * Future proof task handling. 
  * Current flags:
  * 1   = TAKE_OFF
  * 2   = LANDING
  * 3   = CAMERA_IMAGE   The UAV is instructed to take image(s).
  * 4   = VIDEO_START_CAPTURE  Video capture starts.
  * 5   = VIDEO_STOP_CAPTURE Video capture ends.
  *
  * 255 = TO_TASK               Nothing to do
 */
typedef struct custom_drone_interfaces__msg__TaskSpecification
{
  int16_t flag;
  double settings[5];
} custom_drone_interfaces__msg__TaskSpecification;

// Struct for a sequence of custom_drone_interfaces__msg__TaskSpecification.
typedef struct custom_drone_interfaces__msg__TaskSpecification__Sequence
{
  custom_drone_interfaces__msg__TaskSpecification * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_drone_interfaces__msg__TaskSpecification__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__TASK_SPECIFICATION__STRUCT_H_
