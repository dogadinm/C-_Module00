/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdogadin <mdogadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:58:36 by mdogadin          #+#    #+#             */
/*   Updated: 2024/07/14 14:58:36 by mdogadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    *this = copy;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
    (void)copy;
    return(*this);
}

void ScalarConverter::convert(const std::string &literal)
{
    std::string toChar = "";
	int toInt = 0;
	float toFloat = 0;
	double toDouble = 0;

    std::string pseudoLiterals[6] = {
        "-inff", "+inff", "nanf","-inf", "+inf", "nan" 
    };

    if (literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
    {
        toChar = literal[0];
        toInt = static_cast<int>(toChar[0]);
	    toFloat = static_cast<float>(toChar[0]);
	    toDouble = static_cast<double>(toChar[0]);
        std::cout << "char:" << toChar << std::endl;
        std::cout << "int:" << toInt << std::endl;
        std::cout << "float:" << toFloat << ".0f" <<std::endl;
        std::cout << "double:" << toDouble << ".0"<< std::endl;
        return;
    }

    toInt = std::atoi(literal.c_str());
    if (literal[literal.length() - 1] == 'f')
    {
        toFloat = std::atof(literal.c_str());
        toDouble = static_cast<double>(toFloat);
    }
    else
    {
        toDouble = std::atof(literal.c_str());
        toFloat = static_cast<float>(toDouble);
    }

    for (int i; i < 6 ; i++)
    {
        if (literal == pseudoLiterals[i])
        {
            toChar = "imposible";
        }
    }

    if (toChar == "" && std::isprint(toInt))
    {
        toChar = "'";
		toChar += static_cast<char>(toInt);
		toChar += "'";
    }
    else if (toChar == "")
    {
        toChar = "Non displayable";
    }

    std::cout << "char: " << toChar << std::endl;
    if (toChar == "imposible" || toChar == "Non displayable")
        std::cout << "int: imposible" << std::endl;
    else
        std::cout << "int: " << toInt << std::endl;

    if ((toChar == "imposible"  || toChar == "Non displayable") && toFloat == 0)
    {
  		std::cout << "float: imposible" << std::endl;
		std::cout << "double: imposible" << std::endl;      
    }
    else
    {
        if (toChar != "imposible" && toFloat - static_cast<int>(toFloat) == 0) 
		{
			std::cout << "float: " << toFloat << ".0f" << std::endl;
			std::cout << "double: " << toDouble << ".0" << std::endl;
		}
		else 
		{
			std::cout << "float: " << toFloat << "f" << std::endl;
			std::cout << "double: " << toDouble << std::endl;
		}
    }


}