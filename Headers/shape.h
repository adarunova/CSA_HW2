#ifndef HW1_SHAPE_H
#define HW1_SHAPE_H

// shape.h - содержит описание обобщающей геометрической фигуры.

#include "../Headers/random.h"

// Класс, обобщающающий все имеющиеся фигуры.
class Shape {
protected:
    // Рандомные значения параметров фигуры.
    static Random randomValue;
    // Рандомная фигура.
    static Random randomKey;
    // Рандомное значение цвета.
    static Random randomColor;

    // Значения цветов для фигур.
    enum color {
        RED, ORANGE, YELLOW, GREEN, CYAN, BLUE, PURPLE
    };
    // Цвет.
    color col;

public:
    // Ввод обобщенной фигуры.
    static Shape *StaticIn(FILE *fileIn, int key);

    // Ввод обобщенной фигуры.
    virtual void In(FILE *fileIn) = 0;

    // Случайный ввод обобщенной фигуры.
    static Shape *StaticInRandom();

    // Виртуальный метод ввода случайной фигуры
    virtual void InRandom() = 0;

    // Вывод обобщенной фигуры
    virtual void Out(FILE *fileOut) = 0;

    // Вычисление периметра обобщенной фигуры.
    virtual double Perimeter() = 0;

    // Выводит цвет фигуры.
    void Color(FILE *fOut);
};

#endif //HW1_SHAPE_H
