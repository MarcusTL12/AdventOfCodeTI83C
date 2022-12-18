#ifndef __linelen__
#define __linelen__

#include <stddef.h>

static size_t linelen(char *s) {
    size_t l = 0;

    while (*s && *s != '\n') {
        s++;
        l++;
    }

    return l;
}

#endif
