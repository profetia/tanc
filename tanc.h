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
 */
typedef enum LogLevel {
  LOG_LEVEL_TRACE, /* TRACE */
  LOG_LEVEL_DEBUG, /* DEBUG */
  LOG_LEVEL_INFO,  /* INFO */
  LOG_LEVEL_WARN,  /* WARN */
  LOG_LEVEL_ERROR, /* ERROR */
  LOG_LEVEL_FATAL  /* FATAL */
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
static int log_is_enabled(LogLevel level) { return level >= LOG_LEVEL; }

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
    default: /* UNKNOWN */
      return "UNKNOWN";
  }
}

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
 * @brief Log the message body.
 * @param format Format string.
 * @param args Arguments to format string.
 * @return int Number of characters printed.
 * @note Log level will not be checked. DO NOT CALL THIS FUNCTION DIRECTLY.
 */
int vlog_message_body(const char* format, va_list args) {
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
int log_message_body(const char* format, ...) {
  /* Initializations */
  va_list args;
  int ret = 0;

  /* Write the message */
  va_start(args, format);
  ret = vlog_message_body(format, args);
  va_end(args);

  /* Return */
  return ret;
}

/**
 * @brief Log the message footer.
 * @return int Number of characters printed.
 * @note Log level will not be checked. DO NOT CALL THIS FUNCTION DIRECTLY.
 */
int log_message_footer() { return LOG_WRITE_HANDLER("\n"); }

/* Enabled only if NDEBUG is not defined */
#ifndef NDEBUG

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
                 const char* format, va_list args) {
  /* Initializations */
  int ret = 0;
  int size = 0;

  /* Check if the log level is enabled */
  if (!log_is_enabled(level)) {
    return 0;
  }

  /* Write the message header */
  size = log_message_header(level, file, line, func);
  if (size > 0) {
    ret += size;
  }

  /* Write the message */
  size = vlog_message_body(format, args);
  if (size > 0) {
    ret += size;
  }

  /* Write the newline */
  size = log_message_footer();
  if (size > 0) {
    ret += size;
  }

  /* Return */
  return ret;
}

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
                const char* format, ...) {
  /* Initializations */
  va_list args;
  int ret = 0;

  /* Write the message */
  va_start(args, format);
  ret = vlog_message(level, file, line, func, format, args);
  va_end(args);

  /* Return */
  return ret;
}

/**
 * @brief Log a message at the TRACE level.
 * @param body Body of the message. In the form of a printf format string and
 *  arguments, e.g. ("Hello %s", "world").
 */
#define LOG_TRACE(body)                                                  \
  do {                                                                   \
    if (log_is_enabled(LOG_LEVEL_TRACE)) { /* Check if is enabled */     \
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
    if (log_is_enabled(LOG_LEVEL_DEBUG)) { /* Check if is enabled */     \
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
    if (log_is_enabled(LOG_LEVEL_INFO)) { /* Check if is enabled */     \
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
    if (log_is_enabled(LOG_LEVEL_WARN)) { /* Check if is enabled */     \
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
    if (log_is_enabled(LOG_LEVEL_ERROR)) { /* Check if is enabled */     \
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
    if (log_is_enabled(LOG_LEVEL_FATAL)) { /* Check if is enabled */     \
      log_message_header(LOG_LEVEL_FATAL, __FILE__, __LINE__, __func__); \
      log_message_body body;                                             \
      log_message_footer();                                              \
      exit(EXIT_FAILURE);                                                \
    }                                                                    \
  } while (0)

/**
 * @brief Log a message at the DEBUG level, with the value of an expression.
 * @note This macro will not return the value of the expression, unlike the dbg!
 *  in Rust.
 */
#define DBG(format, expr) LOG_DEBUG((#expr " = " format, expr))

#else /* NDEBUG */

/* Disable logging in release mode */
int vlog_message(UNUSED LogLevel level, UNUSED const char* file,
                 UNUSED int line, UNUSED const char* func,
                 UNUSED const char* format, UNUSED va_list args) {
  return 0;
}

/* Disable logging in release mode */
int log_message(UNUSED LogLevel level, UNUSED const char* file, UNUSED int line,
                UNUSED const char* func, UNUSED const char* format, ...) {
  return 0;
}

#define LOG_TRACE(body)   /* Do nothing */
#define LOG_DEBUG(body)   /* Do nothing */
#define LOG_INFO(body)    /* Do nothing */
#define LOG_WARN(body)    /* Do nothing */
#define LOG_ERROR(body)   /* Do nothing */
#define LOG_FATAL(body)   /* Do nothing */
#define DBG(format, expr) /* Do nothing */

#endif /* NDEBUG */

#endif /* __TANC_H__ */