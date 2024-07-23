/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:17:54 by mdogadin          #+#    #+#             */
/*   Updated: 2024/05/10 14:17:55 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): type("Cat")
{
	std::cout << "Cat Default Constructor called." << std::endl;
}

Cat::Cat(Cat const &copy): Animal(copy)
{
	this->type = copy.getType();
	std::cout << "Cat Copy Constructor called." << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat Deconstructor called." << std::endl;
}



Cat const	&Cat::operator=(Cat const &copy)
{
	std::cout << "Cat Assignation operator called." << std::endl;
    if (this != &copy)
    {
        this->type = copy.getType();
		Animal::operator=(copy);
    }
    return(*this);
}

const std::string &Cat::getType(void) const
{
    return(this->type);
}


void	Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}