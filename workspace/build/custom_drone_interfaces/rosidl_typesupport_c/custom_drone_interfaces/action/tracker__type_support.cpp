// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from custom_drone_interfaces:action/Tracker.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "custom_drone_interfaces/action/detail/tracker__struct.h"
#include "custom_drone_interfaces/action/detail/tracker__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace custom_drone_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Tracker_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Tracker_Goal_type_support_ids_t;

static const _Tracker_Goal_type_support_ids_t _Tracker_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Tracker_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Tracker_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Tracker_Goal_type_support_symbol_names_t _Tracker_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_drone_interfaces, action, Tracker_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_drone_interfaces, action, Tracker_Goal)),
  }
};

typedef struct _Tracker_Goal_type_support_data_t
{
  void * data[2];
} _Tracker_Goal_type_support_data_t;

static _Tracker_Goal_type_support_data_t _Tracker_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Tracker_Goal_message_typesupport_map = {
  2,
  "custom_drone_interfaces",
  &_Tracker_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_Tracker_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_Tracker_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Tracker_Goal_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Tracker_Goal_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace custom_drone_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, custom_drone_interfaces, action, Tracker_Goal)() {
  return &::custom_drone_interfaces::action::rosidl_typesupport_c::Tracker_Goal_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "custom_drone_interfaces/action/detail/tracker__struct.h"
// already included above
// #include "custom_drone_interfaces/action/detail/tracker__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace custom_drone_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Tracker_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Tracker_Result_type_support_ids_t;

static const _Tracker_Result_type_support_ids_t _Tracker_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Tracker_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Tracker_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Tracker_Result_type_support_symbol_names_t _Tracker_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_drone_interfaces, action, Tracker_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_drone_interfaces, action, Tracker_Result)),
  }
};

typedef struct _Tracker_Result_type_support_data_t
{
  void * data[2];
} _Tracker_Result_type_support_data_t;

static _Tracker_Result_type_support_data_t _Tracker_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Tracker_Result_message_typesupport_map = {
  2,
  "custom_drone_interfaces",
  &_Tracker_Result_message_typesupport_ids.typesupport_identifier[0],
  &_Tracker_Result_message_typesupport_symbol_names.symbol_name[0],
  &_Tracker_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Tracker_Result_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Tracker_Result_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace custom_drone_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, custom_drone_interfaces, action, Tracker_Result)() {
  return &::custom_drone_interfaces::action::rosidl_typesupport_c::Tracker_Result_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "custom_drone_interfaces/action/detail/tracker__struct.h"
// already included above
// #include "custom_drone_interfaces/action/detail/tracker__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace custom_drone_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Tracker_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Tracker_Feedback_type_support_ids_t;

static const _Tracker_Feedback_type_support_ids_t _Tracker_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Tracker_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Tracker_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Tracker_Feedback_type_support_symbol_names_t _Tracker_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_drone_interfaces, action, Tracker_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_drone_interfaces, action, Tracker_Feedback)),
  }
};

typedef struct _Tracker_Feedback_type_support_data_t
{
  void * data[2];
} _Tracker_Feedback_type_support_data_t;

static _Tracker_Feedback_type_support_data_t _Tracker_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Tracker_Feedback_message_typesupport_map = {
  2,
  "custom_drone_interfaces",
  &_Tracker_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_Tracker_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_Tracker_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Tracker_Feedback_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Tracker_Feedback_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace custom_drone_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, custom_drone_interfaces, action, Tracker_Feedback)() {
  return &::custom_drone_interfaces::action::rosidl_typesupport_c::Tracker_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "custom_drone_interfaces/action/detail/tracker__struct.h"
// already included above
// #include "custom_drone_interfaces/action/detail/tracker__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace custom_drone_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Tracker_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Tracker_SendGoal_Request_type_support_ids_t;

static const _Tracker_SendGoal_Request_type_support_ids_t _Tracker_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Tracker_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Tracker_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Tracker_SendGoal_Request_type_support_symbol_names_t _Tracker_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_drone_interfaces, action, Tracker_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_drone_interfaces, action, Tracker_SendGoal_Request)),
  }
};

typedef struct _Tracker_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _Tracker_SendGoal_Request_type_support_data_t;

static _Tracker_SendGoal_Request_type_support_data_t _Tracker_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Tracker_SendGoal_Request_message_typesupport_map = {
  2,
  "custom_drone_interfaces",
  &_Tracker_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Tracker_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Tracker_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Tracker_SendGoal_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Tracker_SendGoal_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace custom_drone_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, custom_drone_interfaces, action, Tracker_SendGoal_Request)() {
  return &::custom_drone_interfaces::action::rosidl_typesupport_c::Tracker_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "custom_drone_interfaces/action/detail/tracker__struct.h"
// already included above
// #include "custom_drone_interfaces/action/detail/tracker__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace custom_drone_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Tracker_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Tracker_SendGoal_Response_type_support_ids_t;

static const _Tracker_SendGoal_Response_type_support_ids_t _Tracker_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Tracker_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Tracker_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Tracker_SendGoal_Response_type_support_symbol_names_t _Tracker_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_drone_interfaces, action, Tracker_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_drone_interfaces, action, Tracker_SendGoal_Response)),
  }
};

typedef struct _Tracker_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _Tracker_SendGoal_Response_type_support_data_t;

static _Tracker_SendGoal_Response_type_support_data_t _Tracker_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Tracker_SendGoal_Response_message_typesupport_map = {
  2,
  "custom_drone_interfaces",
  &_Tracker_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Tracker_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Tracker_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Tracker_SendGoal_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Tracker_SendGoal_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace custom_drone_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, custom_drone_interfaces, action, Tracker_SendGoal_Response)() {
  return &::custom_drone_interfaces::action::rosidl_typesupport_c::Tracker_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "custom_drone_interfaces/action/detail/tracker__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace custom_drone_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Tracker_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Tracker_SendGoal_type_support_ids_t;

static const _Tracker_SendGoal_type_support_ids_t _Tracker_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Tracker_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Tracker_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Tracker_SendGoal_type_support_symbol_names_t _Tracker_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_drone_interfaces, action, Tracker_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_drone_interfaces, action, Tracker_SendGoal)),
  }
};

typedef struct _Tracker_SendGoal_type_support_data_t
{
  void * data[2];
} _Tracker_SendGoal_type_support_data_t;

static _Tracker_SendGoal_type_support_data_t _Tracker_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Tracker_SendGoal_service_typesupport_map = {
  2,
  "custom_drone_interfaces",
  &_Tracker_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_Tracker_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_Tracker_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Tracker_SendGoal_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Tracker_SendGoal_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace custom_drone_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, custom_drone_interfaces, action, Tracker_SendGoal)() {
  return &::custom_drone_interfaces::action::rosidl_typesupport_c::Tracker_SendGoal_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "custom_drone_interfaces/action/detail/tracker__struct.h"
// already included above
// #include "custom_drone_interfaces/action/detail/tracker__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace custom_drone_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Tracker_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Tracker_GetResult_Request_type_support_ids_t;

static const _Tracker_GetResult_Request_type_support_ids_t _Tracker_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Tracker_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Tracker_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Tracker_GetResult_Request_type_support_symbol_names_t _Tracker_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_drone_interfaces, action, Tracker_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_drone_interfaces, action, Tracker_GetResult_Request)),
  }
};

typedef struct _Tracker_GetResult_Request_type_support_data_t
{
  void * data[2];
} _Tracker_GetResult_Request_type_support_data_t;

static _Tracker_GetResult_Request_type_support_data_t _Tracker_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Tracker_GetResult_Request_message_typesupport_map = {
  2,
  "custom_drone_interfaces",
  &_Tracker_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Tracker_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Tracker_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Tracker_GetResult_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Tracker_GetResult_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace custom_drone_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, custom_drone_interfaces, action, Tracker_GetResult_Request)() {
  return &::custom_drone_interfaces::action::rosidl_typesupport_c::Tracker_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "custom_drone_interfaces/action/detail/tracker__struct.h"
// already included above
// #include "custom_drone_interfaces/action/detail/tracker__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace custom_drone_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Tracker_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Tracker_GetResult_Response_type_support_ids_t;

static const _Tracker_GetResult_Response_type_support_ids_t _Tracker_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Tracker_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Tracker_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Tracker_GetResult_Response_type_support_symbol_names_t _Tracker_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_drone_interfaces, action, Tracker_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_drone_interfaces, action, Tracker_GetResult_Response)),
  }
};

typedef struct _Tracker_GetResult_Response_type_support_data_t
{
  void * data[2];
} _Tracker_GetResult_Response_type_support_data_t;

static _Tracker_GetResult_Response_type_support_data_t _Tracker_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Tracker_GetResult_Response_message_typesupport_map = {
  2,
  "custom_drone_interfaces",
  &_Tracker_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Tracker_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Tracker_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Tracker_GetResult_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Tracker_GetResult_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace custom_drone_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, custom_drone_interfaces, action, Tracker_GetResult_Response)() {
  return &::custom_drone_interfaces::action::rosidl_typesupport_c::Tracker_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "custom_drone_interfaces/action/detail/tracker__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace custom_drone_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Tracker_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Tracker_GetResult_type_support_ids_t;

static const _Tracker_GetResult_type_support_ids_t _Tracker_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Tracker_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Tracker_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Tracker_GetResult_type_support_symbol_names_t _Tracker_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_drone_interfaces, action, Tracker_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_drone_interfaces, action, Tracker_GetResult)),
  }
};

typedef struct _Tracker_GetResult_type_support_data_t
{
  void * data[2];
} _Tracker_GetResult_type_support_data_t;

static _Tracker_GetResult_type_support_data_t _Tracker_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Tracker_GetResult_service_typesupport_map = {
  2,
  "custom_drone_interfaces",
  &_Tracker_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_Tracker_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_Tracker_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Tracker_GetResult_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Tracker_GetResult_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace custom_drone_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, custom_drone_interfaces, action, Tracker_GetResult)() {
  return &::custom_drone_interfaces::action::rosidl_typesupport_c::Tracker_GetResult_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "custom_drone_interfaces/action/detail/tracker__struct.h"
// already included above
// #include "custom_drone_interfaces/action/detail/tracker__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace custom_drone_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Tracker_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Tracker_FeedbackMessage_type_support_ids_t;

static const _Tracker_FeedbackMessage_type_support_ids_t _Tracker_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Tracker_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Tracker_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Tracker_FeedbackMessage_type_support_symbol_names_t _Tracker_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_drone_interfaces, action, Tracker_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_drone_interfaces, action, Tracker_FeedbackMessage)),
  }
};

typedef struct _Tracker_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _Tracker_FeedbackMessage_type_support_data_t;

static _Tracker_FeedbackMessage_type_support_data_t _Tracker_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Tracker_FeedbackMessage_message_typesupport_map = {
  2,
  "custom_drone_interfaces",
  &_Tracker_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_Tracker_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_Tracker_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Tracker_FeedbackMessage_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Tracker_FeedbackMessage_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace custom_drone_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, custom_drone_interfaces, action, Tracker_FeedbackMessage)() {
  return &::custom_drone_interfaces::action::rosidl_typesupport_c::Tracker_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "action_msgs/msg/goal_status_array.h"
#include "action_msgs/srv/cancel_goal.h"
#include "custom_drone_interfaces/action/tracker.h"
// already included above
// #include "custom_drone_interfaces/action/detail/tracker__type_support.h"

static rosidl_action_type_support_t _custom_drone_interfaces__action__Tracker__typesupport_c;

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(
  rosidl_typesupport_c, custom_drone_interfaces, action, Tracker)()
{
  // Thread-safe by always writing the same values to the static struct
  _custom_drone_interfaces__action__Tracker__typesupport_c.goal_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, custom_drone_interfaces, action, Tracker_SendGoal)();
  _custom_drone_interfaces__action__Tracker__typesupport_c.result_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, custom_drone_interfaces, action, Tracker_GetResult)();
  _custom_drone_interfaces__action__Tracker__typesupport_c.cancel_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, srv, CancelGoal)();
  _custom_drone_interfaces__action__Tracker__typesupport_c.feedback_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, custom_drone_interfaces, action, Tracker_FeedbackMessage)();
  _custom_drone_interfaces__action__Tracker__typesupport_c.status_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, msg, GoalStatusArray)();

  return &_custom_drone_interfaces__action__Tracker__typesupport_c;
}

#ifdef __cplusplus
}
#endif
