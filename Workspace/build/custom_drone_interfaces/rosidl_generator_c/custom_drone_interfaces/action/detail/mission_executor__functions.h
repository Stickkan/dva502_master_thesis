// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from custom_drone_interfaces:action/MissionExecutor.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__ACTION__DETAIL__MISSION_EXECUTOR__FUNCTIONS_H_
#define CUSTOM_DRONE_INTERFACES__ACTION__DETAIL__MISSION_EXECUTOR__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "custom_drone_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "custom_drone_interfaces/action/detail/mission_executor__struct.h"

/// Initialize action/MissionExecutor message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * custom_drone_interfaces__action__MissionExecutor_Goal
 * )) before or use
 * custom_drone_interfaces__action__MissionExecutor_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_Goal__init(custom_drone_interfaces__action__MissionExecutor_Goal * msg);

/// Finalize action/MissionExecutor message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
void
custom_drone_interfaces__action__MissionExecutor_Goal__fini(custom_drone_interfaces__action__MissionExecutor_Goal * msg);

/// Create action/MissionExecutor message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * custom_drone_interfaces__action__MissionExecutor_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
custom_drone_interfaces__action__MissionExecutor_Goal *
custom_drone_interfaces__action__MissionExecutor_Goal__create();

/// Destroy action/MissionExecutor message.
/**
 * It calls
 * custom_drone_interfaces__action__MissionExecutor_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
void
custom_drone_interfaces__action__MissionExecutor_Goal__destroy(custom_drone_interfaces__action__MissionExecutor_Goal * msg);

/// Check for action/MissionExecutor message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_Goal__are_equal(const custom_drone_interfaces__action__MissionExecutor_Goal * lhs, const custom_drone_interfaces__action__MissionExecutor_Goal * rhs);

/// Copy a action/MissionExecutor message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_Goal__copy(
  const custom_drone_interfaces__action__MissionExecutor_Goal * input,
  custom_drone_interfaces__action__MissionExecutor_Goal * output);

/// Initialize array of action/MissionExecutor messages.
/**
 * It allocates the memory for the number of elements and calls
 * custom_drone_interfaces__action__MissionExecutor_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_Goal__Sequence__init(custom_drone_interfaces__action__MissionExecutor_Goal__Sequence * array, size_t size);

/// Finalize array of action/MissionExecutor messages.
/**
 * It calls
 * custom_drone_interfaces__action__MissionExecutor_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
void
custom_drone_interfaces__action__MissionExecutor_Goal__Sequence__fini(custom_drone_interfaces__action__MissionExecutor_Goal__Sequence * array);

/// Create array of action/MissionExecutor messages.
/**
 * It allocates the memory for the array and calls
 * custom_drone_interfaces__action__MissionExecutor_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
custom_drone_interfaces__action__MissionExecutor_Goal__Sequence *
custom_drone_interfaces__action__MissionExecutor_Goal__Sequence__create(size_t size);

/// Destroy array of action/MissionExecutor messages.
/**
 * It calls
 * custom_drone_interfaces__action__MissionExecutor_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
void
custom_drone_interfaces__action__MissionExecutor_Goal__Sequence__destroy(custom_drone_interfaces__action__MissionExecutor_Goal__Sequence * array);

/// Check for action/MissionExecutor message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_Goal__Sequence__are_equal(const custom_drone_interfaces__action__MissionExecutor_Goal__Sequence * lhs, const custom_drone_interfaces__action__MissionExecutor_Goal__Sequence * rhs);

/// Copy an array of action/MissionExecutor messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_Goal__Sequence__copy(
  const custom_drone_interfaces__action__MissionExecutor_Goal__Sequence * input,
  custom_drone_interfaces__action__MissionExecutor_Goal__Sequence * output);

/// Initialize action/MissionExecutor message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * custom_drone_interfaces__action__MissionExecutor_Result
 * )) before or use
 * custom_drone_interfaces__action__MissionExecutor_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_Result__init(custom_drone_interfaces__action__MissionExecutor_Result * msg);

/// Finalize action/MissionExecutor message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
void
custom_drone_interfaces__action__MissionExecutor_Result__fini(custom_drone_interfaces__action__MissionExecutor_Result * msg);

/// Create action/MissionExecutor message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * custom_drone_interfaces__action__MissionExecutor_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
custom_drone_interfaces__action__MissionExecutor_Result *
custom_drone_interfaces__action__MissionExecutor_Result__create();

/// Destroy action/MissionExecutor message.
/**
 * It calls
 * custom_drone_interfaces__action__MissionExecutor_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
void
custom_drone_interfaces__action__MissionExecutor_Result__destroy(custom_drone_interfaces__action__MissionExecutor_Result * msg);

/// Check for action/MissionExecutor message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_Result__are_equal(const custom_drone_interfaces__action__MissionExecutor_Result * lhs, const custom_drone_interfaces__action__MissionExecutor_Result * rhs);

/// Copy a action/MissionExecutor message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_Result__copy(
  const custom_drone_interfaces__action__MissionExecutor_Result * input,
  custom_drone_interfaces__action__MissionExecutor_Result * output);

/// Initialize array of action/MissionExecutor messages.
/**
 * It allocates the memory for the number of elements and calls
 * custom_drone_interfaces__action__MissionExecutor_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_Result__Sequence__init(custom_drone_interfaces__action__MissionExecutor_Result__Sequence * array, size_t size);

/// Finalize array of action/MissionExecutor messages.
/**
 * It calls
 * custom_drone_interfaces__action__MissionExecutor_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
void
custom_drone_interfaces__action__MissionExecutor_Result__Sequence__fini(custom_drone_interfaces__action__MissionExecutor_Result__Sequence * array);

/// Create array of action/MissionExecutor messages.
/**
 * It allocates the memory for the array and calls
 * custom_drone_interfaces__action__MissionExecutor_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
custom_drone_interfaces__action__MissionExecutor_Result__Sequence *
custom_drone_interfaces__action__MissionExecutor_Result__Sequence__create(size_t size);

/// Destroy array of action/MissionExecutor messages.
/**
 * It calls
 * custom_drone_interfaces__action__MissionExecutor_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
void
custom_drone_interfaces__action__MissionExecutor_Result__Sequence__destroy(custom_drone_interfaces__action__MissionExecutor_Result__Sequence * array);

/// Check for action/MissionExecutor message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_Result__Sequence__are_equal(const custom_drone_interfaces__action__MissionExecutor_Result__Sequence * lhs, const custom_drone_interfaces__action__MissionExecutor_Result__Sequence * rhs);

/// Copy an array of action/MissionExecutor messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_Result__Sequence__copy(
  const custom_drone_interfaces__action__MissionExecutor_Result__Sequence * input,
  custom_drone_interfaces__action__MissionExecutor_Result__Sequence * output);

/// Initialize action/MissionExecutor message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * custom_drone_interfaces__action__MissionExecutor_Feedback
 * )) before or use
 * custom_drone_interfaces__action__MissionExecutor_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_Feedback__init(custom_drone_interfaces__action__MissionExecutor_Feedback * msg);

/// Finalize action/MissionExecutor message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
void
custom_drone_interfaces__action__MissionExecutor_Feedback__fini(custom_drone_interfaces__action__MissionExecutor_Feedback * msg);

/// Create action/MissionExecutor message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * custom_drone_interfaces__action__MissionExecutor_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
custom_drone_interfaces__action__MissionExecutor_Feedback *
custom_drone_interfaces__action__MissionExecutor_Feedback__create();

/// Destroy action/MissionExecutor message.
/**
 * It calls
 * custom_drone_interfaces__action__MissionExecutor_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
void
custom_drone_interfaces__action__MissionExecutor_Feedback__destroy(custom_drone_interfaces__action__MissionExecutor_Feedback * msg);

/// Check for action/MissionExecutor message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_Feedback__are_equal(const custom_drone_interfaces__action__MissionExecutor_Feedback * lhs, const custom_drone_interfaces__action__MissionExecutor_Feedback * rhs);

/// Copy a action/MissionExecutor message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_Feedback__copy(
  const custom_drone_interfaces__action__MissionExecutor_Feedback * input,
  custom_drone_interfaces__action__MissionExecutor_Feedback * output);

/// Initialize array of action/MissionExecutor messages.
/**
 * It allocates the memory for the number of elements and calls
 * custom_drone_interfaces__action__MissionExecutor_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_Feedback__Sequence__init(custom_drone_interfaces__action__MissionExecutor_Feedback__Sequence * array, size_t size);

/// Finalize array of action/MissionExecutor messages.
/**
 * It calls
 * custom_drone_interfaces__action__MissionExecutor_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
void
custom_drone_interfaces__action__MissionExecutor_Feedback__Sequence__fini(custom_drone_interfaces__action__MissionExecutor_Feedback__Sequence * array);

/// Create array of action/MissionExecutor messages.
/**
 * It allocates the memory for the array and calls
 * custom_drone_interfaces__action__MissionExecutor_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
custom_drone_interfaces__action__MissionExecutor_Feedback__Sequence *
custom_drone_interfaces__action__MissionExecutor_Feedback__Sequence__create(size_t size);

/// Destroy array of action/MissionExecutor messages.
/**
 * It calls
 * custom_drone_interfaces__action__MissionExecutor_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
void
custom_drone_interfaces__action__MissionExecutor_Feedback__Sequence__destroy(custom_drone_interfaces__action__MissionExecutor_Feedback__Sequence * array);

/// Check for action/MissionExecutor message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_Feedback__Sequence__are_equal(const custom_drone_interfaces__action__MissionExecutor_Feedback__Sequence * lhs, const custom_drone_interfaces__action__MissionExecutor_Feedback__Sequence * rhs);

/// Copy an array of action/MissionExecutor messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_Feedback__Sequence__copy(
  const custom_drone_interfaces__action__MissionExecutor_Feedback__Sequence * input,
  custom_drone_interfaces__action__MissionExecutor_Feedback__Sequence * output);

/// Initialize action/MissionExecutor message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * custom_drone_interfaces__action__MissionExecutor_SendGoal_Request
 * )) before or use
 * custom_drone_interfaces__action__MissionExecutor_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_SendGoal_Request__init(custom_drone_interfaces__action__MissionExecutor_SendGoal_Request * msg);

/// Finalize action/MissionExecutor message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
void
custom_drone_interfaces__action__MissionExecutor_SendGoal_Request__fini(custom_drone_interfaces__action__MissionExecutor_SendGoal_Request * msg);

/// Create action/MissionExecutor message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * custom_drone_interfaces__action__MissionExecutor_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
custom_drone_interfaces__action__MissionExecutor_SendGoal_Request *
custom_drone_interfaces__action__MissionExecutor_SendGoal_Request__create();

/// Destroy action/MissionExecutor message.
/**
 * It calls
 * custom_drone_interfaces__action__MissionExecutor_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
void
custom_drone_interfaces__action__MissionExecutor_SendGoal_Request__destroy(custom_drone_interfaces__action__MissionExecutor_SendGoal_Request * msg);

/// Check for action/MissionExecutor message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_SendGoal_Request__are_equal(const custom_drone_interfaces__action__MissionExecutor_SendGoal_Request * lhs, const custom_drone_interfaces__action__MissionExecutor_SendGoal_Request * rhs);

/// Copy a action/MissionExecutor message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_SendGoal_Request__copy(
  const custom_drone_interfaces__action__MissionExecutor_SendGoal_Request * input,
  custom_drone_interfaces__action__MissionExecutor_SendGoal_Request * output);

/// Initialize array of action/MissionExecutor messages.
/**
 * It allocates the memory for the number of elements and calls
 * custom_drone_interfaces__action__MissionExecutor_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_SendGoal_Request__Sequence__init(custom_drone_interfaces__action__MissionExecutor_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/MissionExecutor messages.
/**
 * It calls
 * custom_drone_interfaces__action__MissionExecutor_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
void
custom_drone_interfaces__action__MissionExecutor_SendGoal_Request__Sequence__fini(custom_drone_interfaces__action__MissionExecutor_SendGoal_Request__Sequence * array);

/// Create array of action/MissionExecutor messages.
/**
 * It allocates the memory for the array and calls
 * custom_drone_interfaces__action__MissionExecutor_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
custom_drone_interfaces__action__MissionExecutor_SendGoal_Request__Sequence *
custom_drone_interfaces__action__MissionExecutor_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/MissionExecutor messages.
/**
 * It calls
 * custom_drone_interfaces__action__MissionExecutor_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
void
custom_drone_interfaces__action__MissionExecutor_SendGoal_Request__Sequence__destroy(custom_drone_interfaces__action__MissionExecutor_SendGoal_Request__Sequence * array);

/// Check for action/MissionExecutor message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_SendGoal_Request__Sequence__are_equal(const custom_drone_interfaces__action__MissionExecutor_SendGoal_Request__Sequence * lhs, const custom_drone_interfaces__action__MissionExecutor_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/MissionExecutor messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_SendGoal_Request__Sequence__copy(
  const custom_drone_interfaces__action__MissionExecutor_SendGoal_Request__Sequence * input,
  custom_drone_interfaces__action__MissionExecutor_SendGoal_Request__Sequence * output);

/// Initialize action/MissionExecutor message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * custom_drone_interfaces__action__MissionExecutor_SendGoal_Response
 * )) before or use
 * custom_drone_interfaces__action__MissionExecutor_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_SendGoal_Response__init(custom_drone_interfaces__action__MissionExecutor_SendGoal_Response * msg);

/// Finalize action/MissionExecutor message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
void
custom_drone_interfaces__action__MissionExecutor_SendGoal_Response__fini(custom_drone_interfaces__action__MissionExecutor_SendGoal_Response * msg);

/// Create action/MissionExecutor message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * custom_drone_interfaces__action__MissionExecutor_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
custom_drone_interfaces__action__MissionExecutor_SendGoal_Response *
custom_drone_interfaces__action__MissionExecutor_SendGoal_Response__create();

/// Destroy action/MissionExecutor message.
/**
 * It calls
 * custom_drone_interfaces__action__MissionExecutor_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
void
custom_drone_interfaces__action__MissionExecutor_SendGoal_Response__destroy(custom_drone_interfaces__action__MissionExecutor_SendGoal_Response * msg);

/// Check for action/MissionExecutor message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_SendGoal_Response__are_equal(const custom_drone_interfaces__action__MissionExecutor_SendGoal_Response * lhs, const custom_drone_interfaces__action__MissionExecutor_SendGoal_Response * rhs);

/// Copy a action/MissionExecutor message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_SendGoal_Response__copy(
  const custom_drone_interfaces__action__MissionExecutor_SendGoal_Response * input,
  custom_drone_interfaces__action__MissionExecutor_SendGoal_Response * output);

/// Initialize array of action/MissionExecutor messages.
/**
 * It allocates the memory for the number of elements and calls
 * custom_drone_interfaces__action__MissionExecutor_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_SendGoal_Response__Sequence__init(custom_drone_interfaces__action__MissionExecutor_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/MissionExecutor messages.
/**
 * It calls
 * custom_drone_interfaces__action__MissionExecutor_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
void
custom_drone_interfaces__action__MissionExecutor_SendGoal_Response__Sequence__fini(custom_drone_interfaces__action__MissionExecutor_SendGoal_Response__Sequence * array);

/// Create array of action/MissionExecutor messages.
/**
 * It allocates the memory for the array and calls
 * custom_drone_interfaces__action__MissionExecutor_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
custom_drone_interfaces__action__MissionExecutor_SendGoal_Response__Sequence *
custom_drone_interfaces__action__MissionExecutor_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/MissionExecutor messages.
/**
 * It calls
 * custom_drone_interfaces__action__MissionExecutor_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
void
custom_drone_interfaces__action__MissionExecutor_SendGoal_Response__Sequence__destroy(custom_drone_interfaces__action__MissionExecutor_SendGoal_Response__Sequence * array);

/// Check for action/MissionExecutor message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_SendGoal_Response__Sequence__are_equal(const custom_drone_interfaces__action__MissionExecutor_SendGoal_Response__Sequence * lhs, const custom_drone_interfaces__action__MissionExecutor_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/MissionExecutor messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_SendGoal_Response__Sequence__copy(
  const custom_drone_interfaces__action__MissionExecutor_SendGoal_Response__Sequence * input,
  custom_drone_interfaces__action__MissionExecutor_SendGoal_Response__Sequence * output);

/// Initialize action/MissionExecutor message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * custom_drone_interfaces__action__MissionExecutor_GetResult_Request
 * )) before or use
 * custom_drone_interfaces__action__MissionExecutor_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_GetResult_Request__init(custom_drone_interfaces__action__MissionExecutor_GetResult_Request * msg);

/// Finalize action/MissionExecutor message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
void
custom_drone_interfaces__action__MissionExecutor_GetResult_Request__fini(custom_drone_interfaces__action__MissionExecutor_GetResult_Request * msg);

/// Create action/MissionExecutor message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * custom_drone_interfaces__action__MissionExecutor_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
custom_drone_interfaces__action__MissionExecutor_GetResult_Request *
custom_drone_interfaces__action__MissionExecutor_GetResult_Request__create();

/// Destroy action/MissionExecutor message.
/**
 * It calls
 * custom_drone_interfaces__action__MissionExecutor_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
void
custom_drone_interfaces__action__MissionExecutor_GetResult_Request__destroy(custom_drone_interfaces__action__MissionExecutor_GetResult_Request * msg);

/// Check for action/MissionExecutor message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_GetResult_Request__are_equal(const custom_drone_interfaces__action__MissionExecutor_GetResult_Request * lhs, const custom_drone_interfaces__action__MissionExecutor_GetResult_Request * rhs);

/// Copy a action/MissionExecutor message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_GetResult_Request__copy(
  const custom_drone_interfaces__action__MissionExecutor_GetResult_Request * input,
  custom_drone_interfaces__action__MissionExecutor_GetResult_Request * output);

/// Initialize array of action/MissionExecutor messages.
/**
 * It allocates the memory for the number of elements and calls
 * custom_drone_interfaces__action__MissionExecutor_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_GetResult_Request__Sequence__init(custom_drone_interfaces__action__MissionExecutor_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/MissionExecutor messages.
/**
 * It calls
 * custom_drone_interfaces__action__MissionExecutor_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
void
custom_drone_interfaces__action__MissionExecutor_GetResult_Request__Sequence__fini(custom_drone_interfaces__action__MissionExecutor_GetResult_Request__Sequence * array);

/// Create array of action/MissionExecutor messages.
/**
 * It allocates the memory for the array and calls
 * custom_drone_interfaces__action__MissionExecutor_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
custom_drone_interfaces__action__MissionExecutor_GetResult_Request__Sequence *
custom_drone_interfaces__action__MissionExecutor_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/MissionExecutor messages.
/**
 * It calls
 * custom_drone_interfaces__action__MissionExecutor_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
void
custom_drone_interfaces__action__MissionExecutor_GetResult_Request__Sequence__destroy(custom_drone_interfaces__action__MissionExecutor_GetResult_Request__Sequence * array);

/// Check for action/MissionExecutor message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_GetResult_Request__Sequence__are_equal(const custom_drone_interfaces__action__MissionExecutor_GetResult_Request__Sequence * lhs, const custom_drone_interfaces__action__MissionExecutor_GetResult_Request__Sequence * rhs);

/// Copy an array of action/MissionExecutor messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_GetResult_Request__Sequence__copy(
  const custom_drone_interfaces__action__MissionExecutor_GetResult_Request__Sequence * input,
  custom_drone_interfaces__action__MissionExecutor_GetResult_Request__Sequence * output);

/// Initialize action/MissionExecutor message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * custom_drone_interfaces__action__MissionExecutor_GetResult_Response
 * )) before or use
 * custom_drone_interfaces__action__MissionExecutor_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_GetResult_Response__init(custom_drone_interfaces__action__MissionExecutor_GetResult_Response * msg);

/// Finalize action/MissionExecutor message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
void
custom_drone_interfaces__action__MissionExecutor_GetResult_Response__fini(custom_drone_interfaces__action__MissionExecutor_GetResult_Response * msg);

/// Create action/MissionExecutor message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * custom_drone_interfaces__action__MissionExecutor_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
custom_drone_interfaces__action__MissionExecutor_GetResult_Response *
custom_drone_interfaces__action__MissionExecutor_GetResult_Response__create();

/// Destroy action/MissionExecutor message.
/**
 * It calls
 * custom_drone_interfaces__action__MissionExecutor_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
void
custom_drone_interfaces__action__MissionExecutor_GetResult_Response__destroy(custom_drone_interfaces__action__MissionExecutor_GetResult_Response * msg);

/// Check for action/MissionExecutor message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_GetResult_Response__are_equal(const custom_drone_interfaces__action__MissionExecutor_GetResult_Response * lhs, const custom_drone_interfaces__action__MissionExecutor_GetResult_Response * rhs);

/// Copy a action/MissionExecutor message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_GetResult_Response__copy(
  const custom_drone_interfaces__action__MissionExecutor_GetResult_Response * input,
  custom_drone_interfaces__action__MissionExecutor_GetResult_Response * output);

/// Initialize array of action/MissionExecutor messages.
/**
 * It allocates the memory for the number of elements and calls
 * custom_drone_interfaces__action__MissionExecutor_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_GetResult_Response__Sequence__init(custom_drone_interfaces__action__MissionExecutor_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/MissionExecutor messages.
/**
 * It calls
 * custom_drone_interfaces__action__MissionExecutor_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
void
custom_drone_interfaces__action__MissionExecutor_GetResult_Response__Sequence__fini(custom_drone_interfaces__action__MissionExecutor_GetResult_Response__Sequence * array);

/// Create array of action/MissionExecutor messages.
/**
 * It allocates the memory for the array and calls
 * custom_drone_interfaces__action__MissionExecutor_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
custom_drone_interfaces__action__MissionExecutor_GetResult_Response__Sequence *
custom_drone_interfaces__action__MissionExecutor_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/MissionExecutor messages.
/**
 * It calls
 * custom_drone_interfaces__action__MissionExecutor_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
void
custom_drone_interfaces__action__MissionExecutor_GetResult_Response__Sequence__destroy(custom_drone_interfaces__action__MissionExecutor_GetResult_Response__Sequence * array);

/// Check for action/MissionExecutor message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_GetResult_Response__Sequence__are_equal(const custom_drone_interfaces__action__MissionExecutor_GetResult_Response__Sequence * lhs, const custom_drone_interfaces__action__MissionExecutor_GetResult_Response__Sequence * rhs);

/// Copy an array of action/MissionExecutor messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_GetResult_Response__Sequence__copy(
  const custom_drone_interfaces__action__MissionExecutor_GetResult_Response__Sequence * input,
  custom_drone_interfaces__action__MissionExecutor_GetResult_Response__Sequence * output);

/// Initialize action/MissionExecutor message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * custom_drone_interfaces__action__MissionExecutor_FeedbackMessage
 * )) before or use
 * custom_drone_interfaces__action__MissionExecutor_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_FeedbackMessage__init(custom_drone_interfaces__action__MissionExecutor_FeedbackMessage * msg);

/// Finalize action/MissionExecutor message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
void
custom_drone_interfaces__action__MissionExecutor_FeedbackMessage__fini(custom_drone_interfaces__action__MissionExecutor_FeedbackMessage * msg);

/// Create action/MissionExecutor message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * custom_drone_interfaces__action__MissionExecutor_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
custom_drone_interfaces__action__MissionExecutor_FeedbackMessage *
custom_drone_interfaces__action__MissionExecutor_FeedbackMessage__create();

/// Destroy action/MissionExecutor message.
/**
 * It calls
 * custom_drone_interfaces__action__MissionExecutor_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
void
custom_drone_interfaces__action__MissionExecutor_FeedbackMessage__destroy(custom_drone_interfaces__action__MissionExecutor_FeedbackMessage * msg);

/// Check for action/MissionExecutor message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_FeedbackMessage__are_equal(const custom_drone_interfaces__action__MissionExecutor_FeedbackMessage * lhs, const custom_drone_interfaces__action__MissionExecutor_FeedbackMessage * rhs);

/// Copy a action/MissionExecutor message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_FeedbackMessage__copy(
  const custom_drone_interfaces__action__MissionExecutor_FeedbackMessage * input,
  custom_drone_interfaces__action__MissionExecutor_FeedbackMessage * output);

/// Initialize array of action/MissionExecutor messages.
/**
 * It allocates the memory for the number of elements and calls
 * custom_drone_interfaces__action__MissionExecutor_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_FeedbackMessage__Sequence__init(custom_drone_interfaces__action__MissionExecutor_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/MissionExecutor messages.
/**
 * It calls
 * custom_drone_interfaces__action__MissionExecutor_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
void
custom_drone_interfaces__action__MissionExecutor_FeedbackMessage__Sequence__fini(custom_drone_interfaces__action__MissionExecutor_FeedbackMessage__Sequence * array);

/// Create array of action/MissionExecutor messages.
/**
 * It allocates the memory for the array and calls
 * custom_drone_interfaces__action__MissionExecutor_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
custom_drone_interfaces__action__MissionExecutor_FeedbackMessage__Sequence *
custom_drone_interfaces__action__MissionExecutor_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/MissionExecutor messages.
/**
 * It calls
 * custom_drone_interfaces__action__MissionExecutor_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
void
custom_drone_interfaces__action__MissionExecutor_FeedbackMessage__Sequence__destroy(custom_drone_interfaces__action__MissionExecutor_FeedbackMessage__Sequence * array);

/// Check for action/MissionExecutor message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_FeedbackMessage__Sequence__are_equal(const custom_drone_interfaces__action__MissionExecutor_FeedbackMessage__Sequence * lhs, const custom_drone_interfaces__action__MissionExecutor_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/MissionExecutor messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_drone_interfaces
bool
custom_drone_interfaces__action__MissionExecutor_FeedbackMessage__Sequence__copy(
  const custom_drone_interfaces__action__MissionExecutor_FeedbackMessage__Sequence * input,
  custom_drone_interfaces__action__MissionExecutor_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_DRONE_INTERFACES__ACTION__DETAIL__MISSION_EXECUTOR__FUNCTIONS_H_
