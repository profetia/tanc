#include <stdarg.h>

/**
 * @brief Specific write handler to be used when logging.
 *  By default, this is set to eprintf.
 */
#define LOG_WRITE_HANDLER eprintf

/**
 * @brief Specific write handler to be used when logging.
 *  By default, this is set to veprintf.
 */
/* #define VLOG_WRITE_HANDLER veprintf */

/**
 * @brief Log level to be used when logging.
 *  By default, this is set to LOG_LEVEL_INFO.
 */
#define LOG_LEVEL LOG_LEVEL_INFO
