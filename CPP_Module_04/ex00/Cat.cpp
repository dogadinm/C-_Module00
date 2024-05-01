#include "Cat.hpp"

Cat::Cat(void): type("Cat")
{
	std::cout << "Cat from Animal " << Animal::type << " created with default constructor." << std::endl;
}

Cat::Cat(std::string const &taken_type):Animal(taken_type), type("Cat")
{
	std::cout << "Cat from Animal " << Animal::type << " created." << std::endl;
}

Cat::~Cat(void)
{
	std::cout << this-> type << "Cat from Animal " << Animal::type << " destroyed." << std::endl;
}



Cat::Cat(Cat const &copy): Animal(copy)
{
	*this = copy;
	std::cout << "Cat from Animal " << Animal::type << " copied." << std::endl;
}

Cat const	&Cat::operator=(Cat const &copy)
{
	std::cout << "Assignment operator for Cat from Animal " << Animal::type << " called." << std::endl;
	Animal::operator=(copy);
	return (*this);
}



void	Cat::makeSound(void) const
{
	std::cout << "Cat From Animal " << Animal::type << " goes Meow!" << std::endl;
}