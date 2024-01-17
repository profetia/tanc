#ifndef LIBTANC_FORMAT_ASPRINTF_H
#define LIBTANC_FORMAT_ASPRINTF_H

/* Ensure that this header is only used with GCC. */
#ifndef __GNUC__
#error "libtanc/format/asprintf.h requires GCC"
#endif

/* Include the standard headers. */
#include <stdarg.h>
#include <stdio.h>

/**
 * @brief Write formatted output to allocated buffer.
 * @param __ptr Pointer to buffer.
 * @param __f Format string.
 * @param ... Arguments.
 * @return Number of bytes written, or -1 on error.
 */
extern int vasprintf(char **__restrict __ptr, const char *__restrict __f,
                     __gnuc_va_list __arg) __THROWNL
    __attribute__((__format__(__printf__, 2, 0))) __wur;

/**
 * @brief Write formatted output to allocated buffer.
 * @param __ptr Pointer to buffer.
 * @param __fmt Format string.
 * @param ... Arguments.
 * @return Number of bytes written, or -1 on error.
 */
extern int asprintf(char **__restrict __ptr, const char *__restrict __fmt,
                    ...) __THROWNL
    __attribute__((__format__(__printf__, 2, 3))) __wur;

#endif /* LIBTANC_FORMAT_ASPRINTF_H */
