#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// funktsiya dlya Rezhima 1: Kompyuter ugadyvaet chislo polzovatelya
void mode1() {
    int popytka, kolichestvo_popytok = 0;
    int min = 1, max = 1000;
    char otvet;

    printf("Rezhim 1: Vy zagadyvaete chislo ot 1 do 1000, kompyuter ugadyvaet.\n");

    while (1) {
        // Prostaya logika binarnogo poiska dlya effektivnogo ugadyvaniya
        popytka = min + (max - min) / 2;
        kolichestvo_popytok++;
        printf("Eto chislo %d? (b dlya bolshe, m dlya menshe, v dlya verno): ", popytka);
        scanf(" %c", &otvet);

        if (otvet == 'v') {
            printf("Kompyuter ugadal za %d popytok!\n", kolichestvo_popytok);
            break;
        }
        else if (otvet == 'b') {
            min = popytka + 1;
        }
        else if (otvet == 'm') {
            max = popytka - 1;
        }
        else {
            printf("Neverny vvod, ispolzuyte b, m, ili v.\n");
            // Ne schitaem nevernye popytki
            kolichestvo_popytok--;
        }
        // Proverka na oshibku v logike polzovatelya
        if (min > max) {
            printf("Vy mozhete obmanyvat! Vashe chislo dolzhno byt v diapazone.\n");
            break;
        }
    }
}

// funktsiya dlya Rezhima 2: Polzovatel ugadyvaet chislo kompyutera
void mode2() {
    int secret_number, popytka, kolichestvo_popytok = 0;
    // Iniciiruem generator sluchaynykh chisel
    srand(time(NULL));
    // Generiruem sluchainoe chislo ot 1 do 1000
    secret_number = rand() % 1000 + 1;

    printf("Rezhim 2: Kompyuter zagadyvaet chislo ot 1 do 1000, vy ugadyvaete.\n");

    do {
        printf("Vvedite vashe chislo: ");
        scanf("%d", &popytka);
        kolichestvo_popytok++;

        if (popytka > secret_number) {
            printf("Zagadannoe chislo menshe.\n");
        }
        else if (popytka < secret_number) {
            printf("Zagadannoe chislo bolshe.\n");
        }
        else {
            printf("Vy ugadali! Chislo bylo %d.\n", secret_number);
            printf("Eto zanyalo u vas %d popytok.\n", kolichestvo_popytok);
            // Kolichestvo popytok
        }
    } while (popytka != secret_number);
}

int main() {
    int mode; // Peremennaya dlya khraneniya vybora rezhima

    printf("Vyberite rezhim:\n");
    printf("1. Kompyuter ugadyvaet vashe chislo\n");
    printf("2. Vy ugadyvaete chislo kompyutera\n");
    printf("Vvedite nomer rezhima (1 ili 2): ");
    scanf("%d", &mode);

    if (mode == 1) {
        mode1();
    }
    else if (mode == 2) {
        mode2();
    }
    else {
        printf("Vybran neverny rezhim.\n");
    }

    return 0;
}
