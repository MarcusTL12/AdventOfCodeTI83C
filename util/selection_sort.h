#ifndef __selection_sort__
#define __selection_sort__

#include <stddef.h>
#include <stdint.h>
#include <string.h>

static void selection_sort(void *v_, size_t n, size_t elsize,
                           int (*cmp)(const void *, const void *)) {
    uint8_t *ip = v_;
    for (size_t i = 0; i < n; i++, ip += elsize) {
        uint8_t *min_p = ip, *jp = ip + elsize;
        for (size_t j = i + 1; j < n; j++, jp += elsize) {
            if (cmp(jp, min_p) < 0) {
                min_p = jp;
            }
        }

        if (min_p != ip) {
            memswap(ip, min_p, elsize);
        }
    }
}

#endif
