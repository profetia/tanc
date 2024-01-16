#ifndef LIBTANC_FORMAT_H
#define LIBTANC_FORMAT_H

/* Ensure that this header is only used with GCC. */
#ifndef __GNUC__
#error "libtanc/backtrace.h requires GCC"
#endif

/* clang-format off */
#include "libtanc/internal/polyfill.h"
#include "libtanc/internal/module.h"
/* clang-format on */

/* Include the standard headers. */
#include <stdarg.h>
#include <stdio.h>

/**
 * @brief Format with a variadic argument list and allocate the result.
 * @param fmt The format string.
 * @param ... The variadic argument list.
 * @return The formatted string. It is the caller's responsibility to free the
 *        string.
 */
__inline__ __attribute__((format(printf, 1, 2))) char* module_(format)(format)(
    char const* fmt, ...) {
  /* Variadic argument list */
  va_list args;
  char* message = NULL;

  va_start(args, fmt);
  /* Format the message. */
  vasprintf(&message, fmt, args);
  va_end(args);
  return message;
}

/**
 * @brief Print with a variadic argument list to stdout.
 * @param fmt The format string.
 * @param ... The variadic argument list.
 * @return
 */
__inline__ __attribute__((format(printf, 1, 2))) void module_(format)(print)(
    char const* fmt, ...) {
  /* Variadic argument list */
  va_list args;

  va_start(args, fmt);
  /* Print the message. */
  vprintf(fmt, args);
  va_end(args);
}

/**
 * @brief Print with a variadic argument list to stderr.
 * @param fmt The format string.
 * @param ... The variadic argument list.
 * @return
 */
__inline__ __attribute__((format(printf, 1, 2))) void module_(format)(eprint)(
    char const* fmt, ...) {
  /* Variadic argument list */
  va_list args;

  va_start(args, fmt);
  /* Print the message. */
  vfprintf(stderr, fmt, args);
  va_end(args);
}

/**
 * @brief Format with a variadic argument list and allocate the result.
 * @param stmt The variadic argument list, e.g. ("foo %d", 42).
 * @return The formatted string. It is the caller's responsibility to free the
 *       string.
 */
#define format_(stmt) tanc__format__format stmt

/**
 * @brief Print with a variadic argument list to stdout.
 * @param stmt The variadic argument list, e.g. ("foo %d", 42).
 * @return
 */
#define print_(stmt) tanc__format__print stmt

/**
 * @brief Print with a variadic argument list and a newline to stdout.
 * @param stmt The variadic argument list, e.g. ("foo %d", 42).
 * @return
 */
#define println_(stmt)        \
  do {                        \
    tanc__format__print stmt; \
    putchar('\n');            \
  } while (0)

/**
 * @brief Print with a variadic argument list and a newline to stderr.
 * @param stmt The variadic argument list, e.g. ("foo %d", 42).
 * @return
 */
#define eprint_(stmt) tanc__format__eprint stmt

/**
 * @brief Print with a variadic argument list and a newline to stderr.
 * @param stmt The variadic argument list, e.g. ("foo %d", 42).
 * @return
 */
#define eprintln_(stmt)        \
  do {                         \
    tanc__format__eprint stmt; \
    putchar('\n');             \
  } while (0)

/* clang-format off */
#include "libtanc/internal/cleanup.h"
/* clang-format on */

#endif /* LIBTANC_FORMAT_H */
