#ifndef LIBTANC_BACKTRACE_SIGNAL_HANDLER_H
#define LIBTANC_BACKTRACE_SIGNAL_HANDLER_H

/* Ensure that this header is only used with GCC. */
#ifndef __GNUC__
#error "libtanc/backtrace/signal_handler.h requires GCC"
#endif

/* Include the standard headers. */
#include <inttypes.h>
#include <stdlib.h>

/* Include the libtanc headers. */
#include "libtanc/backtrace/panic_handler.h"
#include "libtanc/backtrace/strsignal.h"
#include "libtanc/debug/file.h"
#include "libtanc/format/asprintf.h"

/**
 * @brief Handle a signal with the given `signal`, `info`, and `uc`.
 * @param signal The signal to handle.
 * @param info The signal info.
 * @param uc The user context.
 * @return
 */
void tanc__backtrace__signal_handler(int32_t signal) {
  /* Format the message. */
  char *message = NULL;
  asprintf(&message, "signal %" PRId32 ": %s", signal, strsignal(signal));
  /* Handle the panic. */
  tanc__backtrace__panic_handler(message, file_(), line_(), function_());
}

#endif /* LIBTANC_BACKTRACE_SIGNAL_HANDLER_H */
