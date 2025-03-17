#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef enum { S1, S2 } State;

const char* getMooreOutput(State state) {
    return (state == S1) ? "O1" : "O2";
}

State transitionMoore(State currentState, char input) {
    switch (currentState) {
    case S1:
        return (input == 'A') ? S1 : S2;
    case S2:
        return (input == 'A') ? S1 : S2;
    }
    return S1; 
}

typedef enum { Q1, Q2 } MealyState;

MealyState transitionMealy(MealyState currentState, char input, char* output) {
    switch (currentState) {
    case Q1:
        if (input == 'X') {
            *output = 'O';
            return Q2;
        }
        else {
            *output = 'O';
            return Q1;
        }
    case Q2:
        if (input == 'X') {
            *output = 'P';
            return Q1;
        }
        else {
            *output = 'P';
            return Q2;
        }
    }
    return Q1; 
}

int main() {
    int choice;
    printf("Selectati masina de rulat:\n1 - Masina Moore\n2 - Masina Mealy\n");
    scanf("%d", &choice);

    if (choice == 1) {
        char input[100];
        printf("Introduceti sirul de intrari (A/B): ");
        scanf("%s", input);

        State currentState = S1;
        printf("Stare initiala: S1, Iesire: %s\n", getMooreOutput(currentState));

        for (int i = 0; i < strlen(input); i++) {
            currentState = transitionMoore(currentState, input[i]);
            printf("Tranzitie: %c -> Stare: S%d, Iesire: %s\n", input[i], currentState + 1, getMooreOutput(currentState));
        }
    }
    else if (choice == 2) {
        char input[100];
        printf("Introduceti sirul de intrari (X/Y): ");
        scanf("%s", input);

        MealyState currentState = Q1;
        char output;

        for (int i = 0; i < strlen(input); i++) {
            currentState = transitionMealy(currentState, input[i], &output);
            printf("Tranzitie: %c -> Stare: Q%d, Iesire: %c\n", input[i], currentState + 1, output);
        }
    }
    else {
        printf("Optiune invalida!\n");
    }

    return 0;
}
