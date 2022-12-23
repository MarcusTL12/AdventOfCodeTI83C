#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

extern char input[];

static uint8_t milestones[] = {20, 60, 100, 140, 180, 220};

static bool is_milestone(uint8_t n) __z88dk_fastcall {
    for (uint8_t i = 0; i < 6; i++) {
        if (n == milestones[i]) return true;
    }

    return false;
}

int main() {
    printf("Day %d part %d\n", 10, 1);

    uint8_t x = 1, cycles = 0;
    int16_t y = 0;

    for (char *c = input; *c; c++) {
        if (*c == 'a') {
            c += 5;

            int8_t n = atoi(c);
            while (*c != '\n') c++;

            cycles++;
            if (is_milestone(cycles)) y += cycles * x;

            cycles++;
            if (is_milestone(cycles)) y += cycles * x;

            x += n;
        } else {
            c += 4;
            cycles++;

            if (is_milestone(cycles)) y += cycles * x;
        }
    }

    printf("%d\n", y);

    getkey();
    return 0;
}
