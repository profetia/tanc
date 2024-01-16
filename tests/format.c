/* clang-format off */
#include "libtanc.h"
/* clang-format on */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char* message = format_(("foo %d", 42));
  printf("%s\n", message);
  println_(("bar %d", 42));
  eprintln_(("baz %d", 42));
  free(message);
  return 0;
}