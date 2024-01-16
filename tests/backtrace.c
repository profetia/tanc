/* clang-format off */
#include "libtanc.h"
/* clang-format on */

#include <stdio.h>

void dummy_function(void) {
  backtrace_();
  printf("%s:%d %s\n", __FILE__, __LINE__, function_());
}

void dummy_caller(void (*fn)(void)) { fn(); }

void another_dummy_function(void) { dummy_caller(dummy_function); }

int main(void) {
  another_dummy_function();
  return 0;
}