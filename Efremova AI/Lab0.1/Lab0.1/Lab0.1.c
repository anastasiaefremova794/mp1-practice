#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
    double h, w, d;
    double mass = 0.0;
    int polki;

    const double DVP_P = 600.0, DSP_P = 650.0, WOOD_P = 700.0;
    const double T_BACK = 0.005, T_BODY = 0.015, T_DOOR = 0.010;

    printf("Vvedite visotu h (sm): ");
    if (scanf("%lf", &h) != 1) return 1;
    h = h / 100.0;

    printf("Vvedite shirinu w (sm): ");
    if (scanf("%lf", &w) != 1) return 1;
    w = w / 100.0;

    printf("Vvedite glubinu d (sm): ");
    if (scanf("%lf", &d) != 1) return 1;
    d = d / 100.0;

    polki = (int)floor(h / 0.4);
    if (polki < 0) polki = 0;

    mass += h * w * T_BACK * DVP_P;
    mass += 2 * h * d * T_BODY * DSP_P;
    mass += 2 * w * d * T_BODY * DSP_P;
    mass += h * w * T_DOOR * WOOD_P;
    mass += polki * w * d * T_BODY * DSP_P;

    printf("%.2f\n", mass);

    return 0;
}


