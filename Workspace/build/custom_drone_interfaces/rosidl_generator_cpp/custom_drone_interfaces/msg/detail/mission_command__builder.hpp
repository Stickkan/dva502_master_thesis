// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_drone_interfaces:msg/MissionCommand.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_COMMAND__BUILDER_HPP_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_drone_interfaces/msg/detail/mission_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_drone_interfaces
{

namespace msg
{

namespace builder
{

class Init_MissionCommand_command_flag
{
public:
  Init_MissionCommand_command_flag()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_drone_interfaces::msg::MissionCommand command_flag(::custom_drone_interfaces::msg::MissionCommand::_command_flag_type arg)
  {
    msg_.command_flag = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_drone_interfaces::msg::MissionCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_drone_interfaces::msg::MissionCommand>()
{
  return custom_drone_interfaces::msg::builder::Init_MissionCommand_command_flag();
}

}  // namespace custom_drone_interfaces

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_COMMAND__BUILDER_HPP_
