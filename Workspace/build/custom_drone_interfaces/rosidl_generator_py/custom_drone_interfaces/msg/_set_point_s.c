// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from custom_drone_interfaces:msg/SetPoint.idl
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
#include "custom_drone_interfaces/msg/detail/set_point__struct.h"
#include "custom_drone_interfaces/msg/detail/set_point__functions.h"

bool custom_drone_interfaces__msg__sub_waypoint__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * custom_drone_interfaces__msg__sub_waypoint__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool custom_drone_interfaces__msg__set_point__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[48];
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
    assert(strncmp("custom_drone_interfaces.msg._set_point.SetPoint", full_classname_dest, 47) == 0);
  }
  custom_drone_interfaces__msg__SetPoint * ros_message = _ros_message;
  {  // setpoint_data
    PyObject * field = PyObject_GetAttrString(_pymsg, "setpoint_data");
    if (!field) {
      return false;
    }
    if (!custom_drone_interfaces__msg__sub_waypoint__convert_from_py(field, &ros_message->setpoint_data)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // frequency
    PyObject * field = PyObject_GetAttrString(_pymsg, "frequency");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->frequency = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // r_t_f
    PyObject * field = PyObject_GetAttrString(_pymsg, "r_t_f");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->r_t_f = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * custom_drone_interfaces__msg__set_point__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SetPoint */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("custom_drone_interfaces.msg._set_point");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SetPoint");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  custom_drone_interfaces__msg__SetPoint * ros_message = (custom_drone_interfaces__msg__SetPoint *)raw_ros_message;
  {  // setpoint_data
    PyObject * field = NULL;
    field = custom_drone_interfaces__msg__sub_waypoint__convert_to_py(&ros_message->setpoint_data);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "setpoint_data", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // frequency
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->frequency);
    {
      int rc = PyObject_SetAttrString(_pymessage, "frequency", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // r_t_f
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->r_t_f ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "r_t_f", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
