#ifndef HW1_RECTANGLE_H
#define HW1_RECTANGLE_H

// rectangle.h - содержит описание прямоугольника.

#include "../Headers/random.h"
#include "../Headers/shape.h"

// Прямоугольник.
class Rectangle : public Shape {
private:
    // Координаты левой верхней вершины.
    int x1, y1;
    // Координаты правой нижней вершины.
    int x2, y2;

public:
    // Ввод параметров прямоугольника из файла.
    void In(FILE *fileIn) override;

    // Случайный ввод параметров прямоугольника.
    void InRandom() override;

    // Вывод параметров прямоугольника в файл.
    void Out(FILE *fileOut) override;

    // Вычисление периметра прямоугольника.
    double Perimeter() override;
};

#endif //HW1_RECTANGLE_H
