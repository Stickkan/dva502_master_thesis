// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from custom_drone_interfaces:msg/StatusDataCollection.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "custom_drone_interfaces/msg/detail/status_data_collection__struct.h"
#include "custom_drone_interfaces/msg/detail/status_data_collection__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool custom_drone_interfaces__msg__status_data_collection__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[73];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("custom_drone_interfaces.msg._status_data_collection.StatusDataCollection", full_classname_dest, 72) == 0);
  }
  custom_drone_interfaces__msg__StatusDataCollection * ros_message = _ros_message;
  {  // remaining
    PyObject * field = PyObject_GetAttrString(_pymsg, "remaining");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->remaining = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // time_remaining_s
    PyObject * field = PyObject_GetAttrString(_pymsg, "time_remaining_s");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->time_remaining_s = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // battery_warning
    PyObject * field = PyObject_GetAttrString(_pymsg, "battery_warning");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->battery_warning = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // battery_unhealthy
    PyObject * field = PyObject_GetAttrString(_pymsg, "battery_unhealthy");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->battery_unhealthy = (Py_True == field);
    Py_DECREF(field);
  }
  {  // angular_velocity_invalid
    PyObject * field = PyObject_GetAttrString(_pymsg, "angular_velocity_invalid");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->angular_velocity_invalid = (Py_True == field);
    Py_DECREF(field);
  }
  {  // attitude_invalid
    PyObject * field = PyObject_GetAttrString(_pymsg, "attitude_invalid");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->attitude_invalid = (Py_True == field);
    Py_DECREF(field);
  }
  {  // global_position_invalid
    PyObject * field = PyObject_GetAttrString(_pymsg, "global_position_invalid");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->global_position_invalid = (Py_True == field);
    Py_DECREF(field);
  }
  {  // wind_limit_exceeded
    PyObject * field = PyObject_GetAttrString(_pymsg, "wind_limit_exceeded");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->wind_limit_exceeded = (Py_True == field);
    Py_DECREF(field);
  }
  {  // esc_arming_failure
    PyObject * field = PyObject_GetAttrString(_pymsg, "esc_arming_failure");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->esc_arming_failure = (Py_True == field);
    Py_DECREF(field);
  }
  {  // imbalanced_prop
    PyObject * field = PyObject_GetAttrString(_pymsg, "imbalanced_prop");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->imbalanced_prop = (Py_True == field);
    Py_DECREF(field);
  }
  {  // motor_failure
    PyObject * field = PyObject_GetAttrString(_pymsg, "motor_failure");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->motor_failure = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * custom_drone_interfaces__msg__status_data_collection__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of StatusDataCollection */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("custom_drone_interfaces.msg._status_data_collection");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "StatusDataCollection");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  custom_drone_interfaces__msg__StatusDataCollection * ros_message = (custom_drone_interfaces__msg__StatusDataCollection *)raw_ros_message;
  {  // remaining
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->remaining);
    {
      int rc = PyObject_SetAttrString(_pymessage, "remaining", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // time_remaining_s
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->time_remaining_s);
    {
      int rc = PyObject_SetAttrString(_pymessage, "time_remaining_s", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // battery_warning
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->battery_warning);
    {
      int rc = PyObject_SetAttrString(_pymessage, "battery_warning", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // battery_unhealthy
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->battery_unhealthy ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "battery_unhealthy", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // angular_velocity_invalid
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->angular_velocity_invalid ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "angular_velocity_invalid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // attitude_invalid
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->attitude_invalid ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "attitude_invalid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // global_position_invalid
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->global_position_invalid ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "global_position_invalid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // wind_limit_exceeded
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->wind_limit_exceeded ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "wind_limit_exceeded", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // esc_arming_failure
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->esc_arming_failure ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "esc_arming_failure", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // imbalanced_prop
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->imbalanced_prop ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "imbalanced_prop", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // motor_failure
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->motor_failure ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "motor_failure", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
