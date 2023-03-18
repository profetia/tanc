#include "../tanc.h"

int main(void) {
  eprintf("Hello, world!\n");
  LOG_TRACE(("Hello, world!"));
  LOG_DEBUG(("Hello, world!"));
  LOG_INFO(("Hello, world!"));
  LOG_WARN(("Hello, world!"));
  LOG_FATAL(("Hello, world!"));
  return EXIT_SUCCESS;
}