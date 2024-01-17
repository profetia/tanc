#ifndef LIBTANC_FORMAT_SNPRINTF_H
#define LIBTANC_FORMAT_SNPRINTF_H

/* Ensure that this header is only used with GCC. */
#ifndef __GNUC__
#error "libtanc/format/snprintf.h requires GCC"
#endif

/* Include the standard headers. */
#include <stdarg.h>
#include <stdio.h>

/**
 * @brief Write formatted output to sized buffer.
 * @param __s Pointer to buffer.
 * @param __maxlen Maximum number of bytes to write.
 * @param __format Format string.
 * @param ... Arguments.
 * @return Number of bytes written, or -1 on error.
 */
extern int snprintf(char *__restrict __s, size_t __maxlen,
                    const char *__restrict __format, ...) __THROWNL
    __attribute__((__format__(__printf__, 3, 4)));

/**
 * @brief Write formatted output to sized buffer.
 * @param __s Pointer to buffer.
 * @param __maxlen Maximum number of bytes to write.
 * @param __format Format string.
 * @param __arg Arguments.
 * @return Number of bytes written, or -1 on error.
 */
extern int vsnprintf(char *__restrict __s, size_t __maxlen,
                     const char *__restrict __format,
                     __gnuc_va_list __arg) __THROWNL
    __attribute__((__format__(__printf__, 3, 0)));

#endif /* LIBTANC_FORMAT_SNPRINTF_H */
