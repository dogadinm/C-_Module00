#ifndef DOG_HPP
#define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal
{
private:
    std::string	type;
public:
    Dog(void);
    Dog(std::string const &taken_type);
    Dog(Dog const &copy);
    ~Dog(void);

    Dog const	&operator=(Dog const &copy);

    void	makeSound(void) const;
};

#endif