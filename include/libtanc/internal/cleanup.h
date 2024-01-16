
/* Cleanup for the polyfill of _GNU_SOURCE. */
#ifdef LIBTANC_POLYFILL_GNU_SOURCE
#undef _GNU_SOURCE
/* Unmark _GNU_SOURCE as polyfilled */
#undef LIBTANC_POLYFILL_GNU_SOURCE
#endif

/* Cleanup for the polyfill of __USE_GNU. */
#ifdef LIBTANC_POLYFILL__USE_GNU
#undef __USE_GNU
/* Unmark __USE_GNU as polyfilled */
#undef LIBTANC_POLYFILL__USE_GNU
#endif

/* Cleanup for the polyfill of module/namespace. */
#undef module_
/* Cleanup for the declaration of the backtrace module. */
#undef LIBTANC_POLYFILL__MODULE_backtrace
