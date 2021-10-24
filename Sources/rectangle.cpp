
// rectangle.cpp - содержит процедуру ввода параметров для уже созданного прямоугольника.

#include <stdio.h>
#include "../Headers/rectangle.h"

// Ввод параметров прямоугольника из файла.
void Rectangle::In(FILE *fileIn) {
    fscanf(fileIn, "%d %d %d %d", &x1, &y1, &x2, &y2);
    if ((x2 - x1) * (y1 - y2) == 0) {
        printf("Incorrect RECTANGLE. All coordinates are on one line. The RECTANGLE will be randomly generated.\n");
        InRandom();
    } else if ((x2 <= x1) || (y1 <= y2)) {
        printf("Incorrect RECTANGLE. Wrong corner coordinates! The RECTANGLE will be randomly generated.\n");
        InRandom();
    }
}

// Случайный ввод параметров прямоугольника.
void Rectangle::InRandom() {
    x1 = randomValue.Get();
    y1 = randomValue.Get();
    Random randomXCoordinate(x1, 100 + x1);
    Random randomYCoordinate(y1, 100 + y1);
    x2 = randomXCoordinate.Get();
    y2 = randomYCoordinate.Get();
}

// Вывод параметров прямоугольника в файл.
void Rectangle::Out(FILE *fileOut) {
    fprintf(fileOut,
            "It is RECTANGLE. Coordinates of angles: (%d, %d), (%d, %d). Perimeter = %f;",
            x1, y1, x2, y2, Perimeter());
    Color(fileOut);
}

// Вычисление периметра прямоугольника.
double Rectangle::Perimeter() {
    return 2.0 * (abs(x1 - x2) + abs(y1 - y2));
}

