#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "parse_filesystem.h"

extern char input[];

static uint32_t sum_sub_100000(uint8_t i) {
    directory_t *curdir = &dirtree[i];

    uint32_t s = 0;

    if (curdir->size <= 100000) {
        s = curdir->size;
    }

    if (curdir->has_subdir) {
        i++;

        while (true) {
            s += sum_sub_100000(i);

            if (dirtree[i].next_dir) {
                i = dirtree[i].next_dir;
            } else {
                break;
            }
        }
    }

    return s;
}

int main() {
    printf("Day %d part %d\n", 7, 1);

    next_dir_space = 0;
    parse_filesystem(input + 7);

    uint32_t ans = sum_sub_100000(0);

    printf("%ld\n", ans);

    getkey();
    return 0;
}
