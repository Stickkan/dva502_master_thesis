// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_drone_interfaces:msg/StatusDataCollection.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__STATUS_DATA_COLLECTION__TRAITS_HPP_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__STATUS_DATA_COLLECTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_drone_interfaces/msg/detail/status_data_collection__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_drone_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const StatusDataCollection & msg,
  std::ostream & out)
{
  out << "{";
  // member: remaining
  {
    out << "remaining: ";
    rosidl_generator_traits::value_to_yaml(msg.remaining, out);
    out << ", ";
  }

  // member: time_remaining_s
  {
    out << "time_remaining_s: ";
    rosidl_generator_traits::value_to_yaml(msg.time_remaining_s, out);
    out << ", ";
  }

  // member: battery_warning
  {
    out << "battery_warning: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_warning, out);
    out << ", ";
  }

  // member: battery_unhealthy
  {
    out << "battery_unhealthy: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_unhealthy, out);
    out << ", ";
  }

  // member: angular_velocity_invalid
  {
    out << "angular_velocity_invalid: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_velocity_invalid, out);
    out << ", ";
  }

  // member: attitude_invalid
  {
    out << "attitude_invalid: ";
    rosidl_generator_traits::value_to_yaml(msg.attitude_invalid, out);
    out << ", ";
  }

  // member: global_position_invalid
  {
    out << "global_position_invalid: ";
    rosidl_generator_traits::value_to_yaml(msg.global_position_invalid, out);
    out << ", ";
  }

  // member: wind_limit_exceeded
  {
    out << "wind_limit_exceeded: ";
    rosidl_generator_traits::value_to_yaml(msg.wind_limit_exceeded, out);
    out << ", ";
  }

  // member: esc_arming_failure
  {
    out << "esc_arming_failure: ";
    rosidl_generator_traits::value_to_yaml(msg.esc_arming_failure, out);
    out << ", ";
  }

  // member: imbalanced_prop
  {
    out << "imbalanced_prop: ";
    rosidl_generator_traits::value_to_yaml(msg.imbalanced_prop, out);
    out << ", ";
  }

  // member: motor_failure
  {
    out << "motor_failure: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_failure, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StatusDataCollection & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: remaining
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "remaining: ";
    rosidl_generator_traits::value_to_yaml(msg.remaining, out);
    out << "\n";
  }

  // member: time_remaining_s
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time_remaining_s: ";
    rosidl_generator_traits::value_to_yaml(msg.time_remaining_s, out);
    out << "\n";
  }

  // member: battery_warning
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "battery_warning: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_warning, out);
    out << "\n";
  }

  // member: battery_unhealthy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "battery_unhealthy: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_unhealthy, out);
    out << "\n";
  }

  // member: angular_velocity_invalid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angular_velocity_invalid: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_velocity_invalid, out);
    out << "\n";
  }

  // member: attitude_invalid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "attitude_invalid: ";
    rosidl_generator_traits::value_to_yaml(msg.attitude_invalid, out);
    out << "\n";
  }

  // member: global_position_invalid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "global_position_invalid: ";
    rosidl_generator_traits::value_to_yaml(msg.global_position_invalid, out);
    out << "\n";
  }

  // member: wind_limit_exceeded
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "wind_limit_exceeded: ";
    rosidl_generator_traits::value_to_yaml(msg.wind_limit_exceeded, out);
    out << "\n";
  }

  // member: esc_arming_failure
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "esc_arming_failure: ";
    rosidl_generator_traits::value_to_yaml(msg.esc_arming_failure, out);
    out << "\n";
  }

  // member: imbalanced_prop
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "imbalanced_prop: ";
    rosidl_generator_traits::value_to_yaml(msg.imbalanced_prop, out);
    out << "\n";
  }

  // member: motor_failure
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor_failure: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_failure, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StatusDataCollection & msg, bool use_flow_style = false)
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
  const custom_drone_interfaces::msg::StatusDataCollection & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_drone_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_drone_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_drone_interfaces::msg::StatusDataCollection & msg)
{
  return custom_drone_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_drone_interfaces::msg::StatusDataCollection>()
{
  return "custom_drone_interfaces::msg::StatusDataCollection";
}

template<>
inline const char * name<custom_drone_interfaces::msg::StatusDataCollection>()
{
  return "custom_drone_interfaces/msg/StatusDataCollection";
}

template<>
struct has_fixed_size<custom_drone_interfaces::msg::StatusDataCollection>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_drone_interfaces::msg::StatusDataCollection>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_drone_interfaces::msg::StatusDataCollection>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__STATUS_DATA_COLLECTION__TRAITS_HPP_
