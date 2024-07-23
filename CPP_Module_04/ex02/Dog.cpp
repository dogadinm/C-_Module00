/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:20:00 by mdogadin          #+#    #+#             */
/*   Updated: 2024/05/10 14:20:00 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): type("Dog")
{
	this->brain = new Brain();
	std::cout << "Dog Default Constructor called." << std::endl;
}

Dog::Dog(Dog const &copy): Animal(copy)
{
	Animal::type = copy.getType();
	this->brain = new Brain(*copy.brain);
	std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog::~Dog(void)
{
	delete this->brain;
	std::cout << "Dog Deconstructor called." << std::endl;
}


Dog const	&Dog::operator=(Dog const &copy)
{
	std::cout << "Dog Assignation operator called." << std::endl;
	if (this != &copy) {
        this->type = copy.getType();
		Animal::operator=(copy);
		delete this->brain;
		this->brain = new Brain(*copy.brain);
	}
	return *this;
}



Brain &Dog::getBrain(void) const
{
	return (*this->brain);
}

void	Dog::setBrain(Brain const &takenBrain)
{
	*this->brain = takenBrain;
}

const std::string &Dog::getType(void) const
{
    return(this->type);
}

void	Dog::makeSound(void) const
{
	std::cout << "Bark!" << std::endl;
}