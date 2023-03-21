#ifndef __TANC_H__
#define __TANC_H__

#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "tanc.conf.h"

/* GCC specific attributes */
#define UNUSED __attribute__((unused))
#define NORETURN __attribute__((noreturn))
#define NODISCARD __attribute__((warn_unused_result))

/* Common macros */
#define STATIC_CAST(type, expr) ((type)(expr))

/* Polyfill for __func__ */
#if __STDC_VERSION__ < 199901L
#if __GNUC__ >= 2 && defined(__FUNCTION__)
#define __func__ __FUNCTION__
#else /* !__GNUC__ */
#define __func__ "<unknown>"
#endif /* __GNUC__ */
#endif /* __STDC_VERSION__ */

/* Polyfill for typeof */
#if __STDC_VERSION__ < 199901L && defined(__GNUC__)
#define typeof __typeof__
#endif

/**
 * @brief Variadic eprinf.
 * @param format Format string.
 * @param args Arguments to format string.
 * @return int Number of characters printed.
 */
int veprintf(const char* format, va_list args) {
  /* Forward to vfprintf */
  return vfprintf(stderr, format, args);
}

/**
 * @brief Printf on stderr.
 * @param format Format string.
 * @param ... Arguments to format string.
 * @return int Number of characters printed.
 */
int eprintf(const char* format, ...) {
  /* Initializations */
  va_list args;
  int ret = 0;

  /* Print to stderr */
  va_start(args, format);
  ret = veprintf(format, args);
  va_end(args);

  /* Return */
  return ret;
}

/**
 * @brief Levels of logging.
 *  LOG_LEVEL_TRACE: 0.
 *  LOG_LEVEL_DEBUG: 1.
 *  LOG_LEVEL_INFO:  2.
 *  LOG_LEVEL_WARN:  3.
 *  LOG_LEVEL_ERROR: 4.
 *  LOG_LEVEL_FATAL: 5.
 *  LOG_LEVEL_NONE:  6.
 */
typedef enum LogLevel {
  LOG_LEVEL_TRACE,             /* TRACE */
#define TANC_LOG_LEVEL_TRACE 0 /* TRACE = 0 */
  LOG_LEVEL_DEBUG,             /* DEBUG */
#define TANC_LOG_LEVEL_DEBUG 1 /* DEBUG = 1 */
  LOG_LEVEL_INFO,              /* INFO */
#define TANC_LOG_LEVEL_INFO 2  /* INFO = 2 */
  LOG_LEVEL_WARN,              /* WARN */
#define TANC_LOG_LEVEL_WARN 3  /* WARN = 3 */
  LOG_LEVEL_ERROR,             /* ERROR */
#define TANC_LOG_LEVEL_ERROR 4 /* ERROR = 4 */
  LOG_LEVEL_FATAL,             /* FATAL */
#define TANC_LOG_LEVEL_FATAL 5 /* FATAL = 5 */
  LOG_LEVEL_NONE               /* NONE */
#define TANC_LOG_LEVEL_NONE 6  /* NONE = 6 */
} LogLevel;

/**
 * @brief Write handler for logging.
 * This function is called by the logging macros to write the log message.
 */
typedef int (*VLogWriteHandler)(const char* format, va_list args);

/**
 * @brief Write handler for logging.
 * This function is called by the logging macros to write the log message.
 */
typedef int (*LogWriteHandler)(const char* format, ...);

/**
 * @brief Check if a log level is enabled
 * @param level The log level to check
 * @return 1 if the log level is enabled, 0 otherwise
 */
int log_is_enabled(LogLevel level) { return level >= LOG_LEVEL; }

/**
 * @brief Convert a log level to a string
 * @param level The log level to convert
 * @return The string representation of the log level
 */
static char* log_level_to_string(LogLevel level) {
  switch (level) {
    case LOG_LEVEL_TRACE: /* TRACE */
      return "TRACE";
    case LOG_LEVEL_DEBUG: /* DEBUG */
      return "DEBUG";
    case LOG_LEVEL_INFO: /* INFO */
      return "INFO";
    case LOG_LEVEL_WARN: /* WARN */
      return "WARN";
    case LOG_LEVEL_ERROR: /* ERROR */
      return "ERROR";
    case LOG_LEVEL_FATAL: /* FATAL */
      return "FATAL";
    case LOG_LEVEL_NONE: /* NONE */
      return "NONE";
    default: /* UNKNOWN */
      return "UNKNOWN";
  }
}

/* Polyfill for the optional VLOG_WRITE_HANDLER */
#ifndef LOG_WRITE_HANDLER
#ifdef VLOG_WRITE_HANDLER

/**
 * @brief Log the message body.
 * @param format Format string.
 * @param args Arguments to format string.
 * @return int Number of characters printed.
 * @note Log level will not be checked. DO NOT CALL THIS FUNCTION DIRECTLY.
 */
int vlog_message(const char* format, va_list args) {
  /* Write the message */
  return VLOG_WRITE_HANDLER(format, args);
}

/**
 * @brief Log the message body.
 * @param format Format string.
 * @param ... Arguments to format string.
 * @return int Number of characters printed.
 * @note Log level will not be checked. DO NOT CALL THIS FUNCTION DIRECTLY.
 */
int log_message(const char* format, ...) {
  /* Initializations */
  va_list args;
  int ret = 0;

  /* Write the message */
  va_start(args, format);
  ret = vlog_message(format, args);
  va_end(args);

  /* Return */
  return ret;
}

/* Define LOG_WRITE_HANDLER as the polyfill */
#define LOG_WRITE_HANDLER log_message
#else /* !VLOG_WRITE_HANDLER */
#error "LOG_WRITE_HANDLER or VLOG_WRITE_HANDLER must be defined"
#endif /* VLOG_WRITE_HANDLER */
#endif /* !LOG_WRITE_HANDLER */

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
                       const char* func) {
  /* Initializations */
  char* level_str = log_level_to_string(level);

  /* Write the message header */
  return LOG_WRITE_HANDLER("[%s] %s:%d (%s): ", level_str, file, line, func);
}

/**
 * @brief Log the message footer.
 * @return int Number of characters printed.
 * @note Log level will not be checked. DO NOT CALL THIS FUNCTION DIRECTLY.
 */
int log_message_footer() { return LOG_WRITE_HANDLER("\n"); }

/* Disable assertions if LOG_LEVEL is not DEBUG */
#if LOG_LEVEL > TANC_LOG_LEVEL_DEBUG
#define NDEBUG
#endif

/* Disable logging if LOG_LEVEL is NONE */
#if LOG_LEVEL < TANC_LOG_LEVEL_NONE
/**
 * @brief Log a message at the TRACE level.
 * @param body Body of the message. In the form of a printf format string and
 * arguments, e.g. ("Hello %s", "world").
 */
#define LOG_TRACE(body)                                                  \
  do {                                                                   \
    if (log_is_enabled(LOG_LEVEL_TRACE)) { /* Check if is enabled */     \
      log_message_header(LOG_LEVEL_TRACE, __FILE__, __LINE__, __func__); \
      LOG_WRITE_HANDLER body;                                            \
      log_message_footer();                                              \
    }                                                                    \
  } while (0)

/**
 * @brief Log a message at the DEBUG level.
 * @param body Body of the message. In the form of a printf format string and
 * arguments, e.g. ("Hello %s", "world").
 */
#define LOG_DEBUG(body)                                                  \
  do {                                                                   \
    if (log_is_enabled(LOG_LEVEL_DEBUG)) { /* Check if is enabled */     \
      log_message_header(LOG_LEVEL_DEBUG, __FILE__, __LINE__, __func__); \
      LOG_WRITE_HANDLER body;                                            \
      log_message_footer();                                              \
    }                                                                    \
  } while (0)

/**
 * @brief Log a message at the INFO level.
 * @param body Body of the message. In the form of a printf format string and
 * arguments, e.g. ("Hello %s", "world").
 */
#define LOG_INFO(body)                                                  \
  do {                                                                  \
    if (log_is_enabled(LOG_LEVEL_INFO)) { /* Check if is enabled */     \
      log_message_header(LOG_LEVEL_INFO, __FILE__, __LINE__, __func__); \
      LOG_WRITE_HANDLER body;                                           \
      log_message_footer();                                             \
    }                                                                   \
  } while (0)

/**
 * @brief Log a message at the WARN level.
 * @param body Body of the message. In the form of a printf format string and
 * arguments, e.g. ("Hello %s", "world").
 */
#define LOG_WARN(body)                                                  \
  do {                                                                  \
    if (log_is_enabled(LOG_LEVEL_WARN)) { /* Check if is enabled */     \
      log_message_header(LOG_LEVEL_WARN, __FILE__, __LINE__, __func__); \
      LOG_WRITE_HANDLER body;                                           \
      log_message_footer();                                             \
    }                                                                   \
  } while (0)

/**
 * @brief Log a message at the ERROR level.
 * @param body Body of the message. In the form of a printf format string and
 * arguments, e.g. ("Hello %s", "world").
 */
#define LOG_ERROR(body)                                                  \
  do {                                                                   \
    if (log_is_enabled(LOG_LEVEL_ERROR)) { /* Check if is enabled */     \
      log_message_header(LOG_LEVEL_ERROR, __FILE__, __LINE__, __func__); \
      LOG_WRITE_HANDLER body;                                            \
      log_message_footer();                                              \
    }                                                                    \
  } while (0)

/**
 * @brief Log a message at the FATAL level.
 * @param body Body of the message. In the form of a printf format string and
 * arguments, e.g. ("Hello %s", "world").
 * @note This macro will call exit(EXIT_FAILURE) after logging the message.
 */
#define LOG_FATAL(body)                                                  \
  do {                                                                   \
    if (log_is_enabled(LOG_LEVEL_FATAL)) { /* Check if is enabled */     \
      log_message_header(LOG_LEVEL_FATAL, __FILE__, __LINE__, __func__); \
      LOG_WRITE_HANDLER body;                                            \
      log_message_footer();                                              \
      exit(EXIT_FAILURE);                                                \
    }                                                                    \
  } while (0)

/**
 * @brief Log a message at the DEBUG level, with the value of an expression.
 * @note This macro will return the value of the expression. It cannot be
 * discarded, so you have to use it in a statement. Otherwise, use LOG_DEBUG
 * instead.
 */
#define DBG(format, expr)                                                     \
  ((log_is_enabled(LOG_LEVEL_DEBUG)                                           \
        ? (log_message_header(LOG_LEVEL_DEBUG, __FILE__, __LINE__, __func__), \
           LOG_WRITE_HANDLER(#expr " = " format " (%s)", (expr), format),     \
           log_message_footer())                                              \
        : 0),                                                                 \
   (expr))

#else /* LOG_LEVEL >= LOG_LEVEL_NONE */

#define LOG_TRACE(body)          /* Do nothing */
#define LOG_DEBUG(body)          /* Do nothing */
#define LOG_INFO(body)           /* Do nothing */
#define LOG_WARN(body)           /* Do nothing */
#define LOG_ERROR(body)          /* Do nothing */
#define LOG_FATAL(body)          /* Do nothing */
#define DBG(format, expr) (expr) /* Do nothing */

#endif /* LOG_LEVEL < LOG_LEVEL_NONE */

#endif /* __TANC_H__ */