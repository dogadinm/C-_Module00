/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:19:45 by mdogadin          #+#    #+#             */
/*   Updated: 2024/05/10 14:19:46 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal
{
protected:
    Animal(void);
    Animal(Animal const &copy);
    Animal      const &operator=(Animal const &copy);
    std::string type;
public:
    virtual ~Animal();

    virtual const       std::string &getType(void) const;
    virtual Brain 		&getBrain(void) const = 0;
    virtual void        makeSound(void) const;
};

#endif