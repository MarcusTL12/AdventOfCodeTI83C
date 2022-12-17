#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#pragma string name day 5 part 2

#include "input.h"
#include "parse_stacks.h"

int main() {
    printf("Day 5 part 2\n");

    uint8_t n_stacks;

    char *inp_ptr = parse_stacks(input, &n_stacks);

    while (*inp_ptr) {
        inp_ptr += 5;

        uint8_t n_move = (uint8_t)atoi(inp_ptr);

        while (*inp_ptr != ' ') inp_ptr++;
        inp_ptr += 6;

        uint8_t from_ind = *inp_ptr - '1';
        inp_ptr += 5;

        uint8_t to_ind = *inp_ptr - '1';
        inp_ptr += 2;

        stackheights[from_ind] -= n_move;
        memcpy(stacks[to_ind] + stackheights[to_ind],
               stacks[from_ind] + stackheights[from_ind], n_move);
        stackheights[to_ind] += n_move;
    }

    for (uint8_t i = 0; i < n_stacks; i++) {
        printf("%c", stacks[i][stackheights[i] - 1]);
    }

    getkey();
    return 0;
}
