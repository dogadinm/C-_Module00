#include "Animal.hpp"

Animal::Animal(void) : type("unknow type")
{
    std::cout << "Animal " << this->type << " created with default constructor." << std::endl;
}

Animal::Animal(std::string take_type) : type(take_type)
{
    std::cout << "Animal " << this->type << " created." << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal " << this->type << " destroyed." << std::endl;
}



Animal::Animal(Animal const &copy)
{
    *this = copy;
    std::cout << "Animal " << this->type << " copied." << std::endl; 
}

Animal &Animal::operator=(Animal const &copy)
{
    std::cout << "Assignment operator for Animal " << this->type << " called." << std::endl;
    if (this != &copy)
    {
        type = copy.getType();
    }
    return(*this);
}



void Animal::setType(const std::string &taken_type)
{
    this->type = taken_type;
}

const std::string &Animal::getType(void) const
{
    return(this->type);
}



void	Animal::makeSound(void) const
{
	std::cout << "Animal " << this->type << " made a sound!" << std::endl;
}