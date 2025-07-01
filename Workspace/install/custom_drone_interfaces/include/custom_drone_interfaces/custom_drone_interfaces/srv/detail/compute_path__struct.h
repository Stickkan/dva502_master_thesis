// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_drone_interfaces:srv/ComputePath.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__SRV__DETAIL__COMPUTE_PATH__STRUCT_H_
#define CUSTOM_DRONE_INTERFACES__SRV__DETAIL__COMPUTE_PATH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'input_path'
#include "custom_drone_interfaces/msg/detail/path3_d__struct.h"
// Member 'planning_method'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ComputePath in the package custom_drone_interfaces.
typedef struct custom_drone_interfaces__srv__ComputePath_Request
{
  /// List of custom_drone_interfaces/msg/Waypoints
  custom_drone_interfaces__msg__Path3D input_path;
  /// Maximum velocity limit
  double velocity_limit[3];
  /// Maximum acceleration limit
  double acceleration_limit[3];
  rosidl_runtime_c__String planning_method;
} custom_drone_interfaces__srv__ComputePath_Request;

// Struct for a sequence of custom_drone_interfaces__srv__ComputePath_Request.
typedef struct custom_drone_interfaces__srv__ComputePath_Request__Sequence
{
  custom_drone_interfaces__srv__ComputePath_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_drone_interfaces__srv__ComputePath_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'planned_path'
// already included above
// #include "custom_drone_interfaces/msg/detail/path3_d__struct.h"

/// Struct defined in srv/ComputePath in the package custom_drone_interfaces.
typedef struct custom_drone_interfaces__srv__ComputePath_Response
{
  custom_drone_interfaces__msg__Path3D planned_path;
} custom_drone_interfaces__srv__ComputePath_Response;

// Struct for a sequence of custom_drone_interfaces__srv__ComputePath_Response.
typedef struct custom_drone_interfaces__srv__ComputePath_Response__Sequence
{
  custom_drone_interfaces__srv__ComputePath_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_drone_interfaces__srv__ComputePath_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_DRONE_INTERFACES__SRV__DETAIL__COMPUTE_PATH__STRUCT_H_
