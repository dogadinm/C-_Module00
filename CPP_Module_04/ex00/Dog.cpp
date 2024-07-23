/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:18:00 by mdogadin          #+#    #+#             */
/*   Updated: 2024/05/10 14:18:01 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): type("Dog")
{
	std::cout << "Dog Default Constructor called." << std::endl;
}

Dog::Dog(Dog const &copy): Animal(copy)
{
	*this = copy;
	std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog Deconstructor called." << std::endl;
}



Dog const	&Dog::operator=(Dog const &copy)
{
	std::cout << "Dog Assignation operator called." << std::endl;
    if (this != &copy)
    {
        this->type = copy.getType();
		Animal::operator=(copy);
    }
	return (*this);
}

const std::string &Dog::getType(void) const
{
    return(this->type);
}

void	Dog::makeSound(void) const
{
	std::cout << "Bark!" << std::endl;
}