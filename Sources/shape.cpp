
// shape.cpp - содержит процедуры связанные с обработкой обобщенной фигуры и создания произвольной фигуры.

#include <stdio.h>
#include "../Headers/shape.h"
#include "../Headers/circle.h"
#include "../Headers/rectangle.h"
#include "../Headers/triangle.h"

// Рандомные значения параметров фигуры.
Random Shape::randomValue(-100, 100);
// Рандомная фигура.
Random Shape::randomKey(1, 3);
// Рандомное значение цвета.
Random Shape::randomColor(0, 6);

// Ввод параметров обобщенной фигуры из файла.
Shape *Shape::StaticIn(FILE *fileIn, int key) {
    Shape *shape;
    switch (key) {
        case 1:
            shape = new Circle;
            break;
        case 2:
            shape = new Rectangle;
            break;
        case 3:
            shape = new Triangle;
            break;
        default:
            printf("Incorrect shape!\n");
            return nullptr;
    }
    int color;
    fscanf(fileIn, "%d", &color);
    if (color > 6 || color < 0) {
        printf("Incorrect color! The COLOR will be randomly generated.\n");
        color = rand() % 7;
    }
    shape->col = static_cast<Shape::color>(color);
    shape->In(fileIn);
    return shape;
}

// Случайный ввод обобщенной фигуры.
Shape *Shape::StaticInRandom() {
    // Генерируем число, которыму соответствует одна из фигур.
    auto key = Shape::randomKey.Get();
    Shape *shape = nullptr;
    switch (key) {
        case 1:
            shape = new Circle;
            break;
        case 2:
            shape = new Rectangle;
            break;
        case 3:
            shape = new Triangle;
            break;
    }
    // Генерируем число, которыму соответствует один из цветов.
    auto color = Shape::randomColor.Get();
    shape->col = static_cast<Shape::color>(color);
    shape->InRandom();
    return shape;
}

// Выводит цвет фигуры.
void Shape::Color(FILE *fOut) {
    switch (col) {
        case Shape::color::RED:
            fprintf(fOut, " Color: RED\n");
            break;
        case Shape::color::ORANGE:
            fprintf(fOut, " Color: ORANGE\n");
            break;
        case Shape::color::YELLOW:
            fprintf(fOut, " Color: YELLOW\n");
            break;
        case Shape::color::GREEN:
            fprintf(fOut, " Color: GREEN\n");
            break;
        case Shape::color::CYAN:
            fprintf(fOut, " Color: CYAN\n");
            break;
        case Shape::color::BLUE:
            fprintf(fOut, " Color: BLUE\n");
            break;
        case Shape::color::PURPLE:
            fprintf(fOut, " Color: PURPLE\n");
            break;
    }
}
