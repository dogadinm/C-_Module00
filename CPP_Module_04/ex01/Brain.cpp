/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:18:31 by mdogadin          #+#    #+#             */
/*   Updated: 2024/05/10 14:18:31 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain created with default constructor." << std::endl;
}

Brain::Brain(Brain const &copy)
{
	*this = copy;
	std::cout << "Brain copied." << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain destroyed." << std::endl;
}

Brain const	&Brain::operator=(Brain const &copy)
{
	std::copy(copy.ideas, copy.ideas + 100, this->ideas);
	std::cout << "Assignment operator for Brain called." << std::endl;
	return (*this);
}

std::string const	&Brain::getIdea(int const &index) const
{
	if (index >= 0 && index < 100)
		return (this->ideas[index]);
	return (this->ideas[0]);
}

void	Brain::setIdea(std::string const &takenIdea, int const &index)
{
	if (index >= 0 && index < 100)
		this->ideas[index] = takenIdea;
}