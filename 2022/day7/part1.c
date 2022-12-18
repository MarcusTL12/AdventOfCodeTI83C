#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "parse_filesystem.h"

extern char input[];

int main() {
    printf("Day %d part %d\n", 7, 1);

    next_dir_space = 0;
    parse_filesystem(input + 7);

    uint32_t s = 0;

    for (uint8_t i = 0; i < next_dir_space; i++) {
        if (dirsizes[i] < 100000) {
            s += dirsizes[i];
        }
    }

    printf("%ld\n", s);

    getkey();
    return 0;
}
