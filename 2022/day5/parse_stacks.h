#include <stdint.h>
#include <string.h>

#define MAX_STACK_HEIGHT 56
#define MAX_STACKS 9

uint8_t stacks[MAX_STACKS][MAX_STACK_HEIGHT];
uint8_t stackheights[MAX_STACKS];

#include "util/reverse_bytes.h"

static char *parse_stacks(char *input, uint8_t *n_stacks_p) {
    uint8_t linelen = 0;

    for (char *c = input; *c != '\n'; c++) linelen++;

    uint8_t n_stacks = (linelen + 1) / 4;
    *n_stacks_p = n_stacks;

    memset(stackheights, 0, (size_t)n_stacks);

    for (; input[1] != '1'; input += linelen + 1) {
        for (uint8_t i = 0; i < n_stacks; i++) {
            char c = input[4 * i + 1];
            if (c != ' ') {
                stacks[i][stackheights[i]++] = c;
            }
        }
    }

    for (uint8_t i = 0; i < n_stacks; i++) {
        reverse_bytes(stacks[i], stackheights[i]);
    }

    return input + linelen + 2;
}
