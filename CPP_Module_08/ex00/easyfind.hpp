#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <iostream>
#include <algorithm>

class ErrorNotFound : public std::exception
{
    const char *what() const throw()
    {
        return("Not found");
    }
};

template<typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = find(container.begin(), container.end(), value);
    if (it == container.end())
        throw ErrorNotFound();
    return it;
}



#endif