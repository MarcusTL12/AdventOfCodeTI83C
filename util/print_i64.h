#ifndef __print_i64__
#define __print_i64__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

static void print_i64(int64_t n) {
    if (n < 0) {
        printf("-");
        n = -n;
    }

    const int32_t tens = 1000000000;

    int32_t h = n / tens, l = n % tens;

    printf("%ld%ld", h, l);
}

#endif
