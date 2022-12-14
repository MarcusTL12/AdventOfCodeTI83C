#include <stdint.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#pragma string name day 3 part 2

#include "input.h"

static uint8_t get_index(char c) {
    if (islower(c)) {
        return c - 'a';
    } else {
        return c - 'A' + 26;
    }
}

int main() {
    printf("Day 3 part 2\n");

    char set1[26 * 2], set2[26 * 2];

    int ans = 0;

    for (char *c = input; *c;) {
        memset(set1, 1, 26 * 2);
        for (uint8_t j = 0; j < 3; j++) {
            uint8_t line_len = 0;
            for (char *l = c; *l != '\n'; l++) line_len++;

            memset(set2, 0, 26 * 2);
            for (uint8_t i = 0; i < line_len; i++) {
                set2[get_index(c[i])] = 1;
            }

            for (uint8_t i = 0; i < 26 * 2; i++) {
                set1[i] &= set2[i];
            }

            c += line_len + 1;
        }

        for (uint8_t i = 0; i < 26 * 2; i++) {
            if (set1[i]) {
                ans += i + 1;
            }
        }
    }

    printf("ans: %d\n", ans);

    getkey();
    return 0;
}
