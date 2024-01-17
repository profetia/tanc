#ifndef LIBTANC_BACKTRACE_INIT_H
#define LIBTANC_BACKTRACE_INIT_H

/* Ensure that this header is only used with GCC. */
#ifndef __GNUC__
#error "libtanc/backtrace/init.h requires GCC"
#endif

/* Include the standard headers. */
#include <signal.h>

/* Include the libtanc headers. */
#include "libtanc/backtrace/signal_handler.h"

/**
 * @brief Initialize the backtrace module.
 * @return
 */
__attribute__((constructor)) void tanc__backtrace__init(void) {
  signal(SIGSEGV, tanc__backtrace__signal_handler);
  signal(SIGBUS, tanc__backtrace__signal_handler);
  signal(SIGILL, tanc__backtrace__signal_handler);
  signal(SIGFPE, tanc__backtrace__signal_handler);
}

#endif /* LIBTANC_BACKTRACE_INIT_H */
