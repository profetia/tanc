#ifndef LIBTANC_DEBUG_H
#define LIBTANC_DEBUG_H

/* Ensure that this header is only used with GCC. */
#ifndef __GNUC__
#error "libtanc/backtrace.h requires GCC"
#endif

/* Include the libtanc headers. */
#include "libtanc/backtrace.h"
#include "libtanc/format.h"

/* clang-format off */
#include "libtanc/internal/module.h"
/* clang-format on */

/**
 * @brief Return the file name.
 * @return The file name.
 */
#define file_() __FILE__

/**
 * @brief Return the line number.
 * @return The line number.
 */
#define line_() __LINE__

/**
 * @brief Return the function name.
 * @return The function name.
 */
#define function_() __builtin_FUNCTION()

/**
 * @brief Panic with the variadic argument list.
 * @param stmt The variadic argument list, e.g. ("foo %d", 42).
 * @return
 */
#define panic_(stmt)                                                       \
  do {                                                                     \
    char* tanc__debug__message = tanc__format__format stmt;                \
    tanc__backtrace__panic_handler(tanc__debug__message, file_(), line_(), \
                                   function_());                           \
  } while (0)

/**
 * @brief Indicates unfinished code by panicking with a message of "not yet
 *        implemented".
 * @param stmt The variadic argument list, e.g. ("foo %d", 42).
 * @return
 */
#define todo_(stmt)                                                        \
  do {                                                                     \
    char* tanc__debug__message_inner = tanc__format__format stmt;          \
    char* tanc__debug__message = tanc__format__format(                     \
        "not yet implemented: %s", tanc__debug__message_inner);            \
    free(tanc__debug__message_inner);                                      \
    tanc__backtrace__panic_handler(tanc__debug__message, file_(), line_(), \
                                   function_());                           \
  } while (0)

/**
 * @brief Indicates unimplemented code by panicking with a message of "not
 *        implemented".
 * @param stmt The variadic argument list, e.g. ("foo %d", 42).
 * @return
 */
#define unimplemented_(stmt)                                               \
  do {                                                                     \
    char* tanc__debug__message_inner = tanc__format__format stmt;          \
    char* tanc__debug__message = tanc__format__format(                     \
        "not implemented: %s", tanc__debug__message_inner);                \
    free(tanc__debug__message_inner);                                      \
    tanc__backtrace__panic_handler(tanc__debug__message, file_(), line_(), \
                                   function_());                           \
  } while (0)

/**
 * @brief Indicates unreachable code by panicking with a message of "entered
 *       unreachable code".
 * @param stmt The variadic argument list, e.g. ("foo %d", 42).
 * @return
 */
#define unreachable_(stmt)                                                 \
  do {                                                                     \
    char* tanc__debug__message_inner = tanc__format__format stmt;          \
    char* tanc__debug__message = tanc__format__format(                     \
        "entered unreachable code: %s", tanc__debug__message_inner);       \
    free(tanc__debug__message_inner);                                      \
    tanc__backtrace__panic_handler(tanc__debug__message, file_(), line_(), \
                                   function_());                           \
  } while (0)

/**
 * @brief Asserts that the statement is true, otherwise panics with a message
 *       of "assertion failed: <stmt>".
 * @param stmt The statement to assert.
 * @return
 */
#define assert_(stmt)                                                        \
  do {                                                                       \
    if (!(stmt)) {                                                           \
      char* tanc__debug__message =                                           \
          tanc__format__format("assertion failed: %s", #stmt);               \
      tanc__backtrace__panic_handler(tanc__debug__message, file_(), line_(), \
                                     function_());                           \
    }                                                                        \
  } while (0)

/* clang-format off */
#include "libtanc/internal/cleanup.h"
/* clang-format on */

#endif
