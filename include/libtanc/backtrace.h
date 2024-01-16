#ifndef LIBTANC_BACKTRACE_H
#define LIBTANC_BACKTRACE_H

/* Ensure that this header is only used with GCC. */
#ifndef __GNUC__
#error "libtanc/backtrace.h requires GCC"
#endif

/* clang-format off */
#include "libtanc/internal/polyfill.h"
#include "libtanc/internal/module.h"
/* clang-format on */

/* Include the standard headers. */
#include <execinfo.h>
#include <inttypes.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ucontext.h>

/* Configure the backtrace module. */
#define MAX_BACKTRACE_DEPTH 128

/**
 * @brief Print a backtrace to the given `stream`.
 * @param stream The stream to print the backtrace to.
 * @return
 */
__inline__ void module_(backtrace)(print_backtrace)(FILE *stream) {
  /* Allocate a buffer for the backtrace. */
  void *buffer[MAX_BACKTRACE_DEPTH];
  /* Get the backtrace. */
  int32_t const depth = backtrace(buffer, MAX_BACKTRACE_DEPTH);
  /* Get the symbols for the backtrace. */
  char **symbols = backtrace_symbols(buffer, depth);

  int32_t i = 0;

  /* Start printing the backtrace. */
  fprintf(stream, "stack backtrace:\n");
  if (symbols == NULL) { /* Fallback to printing the addresses. */
    for (i = 0; i < depth; ++i) {
      fprintf(stream, "    %" PRId32 ": %p\n", i, buffer[i]);
    }
    return;
  }

  /* Print the backtrace. */
  for (i = 0; i < depth; ++i) {
    fprintf(stream, "    %" PRId32 ": %s\n", i, symbols[i]);
  }

  /* Free the symbols. */
  free(symbols);
}

/**
 * @brief Handle a panic with the given `message`, `file`, `line`, and
 *      `function`.
 * @param message The message of the panic.
 * @param file The file of the panic.
 * @param line The line of the panic.
 * @param function The function of the panic.
 * @return
 */
__inline__ void module_(backtrace)(panic_handler)(char const *message,
                                                  char const *file,
                                                  int32_t line,
                                                  char const *function) {
  /* Print the panic. */
  fprintf(stderr, "thread panicked at '%s', %s:%" PRId32 " %s\n", message, file,
          line, function);
  /* Print the backtrace. */
  module_(backtrace)(print_backtrace)(stderr);
  /* Abort the program. */
  abort();
}

/**
 * @brief Handle a signal with the given `signal`, `info`, and `uc`.
 * @param signal The signal to handle.
 * @param info The signal info.
 * @param uc The user context.
 * @return
 */
void module_(backtrace)(signal_handler)(int32_t signal, siginfo_t *info,
                                        void *uc __attribute__((unused))) {
  /* Format the message. */
  char *message = NULL;
  asprintf(&message, "signal %" PRId32 ": %s at %p", signal, strsignal(signal),
           info->si_addr);
  /* Handle the panic. */
  module_(backtrace)(panic_handler)(message, __FILE__, __LINE__,
                                    __builtin_FUNCTION());
}

/**
 * @brief Initialize the backtrace module.
 * @return
 */
__attribute__((constructor)) void module_(backtrace)(init)(void) {
  struct sigaction action;
  memset(&action, 0, sizeof(action));
  action.sa_sigaction = module_(backtrace)(signal_handler);
  action.sa_flags = SA_SIGINFO;
  sigaction(SIGSEGV, &action, NULL);
  sigaction(SIGBUS, &action, NULL);
  sigaction(SIGILL, &action, NULL);
  sigaction(SIGFPE, &action, NULL);
}

/* Cleanup for the backtrace module. */
#undef MAX_BACKTRACE_DEPTH

/* clang-format off */
#include "libtanc/internal/cleanup.h"
/* clang-format on */

#endif /* LIBTANC_BACKTRACE_H */
