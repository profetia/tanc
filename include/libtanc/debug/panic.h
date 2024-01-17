#ifndef LIBTANC_DEBUG_PANIC_H
#define LIBTANC_DEBUG_PANIC_H

/* Ensure that this header is only used with GCC. */
#ifndef __GNUC__
#error "libtanc/debug/panic.h requires GCC"
#endif

/* Include the libtanc headers. */
#include "libtanc/backtrace/panic_handler.h"
#include "libtanc/format/format.h"

/**
 * @brief Panic with the variadic argument list.
 * @param stmt The variadic argument list, e.g. ("foo %d", 42).
 * @return
 */
#define panic_(stmt)                                                       \
  do {                                                                     \
    char* tanc__debug__message = tanc__format__format stmt;                \
    tanc__backtrace__panic_handler(tanc__debug__message, file_(), line_(), \
                                   function_());                           \
  } while (0)

#endif /* LIBTANC_DEBUG_PANIC_H */
