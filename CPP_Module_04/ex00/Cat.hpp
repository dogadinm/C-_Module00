/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:17:57 by mdogadin          #+#    #+#             */
/*   Updated: 2024/05/10 14:17:57 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal
{
private:
    std::string	type;
public:
    Cat(void);
    Cat(Cat const &copy);
    ~Cat(void);

    Cat const	&operator=(Cat const &copy);

    const   std::string &getType(void) const;
    void	makeSound(void) const;
};


#endif