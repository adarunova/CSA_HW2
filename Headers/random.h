#ifndef HW1_RANDOM_H
#define HW1_RANDOM_H

// random.h - содержит генератор случайных чисел в диапазоне от min до max.

#include <stdlib.h>
#include <time.h>

class Random {
private:
    // Границы генерации рандомного числа.
    int min;
    int max;

public:
    Random(int first, int last) {
        if(first <= last) {
            min = first;
            max = last;
        } else {
            min = last;
            max = first;
        }
        // Системные часы в качестве инициализатора.
        srand(static_cast<unsigned int>(time(0)));
    }

    // Генерирует числа в диапазоне от min до max.
    int Get() {
        return rand() % (max - min + 1) + min;
    }
};

#endif //HW1_RANDOM_H
