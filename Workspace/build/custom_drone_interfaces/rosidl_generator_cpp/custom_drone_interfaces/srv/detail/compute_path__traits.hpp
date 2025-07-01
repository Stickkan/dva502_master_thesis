// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_drone_interfaces:srv/ComputePath.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__SRV__DETAIL__COMPUTE_PATH__TRAITS_HPP_
#define CUSTOM_DRONE_INTERFACES__SRV__DETAIL__COMPUTE_PATH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_drone_interfaces/srv/detail/compute_path__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'input_path'
#include "custom_drone_interfaces/msg/detail/path3_d__traits.hpp"

namespace custom_drone_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ComputePath_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: input_path
  {
    out << "input_path: ";
    to_flow_style_yaml(msg.input_path, out);
    out << ", ";
  }

  // member: velocity_limit
  {
    if (msg.velocity_limit.size() == 0) {
      out << "velocity_limit: []";
    } else {
      out << "velocity_limit: [";
      size_t pending_items = msg.velocity_limit.size();
      for (auto item : msg.velocity_limit) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: acceleration_limit
  {
    if (msg.acceleration_limit.size() == 0) {
      out << "acceleration_limit: []";
    } else {
      out << "acceleration_limit: [";
      size_t pending_items = msg.acceleration_limit.size();
      for (auto item : msg.acceleration_limit) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: planning_method
  {
    out << "planning_method: ";
    rosidl_generator_traits::value_to_yaml(msg.planning_method, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ComputePath_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: input_path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "input_path:\n";
    to_block_style_yaml(msg.input_path, out, indentation + 2);
  }

  // member: velocity_limit
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.velocity_limit.size() == 0) {
      out << "velocity_limit: []\n";
    } else {
      out << "velocity_limit:\n";
      for (auto item : msg.velocity_limit) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: acceleration_limit
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.acceleration_limit.size() == 0) {
      out << "acceleration_limit: []\n";
    } else {
      out << "acceleration_limit:\n";
      for (auto item : msg.acceleration_limit) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: planning_method
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "planning_method: ";
    rosidl_generator_traits::value_to_yaml(msg.planning_method, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ComputePath_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace custom_drone_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_drone_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_drone_interfaces::srv::ComputePath_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_drone_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_drone_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_drone_interfaces::srv::ComputePath_Request & msg)
{
  return custom_drone_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_drone_interfaces::srv::ComputePath_Request>()
{
  return "custom_drone_interfaces::srv::ComputePath_Request";
}

template<>
inline const char * name<custom_drone_interfaces::srv::ComputePath_Request>()
{
  return "custom_drone_interfaces/srv/ComputePath_Request";
}

template<>
struct has_fixed_size<custom_drone_interfaces::srv::ComputePath_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_drone_interfaces::srv::ComputePath_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_drone_interfaces::srv::ComputePath_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'planned_path'
// already included above
// #include "custom_drone_interfaces/msg/detail/path3_d__traits.hpp"

namespace custom_drone_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ComputePath_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: planned_path
  {
    out << "planned_path: ";
    to_flow_style_yaml(msg.planned_path, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ComputePath_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: planned_path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "planned_path:\n";
    to_block_style_yaml(msg.planned_path, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ComputePath_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace custom_drone_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_drone_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_drone_interfaces::srv::ComputePath_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_drone_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_drone_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_drone_interfaces::srv::ComputePath_Response & msg)
{
  return custom_drone_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_drone_interfaces::srv::ComputePath_Response>()
{
  return "custom_drone_interfaces::srv::ComputePath_Response";
}

template<>
inline const char * name<custom_drone_interfaces::srv::ComputePath_Response>()
{
  return "custom_drone_interfaces/srv/ComputePath_Response";
}

template<>
struct has_fixed_size<custom_drone_interfaces::srv::ComputePath_Response>
  : std::integral_constant<bool, has_fixed_size<custom_drone_interfaces::msg::Path3D>::value> {};

template<>
struct has_bounded_size<custom_drone_interfaces::srv::ComputePath_Response>
  : std::integral_constant<bool, has_bounded_size<custom_drone_interfaces::msg::Path3D>::value> {};

template<>
struct is_message<custom_drone_interfaces::srv::ComputePath_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_drone_interfaces::srv::ComputePath>()
{
  return "custom_drone_interfaces::srv::ComputePath";
}

template<>
inline const char * name<custom_drone_interfaces::srv::ComputePath>()
{
  return "custom_drone_interfaces/srv/ComputePath";
}

template<>
struct has_fixed_size<custom_drone_interfaces::srv::ComputePath>
  : std::integral_constant<
    bool,
    has_fixed_size<custom_drone_interfaces::srv::ComputePath_Request>::value &&
    has_fixed_size<custom_drone_interfaces::srv::ComputePath_Response>::value
  >
{
};

template<>
struct has_bounded_size<custom_drone_interfaces::srv::ComputePath>
  : std::integral_constant<
    bool,
    has_bounded_size<custom_drone_interfaces::srv::ComputePath_Request>::value &&
    has_bounded_size<custom_drone_interfaces::srv::ComputePath_Response>::value
  >
{
};

template<>
struct is_service<custom_drone_interfaces::srv::ComputePath>
  : std::true_type
{
};

template<>
struct is_service_request<custom_drone_interfaces::srv::ComputePath_Request>
  : std::true_type
{
};

template<>
struct is_service_response<custom_drone_interfaces::srv::ComputePath_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_DRONE_INTERFACES__SRV__DETAIL__COMPUTE_PATH__TRAITS_HPP_
