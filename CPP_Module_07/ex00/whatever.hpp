#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>

void swap(T &a, T &b)
{
    T c;
    c = a;
    a = b;
    b = c;
}

template <typename T>
const T &min(const T &a, const T &b)
{
    return(b <= a ? b : a);
}

template <typename T>
const T &max(const T &a, const T &b)
{
    return(b >= a ? b : a);
}

#endif