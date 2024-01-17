#ifndef LIBTANC_FORMAT_EPRINT_H
#define LIBTANC_FORMAT_EPRINT_H

/* Ensure that this header is only used with GCC. */
#ifndef __GNUC__
#error "libtanc/format/eprint.h requires GCC"
#endif

/* Include the standard headers. */
#include <stdarg.h>
#include <stdio.h>

/**
 * @brief Print with a variadic argument list to stderr.
 * @param fmt The format string.
 * @param ... The variadic argument list.
 * @return
 */
__inline__ __attribute__((format(printf, 1, 2))) void tanc__format__eprint(
    char const* fmt, ...) {
  /* Variadic argument list */
  va_list args;

  va_start(args, fmt);
  /* Print the message. */
  vfprintf(stderr, fmt, args);
  va_end(args);
}

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

#endif /* LIBTANC_FORMAT_EPRINT_H */
