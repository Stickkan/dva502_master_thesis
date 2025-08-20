// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_drone_interfaces:msg/AgentsList.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__AGENTS_LIST__BUILDER_HPP_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__AGENTS_LIST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_drone_interfaces/msg/detail/agents_list__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_drone_interfaces
{

namespace msg
{

namespace builder
{

class Init_AgentsList_agents
{
public:
  Init_AgentsList_agents()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_drone_interfaces::msg::AgentsList agents(::custom_drone_interfaces::msg::AgentsList::_agents_type arg)
  {
    msg_.agents = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_drone_interfaces::msg::AgentsList msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_drone_interfaces::msg::AgentsList>()
{
  return custom_drone_interfaces::msg::builder::Init_AgentsList_agents();
}

}  // namespace custom_drone_interfaces

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__AGENTS_LIST__BUILDER_HPP_
