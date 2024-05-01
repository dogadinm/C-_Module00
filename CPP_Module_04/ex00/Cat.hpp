#ifndef CAT_PP
#define CAT_PP

#include "Animal.hpp"

class Cat: public Animal
{
private:
    std::string	type;
public:
    Cat(void);
    Cat(std::string const &taken_type);
    Cat(Cat const &copy);
    ~Cat(void);

    Cat const	&operator=(Cat const &copy);

    // std::string const	&getType(void) const;
    // void				setType(std::string const &taken_type);

    void	makeSound(void) const;
};


#endif