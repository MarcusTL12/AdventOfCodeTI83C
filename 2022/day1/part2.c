#include <stdio.h>
#include <stdlib.h>

#pragma string name day 1 part 2

extern char input[];

int main() {
    printf("Day 1 part 2\n");

    int32_t cursum = 0, curmax[] = {0, 0, 0};

    for (char *c = input; *c; c++) {
        if (*c == '\n') {
            for (char i = 0; i < 3; i++) {
                if (cursum > curmax[i]) {
                    int32_t tmp = cursum;
                    cursum = curmax[i];
                    curmax[i] = tmp;
                }
            }

            cursum = 0;
        } else {
            cursum += atol(c);
            while (*c != '\n') c++;
        }
    }

    for (char i = 0; i < 3; i++) {
        if (cursum > curmax[i]) {
            int32_t tmp = cursum;
            cursum = curmax[i];
            curmax[i] = tmp;
        }
    }

    int32_t ans = 0;

    for (char i = 0; i < 3; i++) {
        ans += curmax[i];
    }

    printf("ans: %ld\n", ans);

    getkey();
    return 0;
}
