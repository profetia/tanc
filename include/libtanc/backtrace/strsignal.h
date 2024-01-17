#ifndef LIBTANC_BACKTRACE_STRSIGNAL_H
#define LIBTANC_BACKTRACE_STRSIGNAL_H

/* Ensure that this header is only used with GCC. */
#ifndef __GNUC__
#error "libtanc/format/strsignal.h requires GCC"
#endif

#include <string.h>

/**
 * @brief Return the string representation of the given `signal`.
 * @param signal The signal to return the string representation of.
 * @return The string representation of the given `signal`.
 */
extern char *strsignal(int __sig) __THROW;

#endif /* LIBTANC_BACKTRACE_STRSIGNAL_H */
