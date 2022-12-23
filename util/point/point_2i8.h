#ifndef __point_2i8__
#define __point_2i8__

#include <stdint.h>
#include <stdio.h>

typedef struct {
    int8_t x, y;
} point_2i8_t;

static void print_point_2i8(point_2i8_t *p) __z88dk_fastcall {
    printf("(%d, %d)", p->x, p->y);
}

// To sort lexiographically with x being more important than y
int cmp_point_2i8(const void *a_, const void *b_) {
    point_2i8_t *a = (point_2i8_t *)a_, *b = (point_2i8_t *)b_;
    int8_t ax = a->x, ay = a->y, bx = b->x, by = b->y;

    return ax >= bx ? ax == bx ? ay >= by ? ay == by ? 0 : 1 : -1 : 1 : -1;
}

#endif
