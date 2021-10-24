
// circle.cpp - содержит функции обработки круга.

#include <stdio.h>
#include "../Headers/circle.h"

// Число пи.
const double pi = 3.141592653;

// Ввод параметров круга из файла.
void Circle::In(FILE *fileIn) {
    fscanf(fileIn, "%d %d %d", &x, &y, &radius);
    // Проверка на то, что радиус меньше нуля.
    if (radius <= 0) {
        printf("Incorrect CIRCLE. Radius cannot be zero or less. The CIRCLE will be randomly generated.\n");
        InRandom();
    }
}

// Случайный ввод параметров круга.
void Circle::InRandom() {
    x = randomValue.Get();
    y = randomValue.Get();
    // Генерируем положительное число - радиус круга.
    do {
        radius = randomValue.Get();
    } while (radius <= 0);
}

// Вывод параметров круга в файл.
void Circle::Out(FILE *fileOut) {
    fprintf(fileOut,
            "It is CIRCLE. Center coordinates: (%d, %d), radius: %d. Perimeter = %f;",
            x, y, radius, Perimeter());
    Color(fileOut);
}

// Вычисление периметра круга.
double Circle::Perimeter() {
    return 2 * pi * radius;
}
