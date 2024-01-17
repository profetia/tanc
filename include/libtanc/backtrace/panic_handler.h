#ifndef LIBTANC_BACKTRACE_PANIC_HANDLER_H
#define LIBTANC_BACKTRACE_PANIC_HANDLER_H

/* Ensure that this header is only used with GCC. */
#ifndef __GNUC__
#error "libtanc/backtrace/panic_handler.h requires GCC"
#endif

/* Include the standard headers. */
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* Include the libtanc headers. */
#include "libtanc/backtrace/backtrace.h"

/**
 * @brief Handle a panic with the given `message`, `file`, `line`, and
 *      `function`.
 * @param message The message of the panic.
 * @param file The file of the panic.
 * @param line The line of the panic.
 * @param function The function of the panic.
 * @return
 */
__inline__ void tanc__backtrace__panic_handler(char const *message,
                                               char const *file, int32_t line,
                                               char const *function) {
  /* Print the panic. */
  fprintf(stderr, "thread panicked at '%s', %s:%" PRId32 " %s\n", message, file,
          line, function);
  /* Print the backtrace. */
  backtrace_();
  /* Abort the program. */
  abort();
}

#endif /* LIBTANC_BACKTRACE_PANIC_HANDLER_H */
