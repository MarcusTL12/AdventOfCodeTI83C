#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#pragma string name day 7 part 1

uint16_t a = 10000;
uint8_t b = 123;

int main() {
    printf("Day %d part %d\n", 7, 1);

    uint16_t x = a / b, y = a % b;

    printf("x: %d, y: %d\n", x, y);

    getkey();
    return 0;
}
