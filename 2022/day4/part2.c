#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#pragma string name day 4 part 2

#include "input.h"

int main() {
    printf("Day 4 part 2\n");

    uint16_t ans = 0;

    for (char *c = input; *c; c++) {
        uint8_t rs[2][2];

        rs[0][0] = atoi(c);
        while (isdigit(*c)) c++;
        while (!isdigit(*c)) c++;
        rs[0][1] = atoi(c);
        while (isdigit(*c)) c++;
        while (!isdigit(*c)) c++;
        rs[1][0] = atoi(c);
        while (isdigit(*c)) c++;
        while (!isdigit(*c)) c++;
        rs[1][1] = atoi(c);
        while (isdigit(*c)) c++;

        if ((rs[0][0] >= rs[1][0] && rs[0][0] <= rs[1][1]) ||
            (rs[0][1] >= rs[1][0] && rs[0][1] <= rs[1][1]) ||
            (rs[1][0] >= rs[0][0] && rs[1][0] <= rs[0][1]) ||
            (rs[1][1] >= rs[0][0] && rs[1][1] <= rs[0][1])) {
            ans++;
        }
    }

    printf("%d\n", ans);

    getkey();
    return 0;
}
