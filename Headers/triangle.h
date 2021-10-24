#ifndef HW1_TRIANGLE_H
#define HW1_TRIANGLE_H

// triangle.h - содержит описание треугольника.

# include "../Headers/random.h"
#include "../Headers/shape.h"

// Треугольник.
class Triangle : public Shape {
private:
    // Координаты вершин.
    int x1, y1;
    int x2, y2;
    int x3, y3;

public:
    // Ввод параметров треугольника из файла.
    void In(FILE *fileIn) override;

    // Случайный ввод параметров треугольника.
    void InRandom() override;

    // Вывод параметров треугольника в файл.
    void Out(FILE *fileOut) override;

    // Вычисление периметра треугольника.
    double Perimeter() override;
};

#endif //HW1_TRIANGLE_H
