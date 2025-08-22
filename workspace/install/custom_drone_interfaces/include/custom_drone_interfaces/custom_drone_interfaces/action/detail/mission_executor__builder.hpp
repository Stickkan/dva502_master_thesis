// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_drone_interfaces:action/MissionExecutor.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__ACTION__DETAIL__MISSION_EXECUTOR__BUILDER_HPP_
#define CUSTOM_DRONE_INTERFACES__ACTION__DETAIL__MISSION_EXECUTOR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_drone_interfaces/action/detail/mission_executor__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_drone_interfaces
{

namespace action
{

namespace builder
{

class Init_MissionExecutor_Goal_mission_goal
{
public:
  Init_MissionExecutor_Goal_mission_goal()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_drone_interfaces::action::MissionExecutor_Goal mission_goal(::custom_drone_interfaces::action::MissionExecutor_Goal::_mission_goal_type arg)
  {
    msg_.mission_goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_drone_interfaces::action::MissionExecutor_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_drone_interfaces::action::MissionExecutor_Goal>()
{
  return custom_drone_interfaces::action::builder::Init_MissionExecutor_Goal_mission_goal();
}

}  // namespace custom_drone_interfaces


namespace custom_drone_interfaces
{

namespace action
{

namespace builder
{

class Init_MissionExecutor_Result_mission_result
{
public:
  Init_MissionExecutor_Result_mission_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_drone_interfaces::action::MissionExecutor_Result mission_result(::custom_drone_interfaces::action::MissionExecutor_Result::_mission_result_type arg)
  {
    msg_.mission_result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_drone_interfaces::action::MissionExecutor_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_drone_interfaces::action::MissionExecutor_Result>()
{
  return custom_drone_interfaces::action::builder::Init_MissionExecutor_Result_mission_result();
}

}  // namespace custom_drone_interfaces


namespace custom_drone_interfaces
{

namespace action
{

namespace builder
{

class Init_MissionExecutor_Feedback_command_id
{
public:
  explicit Init_MissionExecutor_Feedback_command_id(::custom_drone_interfaces::action::MissionExecutor_Feedback & msg)
  : msg_(msg)
  {}
  ::custom_drone_interfaces::action::MissionExecutor_Feedback command_id(::custom_drone_interfaces::action::MissionExecutor_Feedback::_command_id_type arg)
  {
    msg_.command_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_drone_interfaces::action::MissionExecutor_Feedback msg_;
};

class Init_MissionExecutor_Feedback_status_code
{
public:
  explicit Init_MissionExecutor_Feedback_status_code(::custom_drone_interfaces::action::MissionExecutor_Feedback & msg)
  : msg_(msg)
  {}
  Init_MissionExecutor_Feedback_command_id status_code(::custom_drone_interfaces::action::MissionExecutor_Feedback::_status_code_type arg)
  {
    msg_.status_code = std::move(arg);
    return Init_MissionExecutor_Feedback_command_id(msg_);
  }

private:
  ::custom_drone_interfaces::action::MissionExecutor_Feedback msg_;
};

class Init_MissionExecutor_Feedback_mission_feedback
{
public:
  Init_MissionExecutor_Feedback_mission_feedback()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MissionExecutor_Feedback_status_code mission_feedback(::custom_drone_interfaces::action::MissionExecutor_Feedback::_mission_feedback_type arg)
  {
    msg_.mission_feedback = std::move(arg);
    return Init_MissionExecutor_Feedback_status_code(msg_);
  }

private:
  ::custom_drone_interfaces::action::MissionExecutor_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_drone_interfaces::action::MissionExecutor_Feedback>()
{
  return custom_drone_interfaces::action::builder::Init_MissionExecutor_Feedback_mission_feedback();
}

}  // namespace custom_drone_interfaces


namespace custom_drone_interfaces
{

namespace action
{

namespace builder
{

class Init_MissionExecutor_SendGoal_Request_goal
{
public:
  explicit Init_MissionExecutor_SendGoal_Request_goal(::custom_drone_interfaces::action::MissionExecutor_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::custom_drone_interfaces::action::MissionExecutor_SendGoal_Request goal(::custom_drone_interfaces::action::MissionExecutor_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_drone_interfaces::action::MissionExecutor_SendGoal_Request msg_;
};

class Init_MissionExecutor_SendGoal_Request_goal_id
{
public:
  Init_MissionExecutor_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MissionExecutor_SendGoal_Request_goal goal_id(::custom_drone_interfaces::action::MissionExecutor_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MissionExecutor_SendGoal_Request_goal(msg_);
  }

private:
  ::custom_drone_interfaces::action::MissionExecutor_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_drone_interfaces::action::MissionExecutor_SendGoal_Request>()
{
  return custom_drone_interfaces::action::builder::Init_MissionExecutor_SendGoal_Request_goal_id();
}

}  // namespace custom_drone_interfaces


namespace custom_drone_interfaces
{

namespace action
{

namespace builder
{

class Init_MissionExecutor_SendGoal_Response_stamp
{
public:
  explicit Init_MissionExecutor_SendGoal_Response_stamp(::custom_drone_interfaces::action::MissionExecutor_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::custom_drone_interfaces::action::MissionExecutor_SendGoal_Response stamp(::custom_drone_interfaces::action::MissionExecutor_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_drone_interfaces::action::MissionExecutor_SendGoal_Response msg_;
};

class Init_MissionExecutor_SendGoal_Response_accepted
{
public:
  Init_MissionExecutor_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MissionExecutor_SendGoal_Response_stamp accepted(::custom_drone_interfaces::action::MissionExecutor_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_MissionExecutor_SendGoal_Response_stamp(msg_);
  }

private:
  ::custom_drone_interfaces::action::MissionExecutor_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_drone_interfaces::action::MissionExecutor_SendGoal_Response>()
{
  return custom_drone_interfaces::action::builder::Init_MissionExecutor_SendGoal_Response_accepted();
}

}  // namespace custom_drone_interfaces


namespace custom_drone_interfaces
{

namespace action
{

namespace builder
{

class Init_MissionExecutor_GetResult_Request_goal_id
{
public:
  Init_MissionExecutor_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_drone_interfaces::action::MissionExecutor_GetResult_Request goal_id(::custom_drone_interfaces::action::MissionExecutor_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_drone_interfaces::action::MissionExecutor_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_drone_interfaces::action::MissionExecutor_GetResult_Request>()
{
  return custom_drone_interfaces::action::builder::Init_MissionExecutor_GetResult_Request_goal_id();
}

}  // namespace custom_drone_interfaces


namespace custom_drone_interfaces
{

namespace action
{

namespace builder
{

class Init_MissionExecutor_GetResult_Response_result
{
public:
  explicit Init_MissionExecutor_GetResult_Response_result(::custom_drone_interfaces::action::MissionExecutor_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::custom_drone_interfaces::action::MissionExecutor_GetResult_Response result(::custom_drone_interfaces::action::MissionExecutor_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_drone_interfaces::action::MissionExecutor_GetResult_Response msg_;
};

class Init_MissionExecutor_GetResult_Response_status
{
public:
  Init_MissionExecutor_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MissionExecutor_GetResult_Response_result status(::custom_drone_interfaces::action::MissionExecutor_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_MissionExecutor_GetResult_Response_result(msg_);
  }

private:
  ::custom_drone_interfaces::action::MissionExecutor_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_drone_interfaces::action::MissionExecutor_GetResult_Response>()
{
  return custom_drone_interfaces::action::builder::Init_MissionExecutor_GetResult_Response_status();
}

}  // namespace custom_drone_interfaces


namespace custom_drone_interfaces
{

namespace action
{

namespace builder
{

class Init_MissionExecutor_FeedbackMessage_feedback
{
public:
  explicit Init_MissionExecutor_FeedbackMessage_feedback(::custom_drone_interfaces::action::MissionExecutor_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::custom_drone_interfaces::action::MissionExecutor_FeedbackMessage feedback(::custom_drone_interfaces::action::MissionExecutor_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_drone_interfaces::action::MissionExecutor_FeedbackMessage msg_;
};

class Init_MissionExecutor_FeedbackMessage_goal_id
{
public:
  Init_MissionExecutor_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MissionExecutor_FeedbackMessage_feedback goal_id(::custom_drone_interfaces::action::MissionExecutor_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MissionExecutor_FeedbackMessage_feedback(msg_);
  }

private:
  ::custom_drone_interfaces::action::MissionExecutor_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_drone_interfaces::action::MissionExecutor_FeedbackMessage>()
{
  return custom_drone_interfaces::action::builder::Init_MissionExecutor_FeedbackMessage_goal_id();
}

}  // namespace custom_drone_interfaces

#endif  // CUSTOM_DRONE_INTERFACES__ACTION__DETAIL__MISSION_EXECUTOR__BUILDER_HPP_
