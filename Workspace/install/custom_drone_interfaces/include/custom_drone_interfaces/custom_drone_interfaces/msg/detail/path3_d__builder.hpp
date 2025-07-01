// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_drone_interfaces:msg/Path3D.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__PATH3_D__BUILDER_HPP_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__PATH3_D__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_drone_interfaces/msg/detail/path3_d__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_drone_interfaces
{

namespace msg
{

namespace builder
{

class Init_Path3D_waypoints
{
public:
  Init_Path3D_waypoints()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_drone_interfaces::msg::Path3D waypoints(::custom_drone_interfaces::msg::Path3D::_waypoints_type arg)
  {
    msg_.waypoints = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_drone_interfaces::msg::Path3D msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_drone_interfaces::msg::Path3D>()
{
  return custom_drone_interfaces::msg::builder::Init_Path3D_waypoints();
}

}  // namespace custom_drone_interfaces

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__PATH3_D__BUILDER_HPP_
