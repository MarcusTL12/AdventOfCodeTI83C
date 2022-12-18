#include <stdio.h>
#include <stdint.h>

extern char input[];

int main() {
    printf("Day 2 part 2\n");

    int ans = 0;

    for (char *c = input; *c; c += 4) {
        char a = c[0] - 'A';
        char b = c[2] - 'X';

        ans += b * 3 + (b + a + 2) % 3 + 1;
    }

    printf("ans: %d\n", ans);

    getkey();
    return 0;
}
