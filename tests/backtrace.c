
#include "libtanc/backtrace.h"

void bad_function(void) {
  char *p = (char *)0xdeadbeef;
  *p = 10;
}

void dummy_function(void) { bad_function(); }

int main(void) {
  dummy_function();
  return 0;
}