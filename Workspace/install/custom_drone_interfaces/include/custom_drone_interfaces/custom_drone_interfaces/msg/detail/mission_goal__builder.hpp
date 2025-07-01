// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_drone_interfaces:msg/MissionGoal.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_GOAL__BUILDER_HPP_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_GOAL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_drone_interfaces/msg/detail/mission_goal__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_drone_interfaces
{

namespace msg
{

namespace builder
{

class Init_MissionGoal_json_mission_data
{
public:
  Init_MissionGoal_json_mission_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_drone_interfaces::msg::MissionGoal json_mission_data(::custom_drone_interfaces::msg::MissionGoal::_json_mission_data_type arg)
  {
    msg_.json_mission_data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_drone_interfaces::msg::MissionGoal msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_drone_interfaces::msg::MissionGoal>()
{
  return custom_drone_interfaces::msg::builder::Init_MissionGoal_json_mission_data();
}

}  // namespace custom_drone_interfaces

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__MISSION_GOAL__BUILDER_HPP_
