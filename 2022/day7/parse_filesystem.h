#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
    uint32_t size;
    uint8_t next_dir;  // If zero, this is last. Else this is index of next.
    bool has_subdir;   // If so, it is next after this.
} directory_t;

#define MAX_DIRS 256

static directory_t dirtree[MAX_DIRS];
static uint8_t next_dir_space;

static char *parse_filesystem(char *s) {
    directory_t *curdir = &dirtree[next_dir_space++];
    directory_t *last_subdir = NULL;

    curdir->size = 0;
    curdir->next_dir = 0;
    curdir->has_subdir = false;

    while (*s) {
        char *l = s;

        while (*s != '\n') s++;
        s++;

        if (l[0] == '$' && l[2] == 'c') {
            if (l[5] == '.') {
                break;
            } else {
                uint8_t subdir_i = next_dir_space;

                if (curdir->has_subdir) {
                    last_subdir->next_dir = subdir_i;
                }
                last_subdir = &dirtree[subdir_i];
                curdir->has_subdir = true;
                s = parse_filesystem(s);

                curdir->size += dirtree[subdir_i].size;
            }
        } else if (isdigit(*l)) {
            curdir->size += atol(l);
        }
    }

    return s;
}
