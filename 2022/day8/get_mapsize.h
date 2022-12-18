#include <stdint.h>

static uint8_t w, h;

static void get_mapsize(char *s) {
    w = 0;
    h = 0;

    for (char *c = s; *c != '\n'; c++) w++;

    for (char *c = s; *c; c += w + 1) h++;
}
