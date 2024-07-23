/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:18:14 by mdogadin          #+#    #+#             */
/*   Updated: 2024/05/10 14:18:14 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
	std::cout << "Passing through WrongAnimal default constructor" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Passing through WrongAnimal destructor" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy)
{
	std::cout << "Passing through WrongAnimal copy constructor" << std::endl;
	*this = copy;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &copy)
{
	std::cout << "Passing through WrongAnimal operator=() overload" << std::endl;
	this->type = copy.getType();
	return *this;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Some noise" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}