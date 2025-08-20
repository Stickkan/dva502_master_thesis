// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_drone_interfaces:action/Tracker.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__ACTION__DETAIL__TRACKER__TRAITS_HPP_
#define CUSTOM_DRONE_INTERFACES__ACTION__DETAIL__TRACKER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_drone_interfaces/action/detail/tracker__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'current_waypoint'
#include "custom_drone_interfaces/msg/detail/waypoint__traits.hpp"

namespace custom_drone_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Tracker_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: current_waypoint
  {
    out << "current_waypoint: ";
    to_flow_style_yaml(msg.current_waypoint, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Tracker_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: current_waypoint
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_waypoint:\n";
    to_block_style_yaml(msg.current_waypoint, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Tracker_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace custom_drone_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_drone_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_drone_interfaces::action::Tracker_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_drone_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_drone_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const custom_drone_interfaces::action::Tracker_Goal & msg)
{
  return custom_drone_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<custom_drone_interfaces::action::Tracker_Goal>()
{
  return "custom_drone_interfaces::action::Tracker_Goal";
}

template<>
inline const char * name<custom_drone_interfaces::action::Tracker_Goal>()
{
  return "custom_drone_interfaces/action/Tracker_Goal";
}

template<>
struct has_fixed_size<custom_drone_interfaces::action::Tracker_Goal>
  : std::integral_constant<bool, has_fixed_size<custom_drone_interfaces::msg::Waypoint>::value> {};

template<>
struct has_bounded_size<custom_drone_interfaces::action::Tracker_Goal>
  : std::integral_constant<bool, has_bounded_size<custom_drone_interfaces::msg::Waypoint>::value> {};

template<>
struct is_message<custom_drone_interfaces::action::Tracker_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace custom_drone_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Tracker_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Tracker_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Tracker_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace custom_drone_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_drone_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_drone_interfaces::action::Tracker_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_drone_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_drone_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const custom_drone_interfaces::action::Tracker_Result & msg)
{
  return custom_drone_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<custom_drone_interfaces::action::Tracker_Result>()
{
  return "custom_drone_interfaces::action::Tracker_Result";
}

template<>
inline const char * name<custom_drone_interfaces::action::Tracker_Result>()
{
  return "custom_drone_interfaces/action/Tracker_Result";
}

template<>
struct has_fixed_size<custom_drone_interfaces::action::Tracker_Result>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_drone_interfaces::action::Tracker_Result>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_drone_interfaces::action::Tracker_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'current_remaining_waypoint'
// already included above
// #include "custom_drone_interfaces/msg/detail/waypoint__traits.hpp"

namespace custom_drone_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Tracker_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: current_remaining_waypoint
  {
    out << "current_remaining_waypoint: ";
    to_flow_style_yaml(msg.current_remaining_waypoint, out);
    out << ", ";
  }

  // member: status_executing
  {
    out << "status_executing: ";
    rosidl_generator_traits::value_to_yaml(msg.status_executing, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Tracker_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: current_remaining_waypoint
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_remaining_waypoint:\n";
    to_block_style_yaml(msg.current_remaining_waypoint, out, indentation + 2);
  }

  // member: status_executing
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status_executing: ";
    rosidl_generator_traits::value_to_yaml(msg.status_executing, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Tracker_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace custom_drone_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_drone_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_drone_interfaces::action::Tracker_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_drone_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_drone_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const custom_drone_interfaces::action::Tracker_Feedback & msg)
{
  return custom_drone_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<custom_drone_interfaces::action::Tracker_Feedback>()
{
  return "custom_drone_interfaces::action::Tracker_Feedback";
}

template<>
inline const char * name<custom_drone_interfaces::action::Tracker_Feedback>()
{
  return "custom_drone_interfaces/action/Tracker_Feedback";
}

template<>
struct has_fixed_size<custom_drone_interfaces::action::Tracker_Feedback>
  : std::integral_constant<bool, has_fixed_size<custom_drone_interfaces::msg::Waypoint>::value> {};

template<>
struct has_bounded_size<custom_drone_interfaces::action::Tracker_Feedback>
  : std::integral_constant<bool, has_bounded_size<custom_drone_interfaces::msg::Waypoint>::value> {};

template<>
struct is_message<custom_drone_interfaces::action::Tracker_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "custom_drone_interfaces/action/detail/tracker__traits.hpp"

namespace custom_drone_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Tracker_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Tracker_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Tracker_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace custom_drone_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_drone_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_drone_interfaces::action::Tracker_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_drone_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_drone_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const custom_drone_interfaces::action::Tracker_SendGoal_Request & msg)
{
  return custom_drone_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<custom_drone_interfaces::action::Tracker_SendGoal_Request>()
{
  return "custom_drone_interfaces::action::Tracker_SendGoal_Request";
}

template<>
inline const char * name<custom_drone_interfaces::action::Tracker_SendGoal_Request>()
{
  return "custom_drone_interfaces/action/Tracker_SendGoal_Request";
}

template<>
struct has_fixed_size<custom_drone_interfaces::action::Tracker_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<custom_drone_interfaces::action::Tracker_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<custom_drone_interfaces::action::Tracker_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<custom_drone_interfaces::action::Tracker_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<custom_drone_interfaces::action::Tracker_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace custom_drone_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Tracker_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Tracker_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Tracker_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace custom_drone_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_drone_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_drone_interfaces::action::Tracker_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_drone_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_drone_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const custom_drone_interfaces::action::Tracker_SendGoal_Response & msg)
{
  return custom_drone_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<custom_drone_interfaces::action::Tracker_SendGoal_Response>()
{
  return "custom_drone_interfaces::action::Tracker_SendGoal_Response";
}

template<>
inline const char * name<custom_drone_interfaces::action::Tracker_SendGoal_Response>()
{
  return "custom_drone_interfaces/action/Tracker_SendGoal_Response";
}

template<>
struct has_fixed_size<custom_drone_interfaces::action::Tracker_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<custom_drone_interfaces::action::Tracker_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<custom_drone_interfaces::action::Tracker_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_drone_interfaces::action::Tracker_SendGoal>()
{
  return "custom_drone_interfaces::action::Tracker_SendGoal";
}

template<>
inline const char * name<custom_drone_interfaces::action::Tracker_SendGoal>()
{
  return "custom_drone_interfaces/action/Tracker_SendGoal";
}

template<>
struct has_fixed_size<custom_drone_interfaces::action::Tracker_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<custom_drone_interfaces::action::Tracker_SendGoal_Request>::value &&
    has_fixed_size<custom_drone_interfaces::action::Tracker_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<custom_drone_interfaces::action::Tracker_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<custom_drone_interfaces::action::Tracker_SendGoal_Request>::value &&
    has_bounded_size<custom_drone_interfaces::action::Tracker_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<custom_drone_interfaces::action::Tracker_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<custom_drone_interfaces::action::Tracker_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<custom_drone_interfaces::action::Tracker_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace custom_drone_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Tracker_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Tracker_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Tracker_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace custom_drone_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_drone_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_drone_interfaces::action::Tracker_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_drone_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_drone_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const custom_drone_interfaces::action::Tracker_GetResult_Request & msg)
{
  return custom_drone_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<custom_drone_interfaces::action::Tracker_GetResult_Request>()
{
  return "custom_drone_interfaces::action::Tracker_GetResult_Request";
}

template<>
inline const char * name<custom_drone_interfaces::action::Tracker_GetResult_Request>()
{
  return "custom_drone_interfaces/action/Tracker_GetResult_Request";
}

template<>
struct has_fixed_size<custom_drone_interfaces::action::Tracker_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<custom_drone_interfaces::action::Tracker_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<custom_drone_interfaces::action::Tracker_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "custom_drone_interfaces/action/detail/tracker__traits.hpp"

namespace custom_drone_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Tracker_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Tracker_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Tracker_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace custom_drone_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_drone_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_drone_interfaces::action::Tracker_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_drone_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_drone_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const custom_drone_interfaces::action::Tracker_GetResult_Response & msg)
{
  return custom_drone_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<custom_drone_interfaces::action::Tracker_GetResult_Response>()
{
  return "custom_drone_interfaces::action::Tracker_GetResult_Response";
}

template<>
inline const char * name<custom_drone_interfaces::action::Tracker_GetResult_Response>()
{
  return "custom_drone_interfaces/action/Tracker_GetResult_Response";
}

template<>
struct has_fixed_size<custom_drone_interfaces::action::Tracker_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<custom_drone_interfaces::action::Tracker_Result>::value> {};

template<>
struct has_bounded_size<custom_drone_interfaces::action::Tracker_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<custom_drone_interfaces::action::Tracker_Result>::value> {};

template<>
struct is_message<custom_drone_interfaces::action::Tracker_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_drone_interfaces::action::Tracker_GetResult>()
{
  return "custom_drone_interfaces::action::Tracker_GetResult";
}

template<>
inline const char * name<custom_drone_interfaces::action::Tracker_GetResult>()
{
  return "custom_drone_interfaces/action/Tracker_GetResult";
}

template<>
struct has_fixed_size<custom_drone_interfaces::action::Tracker_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<custom_drone_interfaces::action::Tracker_GetResult_Request>::value &&
    has_fixed_size<custom_drone_interfaces::action::Tracker_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<custom_drone_interfaces::action::Tracker_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<custom_drone_interfaces::action::Tracker_GetResult_Request>::value &&
    has_bounded_size<custom_drone_interfaces::action::Tracker_GetResult_Response>::value
  >
{
};

template<>
struct is_service<custom_drone_interfaces::action::Tracker_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<custom_drone_interfaces::action::Tracker_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<custom_drone_interfaces::action::Tracker_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "custom_drone_interfaces/action/detail/tracker__traits.hpp"

namespace custom_drone_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Tracker_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Tracker_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Tracker_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace custom_drone_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_drone_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_drone_interfaces::action::Tracker_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_drone_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_drone_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const custom_drone_interfaces::action::Tracker_FeedbackMessage & msg)
{
  return custom_drone_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<custom_drone_interfaces::action::Tracker_FeedbackMessage>()
{
  return "custom_drone_interfaces::action::Tracker_FeedbackMessage";
}

template<>
inline const char * name<custom_drone_interfaces::action::Tracker_FeedbackMessage>()
{
  return "custom_drone_interfaces/action/Tracker_FeedbackMessage";
}

template<>
struct has_fixed_size<custom_drone_interfaces::action::Tracker_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<custom_drone_interfaces::action::Tracker_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<custom_drone_interfaces::action::Tracker_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<custom_drone_interfaces::action::Tracker_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<custom_drone_interfaces::action::Tracker_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<custom_drone_interfaces::action::Tracker>
  : std::true_type
{
};

template<>
struct is_action_goal<custom_drone_interfaces::action::Tracker_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<custom_drone_interfaces::action::Tracker_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<custom_drone_interfaces::action::Tracker_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // CUSTOM_DRONE_INTERFACES__ACTION__DETAIL__TRACKER__TRAITS_HPP_
