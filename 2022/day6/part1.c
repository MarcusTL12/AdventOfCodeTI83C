#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#pragma string name day 6 part 1

#include "input.h"
#include "solve.h"

int main() {
    printf("Day %d part %d\n", 6, 1);

    uint16_t ans = solve(input, 4);

    printf("%d", ans);

    getkey();
    return 0;
}
