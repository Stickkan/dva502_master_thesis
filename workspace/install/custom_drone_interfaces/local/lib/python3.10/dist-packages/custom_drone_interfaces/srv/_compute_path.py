# generated from rosidl_generator_py/resource/_idl.py.em
# with input from custom_drone_interfaces:srv/ComputePath.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

# Member 'velocity_limit'
# Member 'acceleration_limit'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ComputePath_Request(type):
    """Metaclass of message 'ComputePath_Request'."""

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
                'custom_drone_interfaces.srv.ComputePath_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__compute_path__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__compute_path__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__compute_path__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__compute_path__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__compute_path__request

            from custom_drone_interfaces.msg import Path3D
            if Path3D.__class__._TYPE_SUPPORT is None:
                Path3D.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ComputePath_Request(metaclass=Metaclass_ComputePath_Request):
    """Message class 'ComputePath_Request'."""

    __slots__ = [
        '_input_path',
        '_velocity_limit',
        '_acceleration_limit',
        '_planning_method',
    ]

    _fields_and_field_types = {
        'input_path': 'custom_drone_interfaces/Path3D',
        'velocity_limit': 'double[3]',
        'acceleration_limit': 'double[3]',
        'planning_method': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['custom_drone_interfaces', 'msg'], 'Path3D'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 3),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 3),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from custom_drone_interfaces.msg import Path3D
        self.input_path = kwargs.get('input_path', Path3D())
        if 'velocity_limit' not in kwargs:
            self.velocity_limit = numpy.zeros(3, dtype=numpy.float64)
        else:
            self.velocity_limit = numpy.array(kwargs.get('velocity_limit'), dtype=numpy.float64)
            assert self.velocity_limit.shape == (3, )
        if 'acceleration_limit' not in kwargs:
            self.acceleration_limit = numpy.zeros(3, dtype=numpy.float64)
        else:
            self.acceleration_limit = numpy.array(kwargs.get('acceleration_limit'), dtype=numpy.float64)
            assert self.acceleration_limit.shape == (3, )
        self.planning_method = kwargs.get('planning_method', str())

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
        if self.input_path != other.input_path:
            return False
        if all(self.velocity_limit != other.velocity_limit):
            return False
        if all(self.acceleration_limit != other.acceleration_limit):
            return False
        if self.planning_method != other.planning_method:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def input_path(self):
        """Message field 'input_path'."""
        return self._input_path

    @input_path.setter
    def input_path(self, value):
        if __debug__:
            from custom_drone_interfaces.msg import Path3D
            assert \
                isinstance(value, Path3D), \
                "The 'input_path' field must be a sub message of type 'Path3D'"
        self._input_path = value

    @builtins.property
    def velocity_limit(self):
        """Message field 'velocity_limit'."""
        return self._velocity_limit

    @velocity_limit.setter
    def velocity_limit(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'velocity_limit' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 3, \
                "The 'velocity_limit' numpy.ndarray() must have a size of 3"
            self._velocity_limit = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 3 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'velocity_limit' field must be a set or sequence with length 3 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._velocity_limit = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def acceleration_limit(self):
        """Message field 'acceleration_limit'."""
        return self._acceleration_limit

    @acceleration_limit.setter
    def acceleration_limit(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'acceleration_limit' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 3, \
                "The 'acceleration_limit' numpy.ndarray() must have a size of 3"
            self._acceleration_limit = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 3 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'acceleration_limit' field must be a set or sequence with length 3 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._acceleration_limit = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def planning_method(self):
        """Message field 'planning_method'."""
        return self._planning_method

    @planning_method.setter
    def planning_method(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'planning_method' field must be of type 'str'"
        self._planning_method = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ComputePath_Response(type):
    """Metaclass of message 'ComputePath_Response'."""

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
                'custom_drone_interfaces.srv.ComputePath_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__compute_path__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__compute_path__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__compute_path__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__compute_path__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__compute_path__response

            from custom_drone_interfaces.msg import Path3D
            if Path3D.__class__._TYPE_SUPPORT is None:
                Path3D.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ComputePath_Response(metaclass=Metaclass_ComputePath_Response):
    """Message class 'ComputePath_Response'."""

    __slots__ = [
        '_planned_path',
    ]

    _fields_and_field_types = {
        'planned_path': 'custom_drone_interfaces/Path3D',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['custom_drone_interfaces', 'msg'], 'Path3D'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from custom_drone_interfaces.msg import Path3D
        self.planned_path = kwargs.get('planned_path', Path3D())

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
        if self.planned_path != other.planned_path:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def planned_path(self):
        """Message field 'planned_path'."""
        return self._planned_path

    @planned_path.setter
    def planned_path(self, value):
        if __debug__:
            from custom_drone_interfaces.msg import Path3D
            assert \
                isinstance(value, Path3D), \
                "The 'planned_path' field must be a sub message of type 'Path3D'"
        self._planned_path = value


class Metaclass_ComputePath(type):
    """Metaclass of service 'ComputePath'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('custom_drone_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'custom_drone_interfaces.srv.ComputePath')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__compute_path

            from custom_drone_interfaces.srv import _compute_path
            if _compute_path.Metaclass_ComputePath_Request._TYPE_SUPPORT is None:
                _compute_path.Metaclass_ComputePath_Request.__import_type_support__()
            if _compute_path.Metaclass_ComputePath_Response._TYPE_SUPPORT is None:
                _compute_path.Metaclass_ComputePath_Response.__import_type_support__()


class ComputePath(metaclass=Metaclass_ComputePath):
    from custom_drone_interfaces.srv._compute_path import ComputePath_Request as Request
    from custom_drone_interfaces.srv._compute_path import ComputePath_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
