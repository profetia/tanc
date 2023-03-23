#include "../tanc.h"

int main(void) {
  UNUSED int a = 1;

  UNUSED typeof(a) b = (a++, BIN(1111_1111_1111_1111_1111_1111_1111_1110));

  /* assert(a != 0); */

  eprintf("Hello, world!\n");
  if (DBG("%d", a << 1)) {
    eprintf("Hi, Mum!\n");
  }

  DBGL("%d", b);

  LOG_TRACE(("Hello, world!"));
  LOG_DEBUG(("Hello, world!"));
  LOG_INFO(("Hello, world!"));
  LOG_WARN(("Hello, world!"));
  LOG_FATAL(("Hello, world!"));
  return EXIT_SUCCESS;
}