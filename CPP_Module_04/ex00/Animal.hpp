#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
    std::string type;
public:
    Animal(void);
    Animal(std::string take_type);
    Animal(Animal const &copy);
    virtual ~Animal();

    Animal &operator=(Animal const &copy);

    void setType(std::string const &taken_type);
    const std::string &getType(void) const;

    virtual void    makeSound(void) const;
};

#endif