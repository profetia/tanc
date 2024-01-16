#include "libtanc/backtrace.h"

#include <stdio.h>

void bad_function(void) {
  char *p = (char *)0xdeadbeef;
  *p = 10;
}

void dummy_function(void) {
  backtrace_();
  printf("%s:%d %s\n", __FILE__, __LINE__, __builtin_FUNCTION());
  bad_function();
}

void dummy_caller(void (*fn)(void)) { fn(); }

void another_dummy_function(void) { dummy_caller(dummy_function); }

int main(void) {
  another_dummy_function();
  return 0;
}