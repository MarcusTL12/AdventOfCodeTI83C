#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "parse_filesystem.h"

extern char input[];

int main() {
    printf("Day %d part %d\n", 7, 2);

    next_dir_space = 0;
    parse_filesystem(input + 7);


    getkey();
    return 0;
}
