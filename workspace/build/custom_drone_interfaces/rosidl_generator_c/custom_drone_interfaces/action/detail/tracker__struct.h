// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_drone_interfaces:action/Tracker.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__ACTION__DETAIL__TRACKER__STRUCT_H_
#define CUSTOM_DRONE_INTERFACES__ACTION__DETAIL__TRACKER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'current_waypoint'
#include "custom_drone_interfaces/msg/detail/waypoint__struct.h"

/// Struct defined in action/Tracker in the package custom_drone_interfaces.
typedef struct custom_drone_interfaces__action__Tracker_Goal
{
  /// Waypoint containing subWaypoints with heading, position, velocity and acceleration data
  custom_drone_interfaces__msg__Waypoint current_waypoint;
} custom_drone_interfaces__action__Tracker_Goal;

// Struct for a sequence of custom_drone_interfaces__action__Tracker_Goal.
typedef struct custom_drone_interfaces__action__Tracker_Goal__Sequence
{
  custom_drone_interfaces__action__Tracker_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_drone_interfaces__action__Tracker_Goal__Sequence;


// Constants defined in the message

/// Struct defined in action/Tracker in the package custom_drone_interfaces.
typedef struct custom_drone_interfaces__action__Tracker_Result
{
  /// True if path was successfully followed
  bool success;
} custom_drone_interfaces__action__Tracker_Result;

// Struct for a sequence of custom_drone_interfaces__action__Tracker_Result.
typedef struct custom_drone_interfaces__action__Tracker_Result__Sequence
{
  custom_drone_interfaces__action__Tracker_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_drone_interfaces__action__Tracker_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'current_remaining_waypoint'
// already included above
// #include "custom_drone_interfaces/msg/detail/waypoint__struct.h"

/// Struct defined in action/Tracker in the package custom_drone_interfaces.
typedef struct custom_drone_interfaces__action__Tracker_Feedback
{
  /// Current UAV pose
  custom_drone_interfaces__msg__Waypoint current_remaining_waypoint;
  bool status_executing;
} custom_drone_interfaces__action__Tracker_Feedback;

// Struct for a sequence of custom_drone_interfaces__action__Tracker_Feedback.
typedef struct custom_drone_interfaces__action__Tracker_Feedback__Sequence
{
  custom_drone_interfaces__action__Tracker_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_drone_interfaces__action__Tracker_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "custom_drone_interfaces/action/detail/tracker__struct.h"

/// Struct defined in action/Tracker in the package custom_drone_interfaces.
typedef struct custom_drone_interfaces__action__Tracker_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  custom_drone_interfaces__action__Tracker_Goal goal;
} custom_drone_interfaces__action__Tracker_SendGoal_Request;

// Struct for a sequence of custom_drone_interfaces__action__Tracker_SendGoal_Request.
typedef struct custom_drone_interfaces__action__Tracker_SendGoal_Request__Sequence
{
  custom_drone_interfaces__action__Tracker_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_drone_interfaces__action__Tracker_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Tracker in the package custom_drone_interfaces.
typedef struct custom_drone_interfaces__action__Tracker_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} custom_drone_interfaces__action__Tracker_SendGoal_Response;

// Struct for a sequence of custom_drone_interfaces__action__Tracker_SendGoal_Response.
typedef struct custom_drone_interfaces__action__Tracker_SendGoal_Response__Sequence
{
  custom_drone_interfaces__action__Tracker_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_drone_interfaces__action__Tracker_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Tracker in the package custom_drone_interfaces.
typedef struct custom_drone_interfaces__action__Tracker_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} custom_drone_interfaces__action__Tracker_GetResult_Request;

// Struct for a sequence of custom_drone_interfaces__action__Tracker_GetResult_Request.
typedef struct custom_drone_interfaces__action__Tracker_GetResult_Request__Sequence
{
  custom_drone_interfaces__action__Tracker_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_drone_interfaces__action__Tracker_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "custom_drone_interfaces/action/detail/tracker__struct.h"

/// Struct defined in action/Tracker in the package custom_drone_interfaces.
typedef struct custom_drone_interfaces__action__Tracker_GetResult_Response
{
  int8_t status;
  custom_drone_interfaces__action__Tracker_Result result;
} custom_drone_interfaces__action__Tracker_GetResult_Response;

// Struct for a sequence of custom_drone_interfaces__action__Tracker_GetResult_Response.
typedef struct custom_drone_interfaces__action__Tracker_GetResult_Response__Sequence
{
  custom_drone_interfaces__action__Tracker_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_drone_interfaces__action__Tracker_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "custom_drone_interfaces/action/detail/tracker__struct.h"

/// Struct defined in action/Tracker in the package custom_drone_interfaces.
typedef struct custom_drone_interfaces__action__Tracker_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  custom_drone_interfaces__action__Tracker_Feedback feedback;
} custom_drone_interfaces__action__Tracker_FeedbackMessage;

// Struct for a sequence of custom_drone_interfaces__action__Tracker_FeedbackMessage.
typedef struct custom_drone_interfaces__action__Tracker_FeedbackMessage__Sequence
{
  custom_drone_interfaces__action__Tracker_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_drone_interfaces__action__Tracker_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_DRONE_INTERFACES__ACTION__DETAIL__TRACKER__STRUCT_H_
