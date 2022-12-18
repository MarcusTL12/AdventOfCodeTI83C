#include <stdint.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#pragma string name day 3 part 1

extern char input[];

static uint8_t get_index(char c) {
    if (islower(c)) {
        return c - 'a';
    } else {
        return c - 'A' + 26;
    }
}

int main() {
    printf("Day 3 part 1\n");

    char set[26 * 2];

    int ans = 0;

    for (char *c = input; *c; c++) {
        uint8_t line_len = 0;
        for (char *l = c; *l != '\n'; l++) line_len++;

        memset(set, 0, 26 * 2);
        for (uint8_t i = 0; i < line_len / 2; i++) {
            set[get_index(c[i])] = 1;
        }

        for (uint8_t i = line_len / 2; i < line_len; i++) {
            if (set[get_index(c[i])]) {
                ans += get_index(c[i]) + 1;
                break;
            }
        }

        c += line_len;
    }

    printf("ans: %d\n", ans);

    getkey();
    return 0;
}
