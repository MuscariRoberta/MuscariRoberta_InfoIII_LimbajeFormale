#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 100

bool matchNFA(const char* input) {
    int len = strlen(input);
    if (len == 0) return false;

    if (len == 1 && input[0] == 'a') return true;
    if (len >= 2 && input[0] == 'b' && (input[1] == 'a' || input[1] == 'b')) return true;

    for (int i = 2; i < len; i++) {
        if (input[i] != 'a' && input[i] != 'b') {
            return false;
        }
    }
    return true;
}

int main() {
    char testCases[][MAX_LEN] = { "baba", "ba", "bb", "a", "bbb", "abba" };
    int numTests = sizeof(testCases) / sizeof(testCases[0]);

    for (int i = 0; i < numTests; i++) {
        printf("Test: %s -> %s\n", testCases[i], matchNFA(testCases[i]) ? "Acceptat" : "Respins");
    }

    return 0;
}
