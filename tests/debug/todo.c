
#include "libtanc/debug.h"

void bad_function(void) {
  char *p = (char *)0xdeadbeef;
  todo_(("Fuck %p", p));
}

void dummy_function(void) { bad_function(); }

void dummy_caller(void (*fn)(void)) { fn(); }

void another_dummy_function(void) { dummy_caller(dummy_function); }

int main(void) {
  another_dummy_function();
  return 0;
}