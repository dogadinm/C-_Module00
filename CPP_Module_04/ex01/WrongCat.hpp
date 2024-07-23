/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:19:09 by mdogadin          #+#    #+#             */
/*   Updated: 2024/05/10 14:19:09 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP


#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public :

	WrongCat();
	virtual ~WrongCat();
	WrongCat(const WrongCat &copy);
    
	WrongCat &operator=(const WrongCat &copy);

	void makeSound() const;
};

#endif