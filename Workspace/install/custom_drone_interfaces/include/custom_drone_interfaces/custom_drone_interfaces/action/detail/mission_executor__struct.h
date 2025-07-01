// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_drone_interfaces:action/MissionExecutor.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__ACTION__DETAIL__MISSION_EXECUTOR__STRUCT_H_
#define CUSTOM_DRONE_INTERFACES__ACTION__DETAIL__MISSION_EXECUTOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'mission_goal'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/MissionExecutor in the package custom_drone_interfaces.
typedef struct custom_drone_interfaces__action__MissionExecutor_Goal
{
  rosidl_runtime_c__String mission_goal;
} custom_drone_interfaces__action__MissionExecutor_Goal;

// Struct for a sequence of custom_drone_interfaces__action__MissionExecutor_Goal.
typedef struct custom_drone_interfaces__action__MissionExecutor_Goal__Sequence
{
  custom_drone_interfaces__action__MissionExecutor_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_drone_interfaces__action__MissionExecutor_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'mission_result'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/MissionExecutor in the package custom_drone_interfaces.
typedef struct custom_drone_interfaces__action__MissionExecutor_Result
{
  rosidl_runtime_c__String mission_result;
} custom_drone_interfaces__action__MissionExecutor_Result;

// Struct for a sequence of custom_drone_interfaces__action__MissionExecutor_Result.
typedef struct custom_drone_interfaces__action__MissionExecutor_Result__Sequence
{
  custom_drone_interfaces__action__MissionExecutor_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_drone_interfaces__action__MissionExecutor_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'mission_feedback'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/MissionExecutor in the package custom_drone_interfaces.
typedef struct custom_drone_interfaces__action__MissionExecutor_Feedback
{
  rosidl_runtime_c__String mission_feedback;
  int32_t status_code;
  int32_t command_id;
} custom_drone_interfaces__action__MissionExecutor_Feedback;

// Struct for a sequence of custom_drone_interfaces__action__MissionExecutor_Feedback.
typedef struct custom_drone_interfaces__action__MissionExecutor_Feedback__Sequence
{
  custom_drone_interfaces__action__MissionExecutor_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_drone_interfaces__action__MissionExecutor_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "custom_drone_interfaces/action/detail/mission_executor__struct.h"

/// Struct defined in action/MissionExecutor in the package custom_drone_interfaces.
typedef struct custom_drone_interfaces__action__MissionExecutor_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  custom_drone_interfaces__action__MissionExecutor_Goal goal;
} custom_drone_interfaces__action__MissionExecutor_SendGoal_Request;

// Struct for a sequence of custom_drone_interfaces__action__MissionExecutor_SendGoal_Request.
typedef struct custom_drone_interfaces__action__MissionExecutor_SendGoal_Request__Sequence
{
  custom_drone_interfaces__action__MissionExecutor_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_drone_interfaces__action__MissionExecutor_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/MissionExecutor in the package custom_drone_interfaces.
typedef struct custom_drone_interfaces__action__MissionExecutor_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} custom_drone_interfaces__action__MissionExecutor_SendGoal_Response;

// Struct for a sequence of custom_drone_interfaces__action__MissionExecutor_SendGoal_Response.
typedef struct custom_drone_interfaces__action__MissionExecutor_SendGoal_Response__Sequence
{
  custom_drone_interfaces__action__MissionExecutor_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_drone_interfaces__action__MissionExecutor_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/MissionExecutor in the package custom_drone_interfaces.
typedef struct custom_drone_interfaces__action__MissionExecutor_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} custom_drone_interfaces__action__MissionExecutor_GetResult_Request;

// Struct for a sequence of custom_drone_interfaces__action__MissionExecutor_GetResult_Request.
typedef struct custom_drone_interfaces__action__MissionExecutor_GetResult_Request__Sequence
{
  custom_drone_interfaces__action__MissionExecutor_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_drone_interfaces__action__MissionExecutor_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "custom_drone_interfaces/action/detail/mission_executor__struct.h"

/// Struct defined in action/MissionExecutor in the package custom_drone_interfaces.
typedef struct custom_drone_interfaces__action__MissionExecutor_GetResult_Response
{
  int8_t status;
  custom_drone_interfaces__action__MissionExecutor_Result result;
} custom_drone_interfaces__action__MissionExecutor_GetResult_Response;

// Struct for a sequence of custom_drone_interfaces__action__MissionExecutor_GetResult_Response.
typedef struct custom_drone_interfaces__action__MissionExecutor_GetResult_Response__Sequence
{
  custom_drone_interfaces__action__MissionExecutor_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_drone_interfaces__action__MissionExecutor_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "custom_drone_interfaces/action/detail/mission_executor__struct.h"

/// Struct defined in action/MissionExecutor in the package custom_drone_interfaces.
typedef struct custom_drone_interfaces__action__MissionExecutor_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  custom_drone_interfaces__action__MissionExecutor_Feedback feedback;
} custom_drone_interfaces__action__MissionExecutor_FeedbackMessage;

// Struct for a sequence of custom_drone_interfaces__action__MissionExecutor_FeedbackMessage.
typedef struct custom_drone_interfaces__action__MissionExecutor_FeedbackMessage__Sequence
{
  custom_drone_interfaces__action__MissionExecutor_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_drone_interfaces__action__MissionExecutor_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_DRONE_INTERFACES__ACTION__DETAIL__MISSION_EXECUTOR__STRUCT_H_
