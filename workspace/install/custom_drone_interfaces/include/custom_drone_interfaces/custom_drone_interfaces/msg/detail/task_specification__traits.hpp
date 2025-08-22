// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_drone_interfaces:msg/TaskSpecification.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__TASK_SPECIFICATION__TRAITS_HPP_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__TASK_SPECIFICATION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_drone_interfaces/msg/detail/task_specification__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_drone_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const TaskSpecification & msg,
  std::ostream & out)
{
  out << "{";
  // member: flag
  {
    out << "flag: ";
    rosidl_generator_traits::value_to_yaml(msg.flag, out);
    out << ", ";
  }

  // member: settings
  {
    if (msg.settings.size() == 0) {
      out << "settings: []";
    } else {
      out << "settings: [";
      size_t pending_items = msg.settings.size();
      for (auto item : msg.settings) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TaskSpecification & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: flag
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "flag: ";
    rosidl_generator_traits::value_to_yaml(msg.flag, out);
    out << "\n";
  }

  // member: settings
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.settings.size() == 0) {
      out << "settings: []\n";
    } else {
      out << "settings:\n";
      for (auto item : msg.settings) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TaskSpecification & msg, bool use_flow_style = false)
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
  const custom_drone_interfaces::msg::TaskSpecification & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_drone_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_drone_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_drone_interfaces::msg::TaskSpecification & msg)
{
  return custom_drone_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_drone_interfaces::msg::TaskSpecification>()
{
  return "custom_drone_interfaces::msg::TaskSpecification";
}

template<>
inline const char * name<custom_drone_interfaces::msg::TaskSpecification>()
{
  return "custom_drone_interfaces/msg/TaskSpecification";
}

template<>
struct has_fixed_size<custom_drone_interfaces::msg::TaskSpecification>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_drone_interfaces::msg::TaskSpecification>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_drone_interfaces::msg::TaskSpecification>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__TASK_SPECIFICATION__TRAITS_HPP_
