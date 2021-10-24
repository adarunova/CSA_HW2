
// container.cpp - содержит функции обработки контейнера.

#include "../Headers/container.h"

// Конструктор (инициализация контейнера).
Container::Container() : length(0) {}

int Container::GetLength() const {
    return length;
}

// Деструктор контейнера
Container::~Container() {
    Clear();
}

// Очистка контейнера от элементов (освобождение памяти).
void Container::Clear() {
    for (int i = 0; i < length; i++) {
        delete container[i];
    }
    length = 0;
}

// Ввод содержимого контейнера из указанного файла.
void Container::In(FILE *fileIn) {
    int key = 0;
    while (fscanf(fileIn, "%d", &key) != EOF) {
        if (length >= MAX_LENGTH) {
            // Считываем данные, но не записываем их в контейнер, так как места в нём уже нет.
            Shape::StaticIn(fileIn, key);
            ++length;
        } else if ((container[length] = Shape::StaticIn(fileIn, key)) != nullptr) {
            ++length;
        }
    }
}

// Случайный ввод содержимого контейнера.
void Container::InRandom(int size) {
    while (length < size) {
        if ((container[length] = Shape::StaticInRandom()) != nullptr) {
            ++length;
        }
    }
}

// Вывод содержимого контейнера в указанный файл.
void Container::Out(FILE *fileOut) {
    fprintf(fileOut, "Container contains %d elements.\n", length);
    for (int i = 0; i < length; i++) {
        fprintf(fileOut, "%d: ", i);
        container[i]->Out(fileOut);
    }
}

// Отчистка контейнера от фигур с периметром, меньшим среднего значаения.
void Container::DeleteElements() {
    Container newContainer;
    double perimeters[MAX_LENGTH];
    double averagePerimeter = 0.0;
    // Считаем сумму периметров всех фигур.
    for (int i = 0; i < length; ++i) {
        perimeters[i] = (*container[i]).Perimeter();
        averagePerimeter += perimeters[i];
    }
    // Находим среднее значение периметров.
    averagePerimeter /= length;
    int index = 0;
    // Кладём в массив только те фигуры, у которых периметр больше среднего.
    for (int i = 0; i < length; i++) {
        if (perimeters[i] >= averagePerimeter) {
            newContainer.container[index] = container[i];
            ++index;
        }
    }
    *this = newContainer;
    length = index;
    newContainer.Clear();
}
