#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    int dlina_chisla, byki = 0, korovy = 0;
    char zagadanoe_chislo[6]; // Ispravleno: massiv simvolov dostatochnogo razmera
    char popytka[6]; // Ispravleno: massiv simvolov dostatochnogo razmera

    do {
        printf("Vyberite dlinu zagadyvayemogo chisla n (ot 2 do 5): ");
        scanf("%d", &dlina_chisla);
        if (dlina_chisla < 2 || dlina_chisla > 5) {
            printf("Nevernyy diapazon vvoda. Povtorite popytku.\n");
        }
    } while (dlina_chisla < 2 || dlina_chisla > 5);

    srand(time(NULL));
    for (int i = 0; i < dlina_chisla; i++) {
        char cifra;
        int povtoryaetsya_li;
        do {
            povtoryaetsya_li = 0;
            cifra = rand() % 10 + '0';
            for (int j = 0; j < i; j++) {
                if (zagadanoe_chislo[j] == cifra) {
                    povtoryaetsya_li = 1;
                    break;
                }
            }
        } while (povtoryaetsya_li);
        zagadanoe_chislo[i] = cifra;
    }
    zagadanoe_chislo[dlina_chisla] = '\0';

    printf("Chislo zagadano. Poprobuyte otgadat'.\n");

    while (byki != dlina_chisla) {
        byki = 0;
        korovy = 0;

        do {
            printf("Vvedite vashe %d-znachnoye chislo: ", dlina_chisla);
            scanf("%s", popytka);
            if (strlen(popytka) != dlina_chisla) {
                printf("Nevernaya dlina chisla. Povtorite popytku.\n");
            }
        } while (strlen(popytka) != dlina_chisla);

        for (int i = 0; i < dlina_chisla; i++) {
            for (int j = 0; j < dlina_chisla; j++) {
                if (zagadanoe_chislo[i] == popytka[j]) {
                    if (i == j) byki++;
                    else korovy++;
                }
            }
        }

        printf("Rezultat: %d bykov, %d korov\n", byki, korovy);
    }

    printf("Pozdravlyayem! Chislo bylo %s.\n", zagadanoe_chislo);
    return 0;
}
