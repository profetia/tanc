#ifndef LIBTANC_DEBUG_TODO_H
#define LIBTANC_DEBUG_TODO_H

/* Ensure that this header is only used with GCC. */
#ifndef __GNUC__
#error "libtanc/debug/todo.h requires GCC"
#endif

/* Include the libtanc headers. */
#include "libtanc/backtrace/panic_handler.h"
#include "libtanc/format/format.h"

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

#endif /* LIBTANC_DEBUG_TODO_H */
