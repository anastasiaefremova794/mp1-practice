#include <stdio.h>

int main() {
    // Плотности материалов в кг/м?
    const float densityDSP = 700; // плотность ДСП
    const float densityDVP = 600;  // плотность ДВП
    const float densityWood = 800;  // плотность дерева

    // Переменные для размеров шкафа
    int h, w, d, a;

    // Ввод высоты шкафа
    printf("Введите высоту шкафа (от 180 до 220 см): ");
    scanf("%d", &h);
    if (h < 180 || h > 220) {
        printf("Ошибка: высота должна быть от 180 до 220 см.\n");
        return 1;
    }

    // Ввод ширины шкафа
    printf("Введите ширину шкафа (от 80 до 120 см): ");
    scanf("%d", &w);
    if (w < 80 || w > 120) {
        printf("Ошибка: ширина должна быть от 80 до 120 см.\n");
        return 1;
    }

    // Ввод глубины боковин
    printf("Введите глубину боковин (от 50 до 90 см): ");
    scanf("%d", &d);
    if (d < 50 || d > 90) {
        printf("Ошибка: глубина должна быть от 50 до 90 см.\n");
        return 1;
    }

    // Ввод глубины верхних и нижних крышек
    printf("Введите глубину верхних и нижних крышек (от 50 до 90 см): ");
    scanf("%d", &a);
    if (a < 50 || a > 90) {
        printf("Ошибка: глубина должна быть от 50 до 90 см.\n");
        return 1;
    }

    // Конвертация см в м для расчета массы
    float height_m = h / 100.0; // высота в метрах
    float width_m = w / 100.0;   // ширина в метрах
    float depth_m = d / 100.0;    // глубина в метрах
    float thickness_dvp = 0.005;   // толщина задней стенки в метрах
    float thickness_dsp = 0.015;   // толщина боковин и крышек в метрах
    float thickness_wood = 0.01;   // толщина дверей в метрах

    // Расчет массы каждой части шкафа
    float mass_back_wall = width_m * height_m * thickness_dvp * densityDVP; // масса задней стенки
    float mass_side_walls = 2 * (thickness_dsp * height_m * depth_m * densityDSP); // масса боковин
    float mass_top_bottom = 2 * (width_m * a / 100.0 * thickness_dsp * densityDSP); // масса верхней и нижней крышек
    float mass_doors = width_m * height_m * thickness_wood * densityWood; // масса дверей

    // Общая масса шкафа
    float total_mass = mass_back_wall + mass_side_walls + mass_top_bottom + mass_doors;

    // Количество полок
    int shelf_count = (h / 40) - 1;

    // Вывод результата
    printf("Общая масса шкафа: %.2f кг\n", total_mass);
    printf("Количество полок: %d\n", shelf_count);

    return 0;
}
