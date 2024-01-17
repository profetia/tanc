#ifndef LIBTANC_FORMAT_PRINT_H
#define LIBTANC_FORMAT_PRINT_H

/* Ensure that this header is only used with GCC. */
#ifndef __GNUC__
#error "libtanc/format/print.h requires GCC"
#endif

/* Include the standard headers. */
#include <stdarg.h>
#include <stdio.h>

/**
 * @brief Print with a variadic argument list to stdout.
 * @param fmt The format string.
 * @param ... The variadic argument list.
 * @return
 */
__inline__ __attribute__((format(printf, 1, 2))) void tanc__format__print(
    char const* fmt, ...) {
  /* Variadic argument list */
  va_list args;

  va_start(args, fmt);
  /* Print the message. */
  vprintf(fmt, args);
  va_end(args);
}

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

#endif /* LIBTANC_FORMAT_PRINT_H */
