// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_drone_interfaces:msg/Waypoint.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__WAYPOINT__TRAITS_HPP_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__WAYPOINT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_drone_interfaces/msg/detail/waypoint__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'point'
#include "geometry_msgs/msg/detail/point__traits.hpp"
// Member 'velocity'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"
// Member 'subtrajectory'
#include "custom_drone_interfaces/msg/detail/sub_waypoint__traits.hpp"
// Member 'task'
#include "custom_drone_interfaces/msg/detail/task_specification__traits.hpp"

namespace custom_drone_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Waypoint & msg,
  std::ostream & out)
{
  out << "{";
  // member: point
  {
    out << "point: ";
    to_flow_style_yaml(msg.point, out);
    out << ", ";
  }

  // member: velocity
  {
    out << "velocity: ";
    to_flow_style_yaml(msg.velocity, out);
    out << ", ";
  }

  // member: subtrajectory
  {
    if (msg.subtrajectory.size() == 0) {
      out << "subtrajectory: []";
    } else {
      out << "subtrajectory: [";
      size_t pending_items = msg.subtrajectory.size();
      for (auto item : msg.subtrajectory) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: stop
  {
    out << "stop: ";
    rosidl_generator_traits::value_to_yaml(msg.stop, out);
    out << ", ";
  }

  // member: heading
  {
    out << "heading: ";
    rosidl_generator_traits::value_to_yaml(msg.heading, out);
    out << ", ";
  }

  // member: time_in_seconds
  {
    out << "time_in_seconds: ";
    rosidl_generator_traits::value_to_yaml(msg.time_in_seconds, out);
    out << ", ";
  }

  // member: hold_time
  {
    out << "hold_time: ";
    rosidl_generator_traits::value_to_yaml(msg.hold_time, out);
    out << ", ";
  }

  // member: acceptence_radius
  {
    out << "acceptence_radius: ";
    rosidl_generator_traits::value_to_yaml(msg.acceptence_radius, out);
    out << ", ";
  }

  // member: task
  {
    out << "task: ";
    to_flow_style_yaml(msg.task, out);
    out << ", ";
  }

  // member: commandid
  {
    if (msg.commandid.size() == 0) {
      out << "commandid: []";
    } else {
      out << "commandid: [";
      size_t pending_items = msg.commandid.size();
      for (auto item : msg.commandid) {
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
  const Waypoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "point:\n";
    to_block_style_yaml(msg.point, out, indentation + 2);
  }

  // member: velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "velocity:\n";
    to_block_style_yaml(msg.velocity, out, indentation + 2);
  }

  // member: subtrajectory
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.subtrajectory.size() == 0) {
      out << "subtrajectory: []\n";
    } else {
      out << "subtrajectory:\n";
      for (auto item : msg.subtrajectory) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: stop
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stop: ";
    rosidl_generator_traits::value_to_yaml(msg.stop, out);
    out << "\n";
  }

  // member: heading
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "heading: ";
    rosidl_generator_traits::value_to_yaml(msg.heading, out);
    out << "\n";
  }

  // member: time_in_seconds
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time_in_seconds: ";
    rosidl_generator_traits::value_to_yaml(msg.time_in_seconds, out);
    out << "\n";
  }

  // member: hold_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hold_time: ";
    rosidl_generator_traits::value_to_yaml(msg.hold_time, out);
    out << "\n";
  }

  // member: acceptence_radius
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "acceptence_radius: ";
    rosidl_generator_traits::value_to_yaml(msg.acceptence_radius, out);
    out << "\n";
  }

  // member: task
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task:\n";
    to_block_style_yaml(msg.task, out, indentation + 2);
  }

  // member: commandid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.commandid.size() == 0) {
      out << "commandid: []\n";
    } else {
      out << "commandid:\n";
      for (auto item : msg.commandid) {
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

inline std::string to_yaml(const Waypoint & msg, bool use_flow_style = false)
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
  const custom_drone_interfaces::msg::Waypoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_drone_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_drone_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_drone_interfaces::msg::Waypoint & msg)
{
  return custom_drone_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_drone_interfaces::msg::Waypoint>()
{
  return "custom_drone_interfaces::msg::Waypoint";
}

template<>
inline const char * name<custom_drone_interfaces::msg::Waypoint>()
{
  return "custom_drone_interfaces/msg/Waypoint";
}

template<>
struct has_fixed_size<custom_drone_interfaces::msg::Waypoint>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_drone_interfaces::msg::Waypoint>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_drone_interfaces::msg::Waypoint>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__WAYPOINT__TRAITS_HPP_
