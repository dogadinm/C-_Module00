/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:18:26 by mdogadin          #+#    #+#             */
/*   Updated: 2024/05/10 14:18:26 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("animal")
{
    std::cout << "Animal created with default constructor." << std::endl;
}

Animal::Animal(Animal const &copy) : type(copy.type)
{
    std::cout << "Animal Copy Constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal Deconstructor called." << std::endl;
}


Animal const &Animal::operator=(Animal const &copy)
{
    std::cout << "Assignment operator for Animal called." << std::endl;
    if (this != &copy)
    {
        this->type = copy.getType();
    }
    return(*this);
}


const std::string &Animal::getType(void) const
{
    return(this->type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Some sound" << std::endl;
}
