#ifndef LIBTANC_INTERNAL_MODULE_H
#define LIBTANC_INTERNAL_MODULE_H

/* Polyfill for module/namespace */
#define module_(mod) LIBTANC_POLYFILL__MODULE_##mod
/* Declare the backtrace module */
#define LIBTANC_POLYFILL__MODULE_backtrace(ident) tanc__backtrace__##ident
/* Declare the debug module */
#define LIBTANC_POLYFILL__MODULE_debug(ident) tanc__debug__##ident
/* Declare the format module */
#define LIBTANC_POLYFILL__MODULE_format(ident) tanc__format__##ident

#endif /* LIBTANC_INTERNAL_MODULE_H */
