
// triangle.cpp - содержит функции обработки треугольника.

#include <stdio.h>
#include <math.h>
#include "../Headers/triangle.h"

// Ввод параметров треугольника из файла.
void Triangle::In(FILE *fileIn) {
    fscanf(fileIn, "%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    // Проверка на то, что координаты находятся на одной линии.
    if ((x3 - x2) * (y2 - y1) == (y3 - y2) * (x2 - x1)) {
        printf("Incorrect TRIANGLE. All coordinates are on one line. The TRIANGLE will be randomly generated.\n");
        InRandom();
    }
}

// Случайный ввод параметров треугольника.
void Triangle::InRandom() {
    x1 = randomValue.Get();
    y1 = randomValue.Get();
    x2 = randomValue.Get();
    x3 = randomValue.Get();
    // Генерируем y2 так, чтобы точки (x1, y1) и (x2, y2) не совпадали.
    do {
        y2 = randomValue.Get();
    } while (x1 == x2 && y1 == y2);
    // Генерируем y3 так, чтобы точки (x1, y1), (x2, y2) и (x3, y3) не лежали на одной прямой.
    do {
        y3 = randomValue.Get();
    } while ((x3 - x2) * (y2 - y1) == (y3 - y2) * (x2 - x1));
}

// Вывод параметров треугольника в файл.
void Triangle::Out(FILE *fileOut) {
    fprintf(fileOut,
            "It is TRIANGLE. Coordinates of vertices: (%d, %d), (%d, %d), (%d, %d). Perimeter =  %f;",
            x1, y1, x2, y2, x3, y3, Perimeter());
    Color(fileOut);
}

// Вычисление периметра треугольника.
double Triangle::Perimeter() {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)) +
           sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2)) +
           sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
}
