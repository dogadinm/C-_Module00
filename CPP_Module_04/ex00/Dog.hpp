/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:18:03 by mdogadin          #+#    #+#             */
/*   Updated: 2024/05/10 14:18:04 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal
{
private:
    std::string	type;
public:
    Dog(void);
    Dog(Dog const &copy);
    ~Dog(void);

    Dog const	&operator=(Dog const &copy);

    const std::string &getType(void) const;
    void	makeSound(void) const;
};

#endif