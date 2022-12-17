#ifndef __reverse_bytes__
#define __reverse_bytes__

#include <stddef.h>
#include <stdint.h>

static void reverse_bytes(uint8_t *front, size_t n) {
    uint8_t *back = front + n - 1;

    n >>= 1;

    while (n--) {
        uint8_t tmp = *front;
        *front = *back;
        *back = tmp;

        front++;
        back--;
    }
}

#endif
