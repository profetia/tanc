#ifndef __TANC_H__
#define __TANC_H__

#include <stdio.h>
#include <stdlib.h>

#include "tanc.conf.h"

/* GCC specific attributes */
#define UNUSED __attribute__((unused))
#define NORETURN __attribute__((noreturn))
#define NODISCARD __attribute__((warn_unused_result))

/* Polyfill for __func__ */
#if __STDC_VERSION__ < 199901L
#if __GNUC__ >= 2 && defined(__FUNCTION__)
#define __func__ __FUNCTION__
#else /* !__GNUC__ */
#define __func__ "<unknown>"
#endif
#endif

/**
 * @brief Variadic eprinf.
 * @param format Format string.
 * @param args Arguments to format string.
 * @return int Number of characters printed.
 */
int veprintf(const char* format, va_list args);

/**
 * @brief Printf on stderr.
 * @param format Format string.
 * @param ... Arguments to format string.
 * @return int Number of characters printed.
 */
int eprintf(const char* format, ...);

/**
 * @brief Levels of logging.
 *  LOG_LEVEL_TRACE: 0.
 *  LOG_LEVEL_DEBUG: 1.
 *  LOG_LEVEL_INFO:  2.
 *  LOG_LEVEL_WARN:  3.
 *  LOG_LEVEL_ERROR: 4.
 *  LOG_LEVEL_FATAL: 5.
 */
typedef enum LogLevel {
  LOG_LEVEL_TRACE,
  LOG_LEVEL_DEBUG,
  LOG_LEVEL_INFO,
  LOG_LEVEL_WARN,
  LOG_LEVEL_ERROR,
  LOG_LEVEL_FATAL
} LogLevel;

/**
 * @brief Write handler for logging.
 *  This function is called by the logging macros to write the log message.
 */
typedef int (*VLogWriteHandler)(const char* format, va_list args);

/**
 * @brief Write handler for logging.
 *  This function is called by the logging macros to write the log message.
 */
typedef int (*LogWriteHandler)(const char* format, ...);

/**
 * @brief Check if a log level is enabled
 * @param level The log level to check
 * @return 1 if the log level is enabled, 0 otherwise
 */
int log_is_enabled(LogLevel level);

/**
 * @brief Convert a log level to a string
 * @param level The log level to convert
 * @return The string representation of the log level
 */
char* log_level_to_string(LogLevel level);

/**
 * @brief Log the message header.
 * @param level Level of the message.
 * @param file File where the message was logged.
 * @param line Line where the message was logged.
 * @param func Function where the message was logged.
 * @return int Number of characters printed.
 * @note Log level will not be checked. DO NOT CALL THIS FUNCTION DIRECTLY.
 */
int log_message_header(LogLevel level, const char* file, int line,
                       const char* func);

/**
 * @brief Log the message body.
 * @param format Format string.
 * @param args Arguments to format string.
 * @return int Number of characters printed.
 * @note Log level will not be checked. DO NOT CALL THIS FUNCTION DIRECTLY.
 */
int vlog_message_body(const char* format, va_list args);

/**
 * @brief Log the message body.
 * @param format Format string.
 * @param ... Arguments to format string.
 * @return int Number of characters printed.
 * @note Log level will not be checked. DO NOT CALL THIS FUNCTION DIRECTLY.
 */
int log_message_body(const char* format, ...);

/**
 * @brief Log the message footer.
 * @return int Number of characters printed.
 * @note Log level will not be checked. DO NOT CALL THIS FUNCTION DIRECTLY.
 */
int log_message_footer(void);

/**
 * @brief Log a message.
 * @param level Level of the message.
 * @param file File where the message was logged.
 * @param line Line where the message was logged.
 * @param func Function where the message was logged.
 * @param format Format string.
 * @param args Arguments to format string.
 * @return int Number of characters printed.
 */
int vlog_message(LogLevel level, const char* file, int line, const char* func,
                 const char* format, va_list args);

/**
 * @brief Log a message.
 * @param level Level of the message.
 * @param file File where the message was logged.
 * @param line Line where the message was logged.
 * @param func Function where the message was logged.
 * @param format Format string.
 * @param ... Arguments to format string.
 * @return int Number of characters printed.
 */
int log_message(LogLevel level, const char* file, int line, const char* func,
                const char* format, ...);

#ifdef NDEBUG
#define LOG_TRACE(body)
#define LOG_DEBUG(body)
#define LOG_INFO(body)
#define LOG_WARN(body)
#define LOG_ERROR(body)
#define LOG_FATAL(body)
#else

/**
 * @brief Log a message at the TRACE level.
 * @param body Body of the message. In the form of a printf format string and
 *  arguments, e.g. ("Hello %s", "world").
 */
#define LOG_TRACE(body)                                                  \
  do {                                                                   \
    if (log_is_enabled(LOG_LEVEL_TRACE)) {                               \
      log_message_header(LOG_LEVEL_TRACE, __FILE__, __LINE__, __func__); \
      log_message_body body;                                             \
      log_message_footer();                                              \
    }                                                                    \
  } while (0)

/**
 * @brief Log a message at the DEBUG level.
 * @param body Body of the message. In the form of a printf format string and
 *  arguments, e.g. ("Hello %s", "world").
 */
#define LOG_DEBUG(body)                                                  \
  do {                                                                   \
    if (log_is_enabled(LOG_LEVEL_DEBUG)) {                               \
      log_message_header(LOG_LEVEL_DEBUG, __FILE__, __LINE__, __func__); \
      log_message_body body;                                             \
      log_message_footer();                                              \
    }                                                                    \
  } while (0)

/**
 * @brief Log a message at the INFO level.
 * @param body Body of the message. In the form of a printf format string and
 *  arguments, e.g. ("Hello %s", "world").
 */
#define LOG_INFO(body)                                                  \
  do {                                                                  \
    if (log_is_enabled(LOG_LEVEL_INFO)) {                               \
      log_message_header(LOG_LEVEL_INFO, __FILE__, __LINE__, __func__); \
      log_message_body body;                                            \
      log_message_footer();                                             \
    }                                                                   \
  } while (0)

/**
 * @brief Log a message at the WARN level.
 * @param body Body of the message. In the form of a printf format string and
 *  arguments, e.g. ("Hello %s", "world").
 */
#define LOG_WARN(body)                                                  \
  do {                                                                  \
    if (log_is_enabled(LOG_LEVEL_WARN)) {                               \
      log_message_header(LOG_LEVEL_WARN, __FILE__, __LINE__, __func__); \
      log_message_body body;                                            \
      log_message_footer();                                             \
    }                                                                   \
  } while (0)

/**
 * @brief Log a message at the ERROR level.
 * @param body Body of the message. In the form of a printf format string and
 *  arguments, e.g. ("Hello %s", "world").
 */
#define LOG_ERROR(body)                                                  \
  do {                                                                   \
    if (log_is_enabled(LOG_LEVEL_ERROR)) {                               \
      log_message_header(LOG_LEVEL_ERROR, __FILE__, __LINE__, __func__); \
      log_message_body body;                                             \
      log_message_footer();                                              \
    }                                                                    \
  } while (0)

/**
 * @brief Log a message at the FATAL level.
 * @param body Body of the message. In the form of a printf format string and
 *  arguments, e.g. ("Hello %s", "world").
 * @note This macro will call exit(EXIT_FAILURE) after logging the message.
 */
#define LOG_FATAL(body)                                                  \
  do {                                                                   \
    if (log_is_enabled(LOG_LEVEL_FATAL)) {                               \
      log_message_header(LOG_LEVEL_FATAL, __FILE__, __LINE__, __func__); \
      log_message_body body;                                             \
      log_message_footer();                                              \
      exit(EXIT_FAILURE);                                                \
    }                                                                    \
  } while (0)

#define DBG(format, expr) LOG_DEBUG((#expr " = " format, expr))

#endif /* NDEBUG */

#endif /* __TANC_H__ */