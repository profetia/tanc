#ifndef LIBTANC_BACKTRACE_BACKTRACE_H
#define LIBTANC_BACKTRACE_BACKTRACE_H

/* Ensure that this header is only used with GCC. */
#ifndef __GNUC__
#error "libtanc/backtrace/backtrace.h requires GCC"
#endif

/* Include the standard headers. */
#include <execinfo.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/* Configure the backtrace module. */
#define MAX_BACKTRACE_DEPTH 128

/**
 * @brief Print a backtrace to the given `stream`.
 * @param stream The stream to print the backtrace to.
 * @return
 */
__inline__ void tanc__backtrace__backtrace(FILE *stream) {
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
 * @brief Print backtrace to stderr.
 * @return
 */
#define backtrace_() tanc__backtrace__backtrace(stderr)

/* Cleanup for the backtrace module. */
#undef MAX_BACKTRACE_DEPTH

#endif /* LIBTANC_BACKTRACE_BACKTRACE_H */
