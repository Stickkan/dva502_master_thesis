# generated from rosidl_generator_py/resource/_idl.py.em
# with input from custom_drone_interfaces:action/MissionExecutor.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MissionExecutor_Goal(type):
    """Metaclass of message 'MissionExecutor_Goal'."""

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
                'custom_drone_interfaces.action.MissionExecutor_Goal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__mission_executor__goal
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__mission_executor__goal
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__mission_executor__goal
            cls._TYPE_SUPPORT = module.type_support_msg__action__mission_executor__goal
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__mission_executor__goal

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MissionExecutor_Goal(metaclass=Metaclass_MissionExecutor_Goal):
    """Message class 'MissionExecutor_Goal'."""

    __slots__ = [
        '_mission_goal',
    ]

    _fields_and_field_types = {
        'mission_goal': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.mission_goal = kwargs.get('mission_goal', str())

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
        if self.mission_goal != other.mission_goal:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def mission_goal(self):
        """Message field 'mission_goal'."""
        return self._mission_goal

    @mission_goal.setter
    def mission_goal(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'mission_goal' field must be of type 'str'"
        self._mission_goal = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_MissionExecutor_Result(type):
    """Metaclass of message 'MissionExecutor_Result'."""

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
                'custom_drone_interfaces.action.MissionExecutor_Result')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__mission_executor__result
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__mission_executor__result
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__mission_executor__result
            cls._TYPE_SUPPORT = module.type_support_msg__action__mission_executor__result
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__mission_executor__result

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MissionExecutor_Result(metaclass=Metaclass_MissionExecutor_Result):
    """Message class 'MissionExecutor_Result'."""

    __slots__ = [
        '_mission_result',
    ]

    _fields_and_field_types = {
        'mission_result': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.mission_result = kwargs.get('mission_result', str())

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
        if self.mission_result != other.mission_result:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def mission_result(self):
        """Message field 'mission_result'."""
        return self._mission_result

    @mission_result.setter
    def mission_result(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'mission_result' field must be of type 'str'"
        self._mission_result = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_MissionExecutor_Feedback(type):
    """Metaclass of message 'MissionExecutor_Feedback'."""

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
                'custom_drone_interfaces.action.MissionExecutor_Feedback')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__mission_executor__feedback
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__mission_executor__feedback
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__mission_executor__feedback
            cls._TYPE_SUPPORT = module.type_support_msg__action__mission_executor__feedback
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__mission_executor__feedback

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MissionExecutor_Feedback(metaclass=Metaclass_MissionExecutor_Feedback):
    """Message class 'MissionExecutor_Feedback'."""

    __slots__ = [
        '_mission_feedback',
        '_status_code',
        '_command_id',
    ]

    _fields_and_field_types = {
        'mission_feedback': 'string',
        'status_code': 'int32',
        'command_id': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.mission_feedback = kwargs.get('mission_feedback', str())
        self.status_code = kwargs.get('status_code', int())
        self.command_id = kwargs.get('command_id', int())

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
        if self.mission_feedback != other.mission_feedback:
            return False
        if self.status_code != other.status_code:
            return False
        if self.command_id != other.command_id:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def mission_feedback(self):
        """Message field 'mission_feedback'."""
        return self._mission_feedback

    @mission_feedback.setter
    def mission_feedback(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'mission_feedback' field must be of type 'str'"
        self._mission_feedback = value

    @builtins.property
    def status_code(self):
        """Message field 'status_code'."""
        return self._status_code

    @status_code.setter
    def status_code(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'status_code' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'status_code' field must be an integer in [-2147483648, 2147483647]"
        self._status_code = value

    @builtins.property
    def command_id(self):
        """Message field 'command_id'."""
        return self._command_id

    @command_id.setter
    def command_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'command_id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'command_id' field must be an integer in [-2147483648, 2147483647]"
        self._command_id = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_MissionExecutor_SendGoal_Request(type):
    """Metaclass of message 'MissionExecutor_SendGoal_Request'."""

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
                'custom_drone_interfaces.action.MissionExecutor_SendGoal_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__mission_executor__send_goal__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__mission_executor__send_goal__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__mission_executor__send_goal__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__mission_executor__send_goal__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__mission_executor__send_goal__request

            from custom_drone_interfaces.action import MissionExecutor
            if MissionExecutor.Goal.__class__._TYPE_SUPPORT is None:
                MissionExecutor.Goal.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MissionExecutor_SendGoal_Request(metaclass=Metaclass_MissionExecutor_SendGoal_Request):
    """Message class 'MissionExecutor_SendGoal_Request'."""

    __slots__ = [
        '_goal_id',
        '_goal',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'goal': 'custom_drone_interfaces/MissionExecutor_Goal',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['custom_drone_interfaces', 'action'], 'MissionExecutor_Goal'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from custom_drone_interfaces.action._mission_executor import MissionExecutor_Goal
        self.goal = kwargs.get('goal', MissionExecutor_Goal())

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
        if self.goal_id != other.goal_id:
            return False
        if self.goal != other.goal:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @builtins.property
    def goal(self):
        """Message field 'goal'."""
        return self._goal

    @goal.setter
    def goal(self, value):
        if __debug__:
            from custom_drone_interfaces.action._mission_executor import MissionExecutor_Goal
            assert \
                isinstance(value, MissionExecutor_Goal), \
                "The 'goal' field must be a sub message of type 'MissionExecutor_Goal'"
        self._goal = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_MissionExecutor_SendGoal_Response(type):
    """Metaclass of message 'MissionExecutor_SendGoal_Response'."""

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
                'custom_drone_interfaces.action.MissionExecutor_SendGoal_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__mission_executor__send_goal__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__mission_executor__send_goal__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__mission_executor__send_goal__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__mission_executor__send_goal__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__mission_executor__send_goal__response

            from builtin_interfaces.msg import Time
            if Time.__class__._TYPE_SUPPORT is None:
                Time.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MissionExecutor_SendGoal_Response(metaclass=Metaclass_MissionExecutor_SendGoal_Response):
    """Message class 'MissionExecutor_SendGoal_Response'."""

    __slots__ = [
        '_accepted',
        '_stamp',
    ]

    _fields_and_field_types = {
        'accepted': 'boolean',
        'stamp': 'builtin_interfaces/Time',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.accepted = kwargs.get('accepted', bool())
        from builtin_interfaces.msg import Time
        self.stamp = kwargs.get('stamp', Time())

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
        if self.accepted != other.accepted:
            return False
        if self.stamp != other.stamp:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def accepted(self):
        """Message field 'accepted'."""
        return self._accepted

    @accepted.setter
    def accepted(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'accepted' field must be of type 'bool'"
        self._accepted = value

    @builtins.property
    def stamp(self):
        """Message field 'stamp'."""
        return self._stamp

    @stamp.setter
    def stamp(self, value):
        if __debug__:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'stamp' field must be a sub message of type 'Time'"
        self._stamp = value


class Metaclass_MissionExecutor_SendGoal(type):
    """Metaclass of service 'MissionExecutor_SendGoal'."""

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
                'custom_drone_interfaces.action.MissionExecutor_SendGoal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__mission_executor__send_goal

            from custom_drone_interfaces.action import _mission_executor
            if _mission_executor.Metaclass_MissionExecutor_SendGoal_Request._TYPE_SUPPORT is None:
                _mission_executor.Metaclass_MissionExecutor_SendGoal_Request.__import_type_support__()
            if _mission_executor.Metaclass_MissionExecutor_SendGoal_Response._TYPE_SUPPORT is None:
                _mission_executor.Metaclass_MissionExecutor_SendGoal_Response.__import_type_support__()


class MissionExecutor_SendGoal(metaclass=Metaclass_MissionExecutor_SendGoal):
    from custom_drone_interfaces.action._mission_executor import MissionExecutor_SendGoal_Request as Request
    from custom_drone_interfaces.action._mission_executor import MissionExecutor_SendGoal_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_MissionExecutor_GetResult_Request(type):
    """Metaclass of message 'MissionExecutor_GetResult_Request'."""

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
                'custom_drone_interfaces.action.MissionExecutor_GetResult_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__mission_executor__get_result__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__mission_executor__get_result__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__mission_executor__get_result__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__mission_executor__get_result__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__mission_executor__get_result__request

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MissionExecutor_GetResult_Request(metaclass=Metaclass_MissionExecutor_GetResult_Request):
    """Message class 'MissionExecutor_GetResult_Request'."""

    __slots__ = [
        '_goal_id',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())

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
        if self.goal_id != other.goal_id:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_MissionExecutor_GetResult_Response(type):
    """Metaclass of message 'MissionExecutor_GetResult_Response'."""

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
                'custom_drone_interfaces.action.MissionExecutor_GetResult_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__mission_executor__get_result__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__mission_executor__get_result__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__mission_executor__get_result__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__mission_executor__get_result__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__mission_executor__get_result__response

            from custom_drone_interfaces.action import MissionExecutor
            if MissionExecutor.Result.__class__._TYPE_SUPPORT is None:
                MissionExecutor.Result.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MissionExecutor_GetResult_Response(metaclass=Metaclass_MissionExecutor_GetResult_Response):
    """Message class 'MissionExecutor_GetResult_Response'."""

    __slots__ = [
        '_status',
        '_result',
    ]

    _fields_and_field_types = {
        'status': 'int8',
        'result': 'custom_drone_interfaces/MissionExecutor_Result',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['custom_drone_interfaces', 'action'], 'MissionExecutor_Result'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.status = kwargs.get('status', int())
        from custom_drone_interfaces.action._mission_executor import MissionExecutor_Result
        self.result = kwargs.get('result', MissionExecutor_Result())

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
        if self.status != other.status:
            return False
        if self.result != other.result:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'status' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'status' field must be an integer in [-128, 127]"
        self._status = value

    @builtins.property
    def result(self):
        """Message field 'result'."""
        return self._result

    @result.setter
    def result(self, value):
        if __debug__:
            from custom_drone_interfaces.action._mission_executor import MissionExecutor_Result
            assert \
                isinstance(value, MissionExecutor_Result), \
                "The 'result' field must be a sub message of type 'MissionExecutor_Result'"
        self._result = value


class Metaclass_MissionExecutor_GetResult(type):
    """Metaclass of service 'MissionExecutor_GetResult'."""

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
                'custom_drone_interfaces.action.MissionExecutor_GetResult')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__mission_executor__get_result

            from custom_drone_interfaces.action import _mission_executor
            if _mission_executor.Metaclass_MissionExecutor_GetResult_Request._TYPE_SUPPORT is None:
                _mission_executor.Metaclass_MissionExecutor_GetResult_Request.__import_type_support__()
            if _mission_executor.Metaclass_MissionExecutor_GetResult_Response._TYPE_SUPPORT is None:
                _mission_executor.Metaclass_MissionExecutor_GetResult_Response.__import_type_support__()


class MissionExecutor_GetResult(metaclass=Metaclass_MissionExecutor_GetResult):
    from custom_drone_interfaces.action._mission_executor import MissionExecutor_GetResult_Request as Request
    from custom_drone_interfaces.action._mission_executor import MissionExecutor_GetResult_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_MissionExecutor_FeedbackMessage(type):
    """Metaclass of message 'MissionExecutor_FeedbackMessage'."""

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
                'custom_drone_interfaces.action.MissionExecutor_FeedbackMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__mission_executor__feedback_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__mission_executor__feedback_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__mission_executor__feedback_message
            cls._TYPE_SUPPORT = module.type_support_msg__action__mission_executor__feedback_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__mission_executor__feedback_message

            from custom_drone_interfaces.action import MissionExecutor
            if MissionExecutor.Feedback.__class__._TYPE_SUPPORT is None:
                MissionExecutor.Feedback.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MissionExecutor_FeedbackMessage(metaclass=Metaclass_MissionExecutor_FeedbackMessage):
    """Message class 'MissionExecutor_FeedbackMessage'."""

    __slots__ = [
        '_goal_id',
        '_feedback',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'feedback': 'custom_drone_interfaces/MissionExecutor_Feedback',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['custom_drone_interfaces', 'action'], 'MissionExecutor_Feedback'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from custom_drone_interfaces.action._mission_executor import MissionExecutor_Feedback
        self.feedback = kwargs.get('feedback', MissionExecutor_Feedback())

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
        if self.goal_id != other.goal_id:
            return False
        if self.feedback != other.feedback:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @builtins.property
    def feedback(self):
        """Message field 'feedback'."""
        return self._feedback

    @feedback.setter
    def feedback(self, value):
        if __debug__:
            from custom_drone_interfaces.action._mission_executor import MissionExecutor_Feedback
            assert \
                isinstance(value, MissionExecutor_Feedback), \
                "The 'feedback' field must be a sub message of type 'MissionExecutor_Feedback'"
        self._feedback = value


class Metaclass_MissionExecutor(type):
    """Metaclass of action 'MissionExecutor'."""

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
                'custom_drone_interfaces.action.MissionExecutor')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_action__action__mission_executor

            from action_msgs.msg import _goal_status_array
            if _goal_status_array.Metaclass_GoalStatusArray._TYPE_SUPPORT is None:
                _goal_status_array.Metaclass_GoalStatusArray.__import_type_support__()
            from action_msgs.srv import _cancel_goal
            if _cancel_goal.Metaclass_CancelGoal._TYPE_SUPPORT is None:
                _cancel_goal.Metaclass_CancelGoal.__import_type_support__()

            from custom_drone_interfaces.action import _mission_executor
            if _mission_executor.Metaclass_MissionExecutor_SendGoal._TYPE_SUPPORT is None:
                _mission_executor.Metaclass_MissionExecutor_SendGoal.__import_type_support__()
            if _mission_executor.Metaclass_MissionExecutor_GetResult._TYPE_SUPPORT is None:
                _mission_executor.Metaclass_MissionExecutor_GetResult.__import_type_support__()
            if _mission_executor.Metaclass_MissionExecutor_FeedbackMessage._TYPE_SUPPORT is None:
                _mission_executor.Metaclass_MissionExecutor_FeedbackMessage.__import_type_support__()


class MissionExecutor(metaclass=Metaclass_MissionExecutor):

    # The goal message defined in the action definition.
    from custom_drone_interfaces.action._mission_executor import MissionExecutor_Goal as Goal
    # The result message defined in the action definition.
    from custom_drone_interfaces.action._mission_executor import MissionExecutor_Result as Result
    # The feedback message defined in the action definition.
    from custom_drone_interfaces.action._mission_executor import MissionExecutor_Feedback as Feedback

    class Impl:

        # The send_goal service using a wrapped version of the goal message as a request.
        from custom_drone_interfaces.action._mission_executor import MissionExecutor_SendGoal as SendGoalService
        # The get_result service using a wrapped version of the result message as a response.
        from custom_drone_interfaces.action._mission_executor import MissionExecutor_GetResult as GetResultService
        # The feedback message with generic fields which wraps the feedback message.
        from custom_drone_interfaces.action._mission_executor import MissionExecutor_FeedbackMessage as FeedbackMessage

        # The generic service to cancel a goal.
        from action_msgs.srv._cancel_goal import CancelGoal as CancelGoalService
        # The generic message for get the status of a goal.
        from action_msgs.msg._goal_status_array import GoalStatusArray as GoalStatusMessage

    def __init__(self):
        raise NotImplementedError('Action classes can not be instantiated')
