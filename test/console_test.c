#include "../tanc.h"

int main(void) {
  UNUSED int a = 1;
  UNUSED __typeof__(a) b = (a++, 2);

  eprintf("Hello, world!\n");
  if (DBG("%d", b == 2)) {
    eprintf("Hi, Mum!\n");
  }

  LOG_TRACE(("Hello, world!"));
  LOG_DEBUG(("Hello, world!"));
  LOG_INFO(("Hello, world!"));
  LOG_WARN(("Hello, world!"));
  LOG_FATAL(("Hello, world!"));
  return EXIT_SUCCESS;
}