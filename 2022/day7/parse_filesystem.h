#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_DIRS 256

static uint32_t dirsizes[MAX_DIRS];
static uint8_t next_dir_space;

static char *parse_filesystem(char *s) {
    uint32_t *curdir = &dirsizes[next_dir_space++];
    uint32_t *last_subdir = NULL;

    *curdir = 0;

    while (*s) {
        char *l = s;

        while (*s != '\n') s++;
        s++;

        if (l[0] == '$' && l[2] == 'c') {
            if (l[5] == '.') {
                break;
            } else {
                uint8_t subdir_i = next_dir_space;

                s = parse_filesystem(s);

                *curdir += dirsizes[subdir_i];
            }
        } else if (isdigit(*l)) {
            *curdir += atol(l);
        }
    }

    return s;
}
