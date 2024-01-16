/* Polyfill for __USE_GNU */
#ifndef __USE_GNU
#define __USE_GNU
/* Mark __USE_GNU as polyfilled */
#define LIBTANC_POLYFILL__USE_GNU
#endif

/* Polyfill for _GNU_SOURCE */
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
/* Mark _GNU_SOURCE as polyfilled */
#define LIBTANC_POLYFILL_GNU_SOURCE
#endif

/* Polyfill for module/namespace */
#define module_(mod) LIBTANC_POLYFILL__MODULE_##mod
/* Declare the backtrace module */
#define LIBTANC_POLYFILL__MODULE_backtrace(ident) tanc__backtrace__##ident
