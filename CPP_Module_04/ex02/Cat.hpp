#ifndef CAT_PP
#define CAT_PP

#include "Animal.hpp"

class Cat: public Animal
{
private:
    std::string	type;
    Brain		*brain;
public:
    Cat(void);
    Cat(Cat const &copy);
    ~Cat(void);

    Cat const	&operator=(Cat const &copy);

    const std::string   &getType(void) const;
    Brain 				&getBrain(void) const;
    void				setBrain(Brain const &takenBrain);
    void	            makeSound(void) const;
};


#endif