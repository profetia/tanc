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

#endif /* LIBTANC_INTERNAL_POLYFILL_H */
