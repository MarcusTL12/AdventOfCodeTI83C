#ifndef __quicksort__
#define __quicksort__

#include <stddef.h>
#include <string.h>

#include "simple_int.h"

static size_t quicksort_elsize;
static int (*quicksort_cmp)(const void *, const void*);

static u8 *quicksort_partition(u8 *lo, u8 *hi) {
    u8 *pivot = hi, *i = lo;

    for (u8 *j = lo; j < hi; j += quicksort_elsize) {
        if (quicksort_cmp(j, pivot) <= 0) {
            memswap(i, j, quicksort_elsize);

            i += quicksort_elsize;
        }
    }

    memswap(i, hi, quicksort_elsize);

    return i;
}

static void quicksort_rec(u8 *lo, u8 *hi) {
    if (lo >= hi) return;

    u8 *p = quicksort_partition(lo, hi);

    quicksort_rec(lo, p - quicksort_elsize);
    quicksort_rec(p + quicksort_elsize, hi);
}

static void quicksort(void *v, size_t n, size_t elsize_,
                      int (*cmp)(const void *, const void *)) {
    quicksort_elsize = elsize_;
    quicksort_cmp = cmp;

    u8 *lo = v, *hi = lo + quicksort_elsize * (n - 1);

    quicksort_rec(lo, hi);
}

#endif
