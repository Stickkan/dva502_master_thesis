// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_drone_interfaces:msg/MissionFeedback.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_FEEDBACK__BUILDER_HPP_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_FEEDBACK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_drone_interfaces/msg/detail/mission_feedback__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_drone_interfaces
{

namespace msg
{

namespace builder
{

class Init_MissionFeedback_feedback_message
{
public:
  Init_MissionFeedback_feedback_message()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_drone_interfaces::msg::MissionFeedback feedback_message(::custom_drone_interfaces::msg::MissionFeedback::_feedback_message_type arg)
  {
    msg_.feedback_message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_drone_interfaces::msg::MissionFeedback msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_drone_interfaces::msg::MissionFeedback>()
{
  return custom_drone_interfaces::msg::builder::Init_MissionFeedback_feedback_message();
}

}  // namespace custom_drone_interfaces

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_FEEDBACK__BUILDER_HPP_
