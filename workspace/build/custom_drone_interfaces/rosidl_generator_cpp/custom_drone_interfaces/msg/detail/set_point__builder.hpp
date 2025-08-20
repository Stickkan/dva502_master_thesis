// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_drone_interfaces:msg/SetPoint.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__SET_POINT__BUILDER_HPP_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__SET_POINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_drone_interfaces/msg/detail/set_point__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_drone_interfaces
{

namespace msg
{

namespace builder
{

class Init_SetPoint_r_t_f
{
public:
  explicit Init_SetPoint_r_t_f(::custom_drone_interfaces::msg::SetPoint & msg)
  : msg_(msg)
  {}
  ::custom_drone_interfaces::msg::SetPoint r_t_f(::custom_drone_interfaces::msg::SetPoint::_r_t_f_type arg)
  {
    msg_.r_t_f = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_drone_interfaces::msg::SetPoint msg_;
};

class Init_SetPoint_frequency
{
public:
  explicit Init_SetPoint_frequency(::custom_drone_interfaces::msg::SetPoint & msg)
  : msg_(msg)
  {}
  Init_SetPoint_r_t_f frequency(::custom_drone_interfaces::msg::SetPoint::_frequency_type arg)
  {
    msg_.frequency = std::move(arg);
    return Init_SetPoint_r_t_f(msg_);
  }

private:
  ::custom_drone_interfaces::msg::SetPoint msg_;
};

class Init_SetPoint_setpoint_data
{
public:
  Init_SetPoint_setpoint_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetPoint_frequency setpoint_data(::custom_drone_interfaces::msg::SetPoint::_setpoint_data_type arg)
  {
    msg_.setpoint_data = std::move(arg);
    return Init_SetPoint_frequency(msg_);
  }

private:
  ::custom_drone_interfaces::msg::SetPoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_drone_interfaces::msg::SetPoint>()
{
  return custom_drone_interfaces::msg::builder::Init_SetPoint_setpoint_data();
}

}  // namespace custom_drone_interfaces

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__SET_POINT__BUILDER_HPP_
