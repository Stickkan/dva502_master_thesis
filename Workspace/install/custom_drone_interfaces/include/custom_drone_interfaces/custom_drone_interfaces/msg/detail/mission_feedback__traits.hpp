// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_drone_interfaces:msg/MissionFeedback.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_FEEDBACK__TRAITS_HPP_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_FEEDBACK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_drone_interfaces/msg/detail/mission_feedback__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_drone_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const MissionFeedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: feedback_message
  {
    out << "feedback_message: ";
    rosidl_generator_traits::value_to_yaml(msg.feedback_message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MissionFeedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: feedback_message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback_message: ";
    rosidl_generator_traits::value_to_yaml(msg.feedback_message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MissionFeedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace custom_drone_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_drone_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_drone_interfaces::msg::MissionFeedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_drone_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_drone_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_drone_interfaces::msg::MissionFeedback & msg)
{
  return custom_drone_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_drone_interfaces::msg::MissionFeedback>()
{
  return "custom_drone_interfaces::msg::MissionFeedback";
}

template<>
inline const char * name<custom_drone_interfaces::msg::MissionFeedback>()
{
  return "custom_drone_interfaces/msg/MissionFeedback";
}

template<>
struct has_fixed_size<custom_drone_interfaces::msg::MissionFeedback>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_drone_interfaces::msg::MissionFeedback>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_drone_interfaces::msg::MissionFeedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_FEEDBACK__TRAITS_HPP_
