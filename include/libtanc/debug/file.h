#ifndef LIBTANC_DEBUG_FILE_H
#define LIBTANC_DEBUG_FILE_H

/* Ensure that this header is only used with GCC. */
#ifndef __GNUC__
#error "libtanc/debug/file.h requires GCC"
#endif

/**
 * @brief Return the file name.
 * @return The file name.
 */
#define file_() __FILE__

/**
 * @brief Return the line number.
 * @return The line number.
 */
#define line_() __LINE__

/**
 * @brief Return the function name.
 * @return The function name.
 */
#define function_() __builtin_FUNCTION()

#endif /* LIBTANC_DEBUG_FILE_H */
