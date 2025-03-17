/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef enum { S0, S1a, S1b } State;

void processInput(int A, int B, State* currentState) {
    int output;

    switch (*currentState) {
    case S0:
        output = 0;
        if (A == 0 && B == 0) {
            *currentState = S0;
        }
        else if (A == 0 && B == 1) {
            *currentState = S1a;
        }
        else if (A == 1 && B == 0) {
            *currentState = S0;
        }
        else {
            *currentState = S1a;
        }
        break;
    case S1a:
    case S1b:
        output = 1;
        if (A == 0 && B == 0) {
            *currentState = S1b;
        }
        else if (A == 0 && B == 1) {
            *currentState = S1b;
        }
        else if (A == 1 && B == 0) {
            *currentState = S0;
        }
        else {
            *currentState = S0;
        }
        break;
    }

    printf("Stare: %s, Intrare: (%d, %d), Iesire: %d\n", (*currentState == S0) ? "S0" : ((*currentState == S1a) ? "S1a" : "S1b"), A, B, output);
}

int main() {
    State currentState = S0;
    int inputs[][2] = { {0, 0}, {0, 1}, {1, 0}, {1, 1}, {0, 0}, {1, 0}, {0, 1} };
    int numTests = sizeof(inputs) / sizeof(inputs[0]);

    for (int i = 0; i < numTests; i++) {
        processInput(inputs[i][0], inputs[i][1], &currentState);
    }

    return 0;
}
*/