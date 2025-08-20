# generated from rosidl_generator_py/resource/_idl.py.em
# with input from custom_drone_interfaces:msg/StatusDataCollection.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_StatusDataCollection(type):
    """Metaclass of message 'StatusDataCollection'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('custom_drone_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'custom_drone_interfaces.msg.StatusDataCollection')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__status_data_collection
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__status_data_collection
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__status_data_collection
            cls._TYPE_SUPPORT = module.type_support_msg__msg__status_data_collection
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__status_data_collection

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class StatusDataCollection(metaclass=Metaclass_StatusDataCollection):
    """Message class 'StatusDataCollection'."""

    __slots__ = [
        '_remaining',
        '_time_remaining_s',
        '_battery_warning',
        '_battery_unhealthy',
        '_angular_velocity_invalid',
        '_attitude_invalid',
        '_global_position_invalid',
        '_wind_limit_exceeded',
        '_esc_arming_failure',
        '_imbalanced_prop',
        '_motor_failure',
    ]

    _fields_and_field_types = {
        'remaining': 'float',
        'time_remaining_s': 'float',
        'battery_warning': 'uint8',
        'battery_unhealthy': 'boolean',
        'angular_velocity_invalid': 'boolean',
        'attitude_invalid': 'boolean',
        'global_position_invalid': 'boolean',
        'wind_limit_exceeded': 'boolean',
        'esc_arming_failure': 'boolean',
        'imbalanced_prop': 'boolean',
        'motor_failure': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.remaining = kwargs.get('remaining', float())
        self.time_remaining_s = kwargs.get('time_remaining_s', float())
        self.battery_warning = kwargs.get('battery_warning', int())
        self.battery_unhealthy = kwargs.get('battery_unhealthy', bool())
        self.angular_velocity_invalid = kwargs.get('angular_velocity_invalid', bool())
        self.attitude_invalid = kwargs.get('attitude_invalid', bool())
        self.global_position_invalid = kwargs.get('global_position_invalid', bool())
        self.wind_limit_exceeded = kwargs.get('wind_limit_exceeded', bool())
        self.esc_arming_failure = kwargs.get('esc_arming_failure', bool())
        self.imbalanced_prop = kwargs.get('imbalanced_prop', bool())
        self.motor_failure = kwargs.get('motor_failure', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.remaining != other.remaining:
            return False
        if self.time_remaining_s != other.time_remaining_s:
            return False
        if self.battery_warning != other.battery_warning:
            return False
        if self.battery_unhealthy != other.battery_unhealthy:
            return False
        if self.angular_velocity_invalid != other.angular_velocity_invalid:
            return False
        if self.attitude_invalid != other.attitude_invalid:
            return False
        if self.global_position_invalid != other.global_position_invalid:
            return False
        if self.wind_limit_exceeded != other.wind_limit_exceeded:
            return False
        if self.esc_arming_failure != other.esc_arming_failure:
            return False
        if self.imbalanced_prop != other.imbalanced_prop:
            return False
        if self.motor_failure != other.motor_failure:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def remaining(self):
        """Message field 'remaining'."""
        return self._remaining

    @remaining.setter
    def remaining(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'remaining' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'remaining' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._remaining = value

    @builtins.property
    def time_remaining_s(self):
        """Message field 'time_remaining_s'."""
        return self._time_remaining_s

    @time_remaining_s.setter
    def time_remaining_s(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'time_remaining_s' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'time_remaining_s' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._time_remaining_s = value

    @builtins.property
    def battery_warning(self):
        """Message field 'battery_warning'."""
        return self._battery_warning

    @battery_warning.setter
    def battery_warning(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'battery_warning' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'battery_warning' field must be an unsigned integer in [0, 255]"
        self._battery_warning = value

    @builtins.property
    def battery_unhealthy(self):
        """Message field 'battery_unhealthy'."""
        return self._battery_unhealthy

    @battery_unhealthy.setter
    def battery_unhealthy(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'battery_unhealthy' field must be of type 'bool'"
        self._battery_unhealthy = value

    @builtins.property
    def angular_velocity_invalid(self):
        """Message field 'angular_velocity_invalid'."""
        return self._angular_velocity_invalid

    @angular_velocity_invalid.setter
    def angular_velocity_invalid(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'angular_velocity_invalid' field must be of type 'bool'"
        self._angular_velocity_invalid = value

    @builtins.property
    def attitude_invalid(self):
        """Message field 'attitude_invalid'."""
        return self._attitude_invalid

    @attitude_invalid.setter
    def attitude_invalid(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'attitude_invalid' field must be of type 'bool'"
        self._attitude_invalid = value

    @builtins.property
    def global_position_invalid(self):
        """Message field 'global_position_invalid'."""
        return self._global_position_invalid

    @global_position_invalid.setter
    def global_position_invalid(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'global_position_invalid' field must be of type 'bool'"
        self._global_position_invalid = value

    @builtins.property
    def wind_limit_exceeded(self):
        """Message field 'wind_limit_exceeded'."""
        return self._wind_limit_exceeded

    @wind_limit_exceeded.setter
    def wind_limit_exceeded(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'wind_limit_exceeded' field must be of type 'bool'"
        self._wind_limit_exceeded = value

    @builtins.property
    def esc_arming_failure(self):
        """Message field 'esc_arming_failure'."""
        return self._esc_arming_failure

    @esc_arming_failure.setter
    def esc_arming_failure(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'esc_arming_failure' field must be of type 'bool'"
        self._esc_arming_failure = value

    @builtins.property
    def imbalanced_prop(self):
        """Message field 'imbalanced_prop'."""
        return self._imbalanced_prop

    @imbalanced_prop.setter
    def imbalanced_prop(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'imbalanced_prop' field must be of type 'bool'"
        self._imbalanced_prop = value

    @builtins.property
    def motor_failure(self):
        """Message field 'motor_failure'."""
        return self._motor_failure

    @motor_failure.setter
    def motor_failure(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'motor_failure' field must be of type 'bool'"
        self._motor_failure = value
