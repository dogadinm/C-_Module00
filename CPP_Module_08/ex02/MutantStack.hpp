#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
private:

public:
    typedef typename std::stack<T>::container_type::iterator iterator;

    MutantStack() : std::stack<T>(){
        // std::cout << "Default Constructor called" << std::endl;
    }
    MutantStack(MutantStack   const &copy) : std::stack<T>(copy){
        // std::cout << "Copy Constructor called" << std::endl;
    }
    ~MutantStack(){
        // std::cout << "Deconstuctor called" << std::endl;
        this->c.clear();
    }

    MutantStack  &operator=(MutantStack  const &copy)
    {
        if (*this != copy)
            *this = copy;
        return (*this);
    }

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }

};

