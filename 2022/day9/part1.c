#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "point/point_2i8.h"
#include "selection_sort.h"

extern char input[];

int main() {
    printf("Day %d part %d\n", 9, 1);

    point_2i8_t pts[6] = {
        {-75, 102}, {90, -39}, {61, 23}, {61, -69}, {-102, 49}, {90, 126},
    };

    selection_sort(pts, 6, 2, cmp_point_2i8);

    print_point_2i8(&pts[0]);
    for (uint8_t i = 1; i < 6; i++) {
        printf(", ");
        print_point_2i8(&pts[i]);
    }

    getkey();
    return 0;
}
