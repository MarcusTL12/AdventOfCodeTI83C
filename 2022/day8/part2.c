#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "parse_filesystem.h"

extern char input[];

#define TOTAL_CAP 70000000
#define NEEDED_SPACE 30000000

int main() {
    printf("Day %d part %d\n", 8, 2);

    next_dir_space = 0;
    parse_filesystem(input + 7);

    uint32_t cur_smallest = TOTAL_CAP, unused = TOTAL_CAP - dirsizes[0];

    for (uint8_t i = 0; i < next_dir_space; i++) {
        if (dirsizes[i] + unused >= NEEDED_SPACE &&
            dirsizes[i] < cur_smallest) {
            cur_smallest = dirsizes[i];
        }
    }

    printf("%ld\n", cur_smallest);

    getkey();
    return 0;
}
