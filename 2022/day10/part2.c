#include <graphics.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

extern char input[];

static int16_t sx, sy;

static void push_pixel(int16_t x) {
    if (abs(sx - x) <= 1) {
        plot(sx, sy);
    }

    sx++;
    if (sx == 40) {
        sx = 0;
        sy++;
    }
}

int main() {
    printf("Day %d part %d\n", 10, 2);

    sx = 0;
    sy = 9;

    int16_t x = 1;

    for (char *c = input; *c; c++) {
        if (*c == 'a') {
            c += 5;

            int8_t n = atoi(c);
            while (*c != '\n') c++;

            push_pixel(x);
            push_pixel(x);

            x += n;
        } else {
            c += 4;
            push_pixel(x);
        }
    }

    getkey();
    return 0;
}
