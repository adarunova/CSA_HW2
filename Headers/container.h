#ifndef HW1_CONTAINER_H
#define HW1_CONTAINER_H

// container.h - содержит тип данных, представляющий простейший контейнер.

#include <stdio.h>
#include "../Headers/shape.h"

// Максимальная длина массива.
const int MAX_LENGTH = 10000;

// Простейший контейнер на основе одномерного массива
class Container {
private:
    // Текущая длина.
    int length;
    // Массив фигур.
    Shape *container[MAX_LENGTH];

    // Очистка контейнера от элементов (освобождение памяти).
    void Clear();

public:
    // Конструктор.
    Container();

    // Получает длину контейнера.
    int GetLength() const;

    // Ввод содержимого контейнера из указанного потока
    void In(FILE *fileIn);

    // Случайный ввод содержимого контейнера
    void InRandom(int size);

    // Вывод содержимого контейнера в указанный поток
    void Out(FILE *fileOut);

    // Отчистка контейнера от фигур с периметром, меньшим среднего значаения.
    void DeleteElements();

    // Деструктор.
    ~Container();
};

#endif //HW1_CONTAINER_H
