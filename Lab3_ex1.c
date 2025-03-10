#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char* stare = "q0";

void tranzitie(char* input) {
    if (strcmp(stare, "q0") == 0) {
        if (strcmp(input, "C") == 0) { stare = "q1"; printf("Ati selectat Cafea. Apasati OK.\n"); }
        else if (strcmp(input, "T") == 0) { stare = "q2"; printf("Ati selectat Ceai. Apasati OK.\n"); }
        else if (strcmp(input, "A") == 0) { stare = "q3"; printf("Ati selectat Cappuccino. Apasati OK.\n"); }
        else if (strcmp(input, "H") == 0) { stare = "q4"; printf("Ati selectat Ciocolata calda. Apasati OK.\n"); }
        else { printf("Selecție invalidă!\n"); }
    }
    else if ((strcmp(stare, "q1") == 0 || strcmp(stare, "q2") == 0 || strcmp(stare, "q3") == 0 || strcmp(stare, "q4") == 0) && strcmp(input, "OK") == 0) {
        printf("Bautura este servita!\n");
        stare = "q0";
    }
    else {
        printf("Comanda invalida!\n");
    }
}

int main() {
    char input[10];
    while (1) {
        printf("Selectati bautura (C, T, A, H) sau OK: ");
        scanf("%s", input);
        tranzitie(input);
    }
    return 0;
}
