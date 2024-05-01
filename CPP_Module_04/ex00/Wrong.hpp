#include <iostream>

class WrongAnimal
{
protected:
    std::string	_type;
public:
    WrongAnimal(void);
    WrongAnimal(std::string const &type);
    WrongAnimal(WrongAnimal const &copy);
    virtual ~WrongAnimal(void);

    WrongAnimal const	&operator=(WrongAnimal const &copy);

    std::string const	&getType(void) const;
    void				setType(std::string const &type);

    void	makeSound(void) const;
};

class WrongCat: public WrongAnimal
{
private:
    std::string	_type;
public:
    WrongCat(void);
    WrongCat(std::string const &type);
    WrongCat(WrongCat const &copy);
    ~WrongCat(void);

    WrongCat const	&operator=(WrongCat const &copy);

    std::string const	&getType(void) const;
    void				setType(std::string const &type);

    void	makeSound(void) const;
};