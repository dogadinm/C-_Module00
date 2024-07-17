#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename T2>

void iter(T *array, size_t length,  T2 f)
{
    for (size_t i = 0; i < length; i++) {
        f(array[i]);
    }
}

#endif