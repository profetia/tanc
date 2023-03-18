#include <stdarg.h>

/**
 * @brief Specific write handler to be used when logging.
 *  By default, this is set to veprintf.
 */
#define VLOG_WRITE_HANDLER veprintf

/**
 * @brief Specific write handler to be used when logging.
 *  By default, this is set to eprintf.
 */
#define LOG_WRITE_HANDLER eprintf

/**
 * @brief Log level to be used when logging.
 *  By default, this is set to LOG_LEVEL_INFO.
 */
#define LOG_LEVEL LOG_LEVEL_INFO

/**
 * @brief Disable logging and assertions.
 *  This will disable all logging macros and assert from <assert.h>.
 */
/* #define NDEBUG */