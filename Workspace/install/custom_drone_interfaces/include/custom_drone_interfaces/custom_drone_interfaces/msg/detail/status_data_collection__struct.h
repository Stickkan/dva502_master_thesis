// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_drone_interfaces:msg/StatusDataCollection.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__STATUS_DATA_COLLECTION__STRUCT_H_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__STATUS_DATA_COLLECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/StatusDataCollection in the package custom_drone_interfaces.
/**
  * Battery
 */
typedef struct custom_drone_interfaces__msg__StatusDataCollection
{
  /// From 1 to 0, -1 if unknown
  float remaining;
  /// predicted time in seconds remaining until battery is empty under previous averaged load, NAN if unknown
  float time_remaining_s;
  /// Battery warning level
  uint8_t battery_warning;
  /// Battery unhealthy
  bool battery_unhealthy;
  /// Fail flags
  ///  Angular velocity invalid
  bool angular_velocity_invalid;
  /// Attitude invalid
  bool attitude_invalid;
  /// Global position estimate invalid
  bool global_position_invalid;
  /// Wind limit exceeded
  bool wind_limit_exceeded;
  /// Failure
  /// ESC failed to arm
  bool esc_arming_failure;
  /// Imbalanced propeller detected
  bool imbalanced_prop;
  /// Motor failure
  bool motor_failure;
} custom_drone_interfaces__msg__StatusDataCollection;

// Struct for a sequence of custom_drone_interfaces__msg__StatusDataCollection.
typedef struct custom_drone_interfaces__msg__StatusDataCollection__Sequence
{
  custom_drone_interfaces__msg__StatusDataCollection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_drone_interfaces__msg__StatusDataCollection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__STATUS_DATA_COLLECTION__STRUCT_H_
