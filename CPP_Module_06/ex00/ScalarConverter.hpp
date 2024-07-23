/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:58:39 by mdogadin          #+#    #+#             */
/*   Updated: 2024/07/14 15:00:24 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>


class ScalarConverter
{
private:
    ScalarConverter(void);
    ScalarConverter(const ScalarConverter &copy); 
    ~ScalarConverter();
    
public:
    ScalarConverter &operator=(const ScalarConverter &copy);

    static void convert(const std::string &literal);
};




#endif