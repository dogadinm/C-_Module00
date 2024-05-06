#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal
{
protected:
    Animal(void);
    Animal(Animal const &copy);
    Animal      const &operator=(Animal const &copy);
    std::string type;
public:
    virtual ~Animal();

    virtual const       std::string &getType(void) const;
    virtual Brain 		&getBrain(void) const = 0;
    virtual void        makeSound(void) const;
};

#endif