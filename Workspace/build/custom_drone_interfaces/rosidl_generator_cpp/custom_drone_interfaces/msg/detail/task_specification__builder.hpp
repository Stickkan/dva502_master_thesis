// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_drone_interfaces:msg/TaskSpecification.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__TASK_SPECIFICATION__BUILDER_HPP_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__TASK_SPECIFICATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_drone_interfaces/msg/detail/task_specification__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_drone_interfaces
{

namespace msg
{

namespace builder
{

class Init_TaskSpecification_settings
{
public:
  explicit Init_TaskSpecification_settings(::custom_drone_interfaces::msg::TaskSpecification & msg)
  : msg_(msg)
  {}
  ::custom_drone_interfaces::msg::TaskSpecification settings(::custom_drone_interfaces::msg::TaskSpecification::_settings_type arg)
  {
    msg_.settings = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_drone_interfaces::msg::TaskSpecification msg_;
};

class Init_TaskSpecification_flag
{
public:
  Init_TaskSpecification_flag()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TaskSpecification_settings flag(::custom_drone_interfaces::msg::TaskSpecification::_flag_type arg)
  {
    msg_.flag = std::move(arg);
    return Init_TaskSpecification_settings(msg_);
  }

private:
  ::custom_drone_interfaces::msg::TaskSpecification msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_drone_interfaces::msg::TaskSpecification>()
{
  return custom_drone_interfaces::msg::builder::Init_TaskSpecification_flag();
}

}  // namespace custom_drone_interfaces

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__TASK_SPECIFICATION__BUILDER_HPP_
