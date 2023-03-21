#include "../tanc.h"

int main(void) {
  UNUSED int a = BIN(11111111111111111111111111111111);
  UNUSED typeof(a) b = (a++, 2);

  eprintf("Hello, world!\n");
  if (DBG("%d", b >> 1)) {
    eprintf("Hi, Mum!\n");
  }

  LOG_TRACE(("Hello, world!"));
  LOG_DEBUG(("Hello, world!"));
  LOG_INFO(("Hello, world!"));
  LOG_WARN(("Hello, world!"));
  LOG_FATAL(("Hello, world!"));
  return EXIT_SUCCESS;
}