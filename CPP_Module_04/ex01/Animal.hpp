#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal
{
protected:
    std::string type;
public:
    Animal(void);
    Animal(Animal const &copy);
    virtual ~Animal();

    Animal const &operator=(Animal const &copy);

    virtual const std::string &getType(void) const;
    virtual Brain 		&getBrain(void) const = 0;

    virtual void    makeSound(void) const;
};

#endif