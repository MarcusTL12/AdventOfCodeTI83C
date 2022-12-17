#include <stdint.h>
#include <string.h>

uint8_t counts[26];

static uint16_t solve(char *s, uint8_t n) {
    memset(counts, 0, 26);

    uint8_t n_diff = 0;

    for (uint8_t i = 0; i < n; i++) {
        if (counts[s[i] - 'a'] == 0) {
            n_diff += 1;
        }

        counts[s[i] - 'a']++;
    }

    for (uint16_t i = 1; s[n]; i++, s++) {
        counts[s[0] - 'a']--;
        if (counts[s[0] - 'a'] == 0) {
            n_diff--;
        }

        if (counts[s[n] - 'a'] == 0) {
            n_diff++;
        }
        counts[s[n] - 'a']++;

        if (n_diff == n) {
            return i + n;
        }
    }

    return 0;
}
