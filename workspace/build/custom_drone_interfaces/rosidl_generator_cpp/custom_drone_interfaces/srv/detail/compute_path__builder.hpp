// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_drone_interfaces:srv/ComputePath.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__SRV__DETAIL__COMPUTE_PATH__BUILDER_HPP_
#define CUSTOM_DRONE_INTERFACES__SRV__DETAIL__COMPUTE_PATH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_drone_interfaces/srv/detail/compute_path__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_drone_interfaces
{

namespace srv
{

namespace builder
{

class Init_ComputePath_Request_planning_method
{
public:
  explicit Init_ComputePath_Request_planning_method(::custom_drone_interfaces::srv::ComputePath_Request & msg)
  : msg_(msg)
  {}
  ::custom_drone_interfaces::srv::ComputePath_Request planning_method(::custom_drone_interfaces::srv::ComputePath_Request::_planning_method_type arg)
  {
    msg_.planning_method = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_drone_interfaces::srv::ComputePath_Request msg_;
};

class Init_ComputePath_Request_acceleration_limit
{
public:
  explicit Init_ComputePath_Request_acceleration_limit(::custom_drone_interfaces::srv::ComputePath_Request & msg)
  : msg_(msg)
  {}
  Init_ComputePath_Request_planning_method acceleration_limit(::custom_drone_interfaces::srv::ComputePath_Request::_acceleration_limit_type arg)
  {
    msg_.acceleration_limit = std::move(arg);
    return Init_ComputePath_Request_planning_method(msg_);
  }

private:
  ::custom_drone_interfaces::srv::ComputePath_Request msg_;
};

class Init_ComputePath_Request_velocity_limit
{
public:
  explicit Init_ComputePath_Request_velocity_limit(::custom_drone_interfaces::srv::ComputePath_Request & msg)
  : msg_(msg)
  {}
  Init_ComputePath_Request_acceleration_limit velocity_limit(::custom_drone_interfaces::srv::ComputePath_Request::_velocity_limit_type arg)
  {
    msg_.velocity_limit = std::move(arg);
    return Init_ComputePath_Request_acceleration_limit(msg_);
  }

private:
  ::custom_drone_interfaces::srv::ComputePath_Request msg_;
};

class Init_ComputePath_Request_input_path
{
public:
  Init_ComputePath_Request_input_path()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ComputePath_Request_velocity_limit input_path(::custom_drone_interfaces::srv::ComputePath_Request::_input_path_type arg)
  {
    msg_.input_path = std::move(arg);
    return Init_ComputePath_Request_velocity_limit(msg_);
  }

private:
  ::custom_drone_interfaces::srv::ComputePath_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_drone_interfaces::srv::ComputePath_Request>()
{
  return custom_drone_interfaces::srv::builder::Init_ComputePath_Request_input_path();
}

}  // namespace custom_drone_interfaces


namespace custom_drone_interfaces
{

namespace srv
{

namespace builder
{

class Init_ComputePath_Response_planned_path
{
public:
  Init_ComputePath_Response_planned_path()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_drone_interfaces::srv::ComputePath_Response planned_path(::custom_drone_interfaces::srv::ComputePath_Response::_planned_path_type arg)
  {
    msg_.planned_path = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_drone_interfaces::srv::ComputePath_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_drone_interfaces::srv::ComputePath_Response>()
{
  return custom_drone_interfaces::srv::builder::Init_ComputePath_Response_planned_path();
}

}  // namespace custom_drone_interfaces

#endif  // CUSTOM_DRONE_INTERFACES__SRV__DETAIL__COMPUTE_PATH__BUILDER_HPP_
