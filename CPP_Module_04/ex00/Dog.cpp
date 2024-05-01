#include "Dog.hpp"

Dog::Dog(void): type("Dog")
{
	std::cout << this->type << " from Animal " << Animal::type << " created with default constructor." << std::endl;
}

Dog::Dog(Dog const &copy): Animal(copy)
{
	*this = copy;
	std::cout << "Dog from Animal " << Animal::type << " copied." << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog from Animal " << Animal::type << " destroyed." << std::endl;
}



Dog::Dog(std::string const &taken_type): Animal(taken_type), type("Dog")
{
	std::cout << this->type << " from Animal " << Animal::type << " created." << std::endl;
}
Dog const	&Dog::operator=(Dog const &copy)
{
	std::cout << "Assignment operator for Dog from Animal " << Animal::type << " called." << std::endl;
	Animal::operator=(copy);
	return (*this);
}



void	Dog::makeSound(void) const
{
	std::cout << "Dog From Animal " << Animal::type << " goes Bark!" << std::endl;
}