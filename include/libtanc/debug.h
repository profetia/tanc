#ifndef LIBTANC_DEBUG_H
#define LIBTANC_DEBUG_H

/* Ensure that this header is only used with GCC. */
#ifndef __GNUC__
#error "libtanc/backtrace.h requires GCC"
#endif

/* Include the debug module headers. */
#include "libtanc/debug/assert.h"
#include "libtanc/debug/file.h"
#include "libtanc/debug/panic.h"
#include "libtanc/debug/todo.h"

#endif /* LIBTANC_DEBUG_H */
