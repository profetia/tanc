#ifndef LIBTANC_FORMAT_FORMAT_H
#define LIBTANC_FORMAT_FORMAT_H

/* Ensure that this header is only used with GCC. */
#ifndef __GNUC__
#error "libtanc/format/format.h requires GCC"
#endif

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
__inline__ __attribute__((format(printf, 1, 2))) char* tanc__format__format(
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
 * @brief Format with a variadic argument list and allocate the result.
 * @param stmt The variadic argument list, e.g. ("foo %d", 42).
 * @return The formatted string. It is the caller's responsibility to free the
 *       string.
 */
#define format_(stmt) tanc__format__format stmt

#endif /* LIBTANC_FORMAT_FORMAT_H */
