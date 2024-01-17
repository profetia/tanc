#ifndef LIBTANC_DEBUG_ASSERT_H
#define LIBTANC_DEBUG_ASSERT_H

/* Ensure that this header is only used with GCC. */
#ifndef __GNUC__
#error "libtanc/debug/assert.h requires GCC"
#endif

/* Include the libtanc headers. */
#include "libtanc/backtrace/panic_handler.h"
#include "libtanc/format/format.h"

/**
 * @brief Asserts that the statement is true, otherwise panics with a message
 *       of "assertion failed: <stmt>".
 * @param stmt The statement to assert.
 * @return
 */
#define assert_(stmt)                                                        \
  do {                                                                       \
    if (!(stmt)) {                                                           \
      char* tanc__debug__message =                                           \
          tanc__format__format("assertion failed: %s", #stmt);               \
      tanc__backtrace__panic_handler(tanc__debug__message, file_(), line_(), \
                                     function_());                           \
    }                                                                        \
  } while (0)

#endif /* LIBTANC_DEBUG_ASSERT_H */
