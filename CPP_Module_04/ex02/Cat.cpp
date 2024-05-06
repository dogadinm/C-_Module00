#include "Cat.hpp"

Cat::Cat(void): type("Cat")
{
	this->brain = new Brain();
	std::cout << "Cat Default Constructor called." << std::endl;
}

Cat::Cat(Cat const &copy): Animal(copy)
{
	this->type = copy.getType();
	this->brain = new Brain(*copy.brain);
	std::cout << "Cat Copy Constructor called." << std::endl;
}

Cat::~Cat(void)
{
	delete this->brain;
	std::cout << "Cat Deconstructor called." << std::endl;
}




Cat const	&Cat::operator=(Cat const &copy)
{
	std::cout << "Cat Assignation operator called." << std::endl;
	if (this != &copy) {
        this->type = copy.getType();
		Animal::operator=(copy);
		delete this->brain;
		this->brain = new Brain(*copy.brain);
	}
	return (*this);
}

const std::string &Cat::getType(void) const
{
    return(this->type);
}


Brain &Cat::getBrain(void) const
{
	return (*this->brain);
}

void	Cat::setBrain(Brain const &takenBrain)
{
	*this->brain = takenBrain;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}