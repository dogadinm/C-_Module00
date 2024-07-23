/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:18:41 by mdogadin          #+#    #+#             */
/*   Updated: 2024/05/10 14:18:42 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_PP
#define CAT_PP

#include "Animal.hpp"

class Cat: public Animal
{
private:
    std::string	type;
    Brain		*brain;
public:
    Cat(void);
    Cat(Cat const &copy);
    ~Cat(void);

    Cat const	&operator=(Cat const &copy);

    const std::string   &getType(void) const;
    Brain 				&getBrain(void) const;
    void				setBrain(Brain const &takenBrain);
    void	            makeSound(void) const;
};


#endif