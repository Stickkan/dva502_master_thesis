// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_drone_interfaces:msg/MissionCommand.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_COMMAND__TRAITS_HPP_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_drone_interfaces/msg/detail/mission_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_drone_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const MissionCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: command_flag
  {
    out << "command_flag: ";
    rosidl_generator_traits::value_to_yaml(msg.command_flag, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MissionCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: command_flag
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "command_flag: ";
    rosidl_generator_traits::value_to_yaml(msg.command_flag, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MissionCommand & msg, bool use_flow_style = false)
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
  const custom_drone_interfaces::msg::MissionCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_drone_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_drone_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_drone_interfaces::msg::MissionCommand & msg)
{
  return custom_drone_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_drone_interfaces::msg::MissionCommand>()
{
  return "custom_drone_interfaces::msg::MissionCommand";
}

template<>
inline const char * name<custom_drone_interfaces::msg::MissionCommand>()
{
  return "custom_drone_interfaces/msg/MissionCommand";
}

template<>
struct has_fixed_size<custom_drone_interfaces::msg::MissionCommand>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_drone_interfaces::msg::MissionCommand>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_drone_interfaces::msg::MissionCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_COMMAND__TRAITS_HPP_
