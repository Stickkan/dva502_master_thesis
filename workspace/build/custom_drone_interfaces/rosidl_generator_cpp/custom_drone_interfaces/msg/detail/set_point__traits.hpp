// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_drone_interfaces:msg/SetPoint.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__SET_POINT__TRAITS_HPP_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__SET_POINT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_drone_interfaces/msg/detail/set_point__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'setpoint_data'
#include "custom_drone_interfaces/msg/detail/sub_waypoint__traits.hpp"

namespace custom_drone_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const SetPoint & msg,
  std::ostream & out)
{
  out << "{";
  // member: setpoint_data
  {
    out << "setpoint_data: ";
    to_flow_style_yaml(msg.setpoint_data, out);
    out << ", ";
  }

  // member: frequency
  {
    out << "frequency: ";
    rosidl_generator_traits::value_to_yaml(msg.frequency, out);
    out << ", ";
  }

  // member: r_t_f
  {
    out << "r_t_f: ";
    rosidl_generator_traits::value_to_yaml(msg.r_t_f, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetPoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: setpoint_data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "setpoint_data:\n";
    to_block_style_yaml(msg.setpoint_data, out, indentation + 2);
  }

  // member: frequency
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "frequency: ";
    rosidl_generator_traits::value_to_yaml(msg.frequency, out);
    out << "\n";
  }

  // member: r_t_f
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "r_t_f: ";
    rosidl_generator_traits::value_to_yaml(msg.r_t_f, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetPoint & msg, bool use_flow_style = false)
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
  const custom_drone_interfaces::msg::SetPoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_drone_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_drone_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_drone_interfaces::msg::SetPoint & msg)
{
  return custom_drone_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_drone_interfaces::msg::SetPoint>()
{
  return "custom_drone_interfaces::msg::SetPoint";
}

template<>
inline const char * name<custom_drone_interfaces::msg::SetPoint>()
{
  return "custom_drone_interfaces/msg/SetPoint";
}

template<>
struct has_fixed_size<custom_drone_interfaces::msg::SetPoint>
  : std::integral_constant<bool, has_fixed_size<custom_drone_interfaces::msg::SubWaypoint>::value> {};

template<>
struct has_bounded_size<custom_drone_interfaces::msg::SetPoint>
  : std::integral_constant<bool, has_bounded_size<custom_drone_interfaces::msg::SubWaypoint>::value> {};

template<>
struct is_message<custom_drone_interfaces::msg::SetPoint>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__SET_POINT__TRAITS_HPP_
