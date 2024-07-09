#include "Array.hpp"

template <typename T>
Array<T>::Array(): _array(new T[0]), _size(0)
{
    std::cout << "Default Constructor called: created empty Array of size 0" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    std::cout << "Constructor for an Array of size " << n << " called" << std::endl;
    _size = n;
    _array = new T[_size];
    for (unsigned  int i = 0; i < _size; i++)
        _array[i] = 0;

}

template <typename T>
Array<T>::Array(const Array<T> &copy):_size(copy.getSize())
{
    std::cout << "Copy Constuctor called" << std::endl;
    _array = NULL;
    *this = copy;
}

template <typename T>
Array<T>::~Array()
{
    std::cout << "Deconstructor called" << std::endl;
    if (this->_array != NULL)
        delete[] _array;
}

template <typename T>
unsigned int Array<T>::getSize() const
{
    return(_size);
}


template <typename T>
Array<T> &Array<T>::operator=(const Array &copy)
{
    if (_array != NULL)
        delete [] _array;
    if(copy.getSize() != 0)
    {
        _size = copy.getSize();
        _array = new T[_size];
        for (unsigned int i = 0; i < getSize(); i++)
            _array[i] = copy._array[i];
    }
    return (*this);
}


template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= _size || _array == NULL)
    {
        // std::cout << "index: " << index << std::endl;
        throw(Array<T>::ExceptionIndexError());
    }
    return(_array[index]);


}

template <typename T>
const char* Array<T>::ExceptionIndexError::what() const throw()
{
    return ("Error: Invalid index");
}