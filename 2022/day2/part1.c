#include <stdio.h>
#include <stdint.h>

#pragma string name day 2 part 1

#include "input.h"

int main() {
    printf("Day 2 part 1\n");

    int ans = 0;

    for (char *c = input; *c; c += 4) {
        char a = c[0] - 'A';
        char b = c[2] - 'X';

        ans += (b + 1) + (b - a + 4) % 3 * 3;
    }

    printf("ans: %d\n", ans);

    getkey();
    return 0;
}
