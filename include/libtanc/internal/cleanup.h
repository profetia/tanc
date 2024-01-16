
#ifdef LIBTANC_INTERNAL_POLYFILL_H

/* Cleanup for the polyfill of _GNU_SOURCE. */
#ifdef LIBTANC_POLYFILL_GNU_SOURCE
#undef _GNU_SOURCE
/* Unmark _GNU_SOURCE as polyfilled */
#undef LIBTANC_POLYFILL_GNU_SOURCE
#endif /* _GNU_SOURCE */

/* Cleanup for the polyfill of __USE_GNU. */
#ifdef LIBTANC_POLYFILL__USE_GNU
#undef __USE_GNU
/* Unmark __USE_GNU as polyfilled */
#undef LIBTANC_POLYFILL__USE_GNU
#endif /* __USE_GNU */

#undef LIBTANC_INTERNAL_POLYFILL_H
#endif /* LIBTANC_INTERNAL_POLYFILL_H */

#ifdef LIBTANC_INTERNAL_MODULE_H

/* Cleanup for the polyfill of module/namespace. */
#undef module_
/* Cleanup for the declaration of the backtrace module. */
#undef LIBTANC_POLYFILL__MODULE_backtrace
/* Cleanup for the declaration of the debug module. */
#undef LIBTANC_POLYFILL__MODULE_debug

#undef LIBTANC_INTERNAL_MODULE_H
#endif /* LIBTANC_INTERNAL_MODULE_H */
