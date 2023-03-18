#include "tanc.h"

int veprintf(const char* format, va_list args) {
  /* Forward to vfprintf */
  return vfprintf(stderr, format, args);
}

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

int log_is_enabled(LogLevel level) { return level >= LOG_LEVEL; }

char* log_level_to_string(LogLevel level) {
  switch (level) {
    case LOG_LEVEL_TRACE:
      return "TRACE";
    case LOG_LEVEL_DEBUG:
      return "DEBUG";
    case LOG_LEVEL_INFO:
      return "INFO";
    case LOG_LEVEL_WARN:
      return "WARN";
    case LOG_LEVEL_ERROR:
      return "ERROR";
    case LOG_LEVEL_FATAL:
      return "FATAL";
    default:
      return "UNKNOWN";
  }
}

int log_message_header(LogLevel level, const char* file, int line,
                       const char* func) {
  /* Initializations */
  char* level_str = log_level_to_string(level);

  /* Write the message header */
  return LOG_WRITE_HANDLER("[%s] %s:%d (%s): ", level_str, file, line, func);
}

int vlog_message_body(const char* format, va_list args) {
  /* Write the message */
  return VLOG_WRITE_HANDLER(format, args);
}

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

int log_message_footer() { return LOG_WRITE_HANDLER("\n"); }

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

  return ret;
}

int log_message(LogLevel level, const char* file, int line, const char* func,
                const char* format, ...) {
  /* Initializations */
  va_list args;
  int ret = 0;

  /* Write the message */
  va_start(args, format);
  ret = vlog_message(level, file, line, func, format, args);
  va_end(args);

  return ret;
}
