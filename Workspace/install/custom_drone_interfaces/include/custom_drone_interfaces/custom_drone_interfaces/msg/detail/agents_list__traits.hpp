// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_drone_interfaces:msg/AgentsList.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__AGENTS_LIST__TRAITS_HPP_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__AGENTS_LIST__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_drone_interfaces/msg/detail/agents_list__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'agents'
#include "custom_drone_interfaces/msg/detail/agent_data__traits.hpp"

namespace custom_drone_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const AgentsList & msg,
  std::ostream & out)
{
  out << "{";
  // member: agents
  {
    if (msg.agents.size() == 0) {
      out << "agents: []";
    } else {
      out << "agents: [";
      size_t pending_items = msg.agents.size();
      for (auto item : msg.agents) {
        to_flow_style_yaml(item, out);
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
  const AgentsList & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: agents
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.agents.size() == 0) {
      out << "agents: []\n";
    } else {
      out << "agents:\n";
      for (auto item : msg.agents) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AgentsList & msg, bool use_flow_style = false)
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
  const custom_drone_interfaces::msg::AgentsList & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_drone_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_drone_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_drone_interfaces::msg::AgentsList & msg)
{
  return custom_drone_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_drone_interfaces::msg::AgentsList>()
{
  return "custom_drone_interfaces::msg::AgentsList";
}

template<>
inline const char * name<custom_drone_interfaces::msg::AgentsList>()
{
  return "custom_drone_interfaces/msg/AgentsList";
}

template<>
struct has_fixed_size<custom_drone_interfaces::msg::AgentsList>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_drone_interfaces::msg::AgentsList>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_drone_interfaces::msg::AgentsList>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__AGENTS_LIST__TRAITS_HPP_
