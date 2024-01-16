#ifndef LIBTANC_INTERNAL_POLYFILL_H
#define LIBTANC_INTERNAL_POLYFILL_H

/* Polyfill for __USE_GNU */
#ifndef __USE_GNU
#define __USE_GNU
/* Mark __USE_GNU as polyfilled */
#define LIBTANC_POLYFILL__USE_GNU
#endif /* __USE_GNU */

/* Polyfill for _GNU_SOURCE */
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
/* Mark _GNU_SOURCE as polyfilled */
#define LIBTANC_POLYFILL_GNU_SOURCE
#endif /* _GNU_SOURCE */

/* Polyfill for typeof */
#ifndef typeof
#define typeof __typeof__
/* Mark typeof as polyfilled */
#define LIBTANC_POLYFILL_typeof
#endif /* typeof */

/* Polyfill for inline */
#ifndef inline
#define inline __inline__
/* Mark inline as polyfilled */
#define LIBTANC_POLYFILL_inline
#endif /* inline */

/* Polyfill for __func__ */
#ifndef __func__
#define __func__ __builtin_FUNCTION()
/* Mark __func__ as polyfilled */
#define LIBTANC_POLYFILL___func__
#endif /* __func__ */

#endif /* LIBTANC_INTERNAL_POLYFILL_H */
