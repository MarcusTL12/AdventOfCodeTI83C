#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "ex1.h"

#pragma string name day 1 part 1

int main() {
    printf("Day 1 part 1\n");

    long cursum = 0, curmax = 0;

    for (char *c = input; *c; c++) {
        if (*c == '\n') {
            curmax = cursum > curmax ? cursum : curmax;
            cursum = 0;
        } else {
            cursum += atol(c);
            while (*c != '\n') c++;
        }
    }

    printf("ans: %ld\n", curmax);

    getkey();
    return 0;
}
