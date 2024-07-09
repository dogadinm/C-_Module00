#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>


template<typename T>

class Array
{
private:
    T *_array;
    unsigned int _size;
public:
    Array();
    Array(unsigned int n);
    Array(const Array<T> &copy);
    ~Array();

    Array &operator=(const Array &copy);
    T &operator[](unsigned int index);
    unsigned int getSize() const;

    class ExceptionIndexError: public std::exception
    {
        public:
            virtual const char *what() const  throw();
    };

};

#include "Array.tpp"

#endif