#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "get_mapsize.h"

extern uint8_t input[];

static bool is_visible(uint8_t i, uint8_t j) {
    uint8_t *row = input + (w + 1) * i;
    uint8_t *col = input + j;

    uint8_t curheight = row[j];

    bool visible = true;
    uint8_t *c = col;
    for (uint8_t k = 0; k < i; k++, c += w + 1) {
        if (*c >= curheight) {
            visible = false;
            break;
        }
    }
    if (visible) return true;

    visible = true;
    c = row;
    for (uint8_t k = 0; k < j; k++, c++) {
        if (*c >= curheight) {
            visible = false;
            break;
        }
    }
    if (visible) return true;

    visible = true;
    c = col + (w + 1) * (i + 1);
    for (uint8_t k = i + 1; k < h; k++, c += w + 1) {
        if (*c >= curheight) {
            visible = false;
            break;
        }
    }
    if (visible) return true;

    visible = true;
    c = row + j + 1;
    for (uint8_t k = j + 1; k < w; k++, c++) {
        if (*c >= curheight) {
            visible = false;
            break;
        }
    }
    return visible;
}

int main() {
    printf("Day %d part %d\n", 8, 1);

    get_mapsize(input);

    uint16_t ans = 2 * w + 2 * (h - 2);

    for (uint8_t i = 1; i < h - 1; i++) {
        for (uint8_t j = 1; j < w - 1; j++) {
            if (is_visible(i, j)) ans++;
        }
    }

    printf("ans: %d\n", ans);

    getkey();
    return 0;
}
