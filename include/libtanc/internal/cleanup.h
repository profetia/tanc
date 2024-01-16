
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

/* Cleanup for the polyfill of typeof. */
#ifdef LIBTANC_POLYFILL_typeof
#undef typeof
/* Unmark typeof as polyfilled */
#undef LIBTANC_POLYFILL_typeof
#endif /* typeof */

/* Cleanup for the polyfill of inline. */
#ifdef LIBTANC_POLYFILL_inline
#undef inline
/* Unmark inline as polyfilled */
#undef LIBTANC_POLYFILL_inline
#endif /* inline */

/* Cleanup for the polyfill of __func__. */
#ifdef LIBTANC_POLYFILL___func__
#undef __func__
/* Unmark __func__ as polyfilled */
#undef LIBTANC_POLYFILL___func__
#endif /* __func__ */

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
