#ifndef HW1_CIRCLE_H
#define HW1_CIRCLE_H

// triangle.h - содержит описание круга.

#include "../Headers/random.h"
#include "../Headers/shape.h"

// Круг.
class Circle : public Shape {
private:
    // Координаты центра.
    int x, y;
    // Радиус.
    int radius;

public:
    // Ввод параметров круга из файла.
    void In(FILE *fileIn) override;

    // Случайный ввод параметров круга.
    void InRandom()  override;

    // Вывод параметров круга в файл.
    void Out(FILE *fileOut)  override;

    // Вычисление периметра круга.
    double Perimeter()  override;
};

#endif //HW1_CIRCLE_H
