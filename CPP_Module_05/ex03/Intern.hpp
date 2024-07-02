#ifndef INTERN_HPP
#define INTERN_HPP


#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

class Form;

class Intern
{
	public:
		/* Constructors & Destructors */
		Intern(void);
		Intern(Intern const &copy);
		~Intern(void);

		/* Basic Operators */
		Intern const	&operator=(Intern const &copy);

		/* Main Member Functions */
		AForm	*makeForm(std::string const &type, std::string const &target);
};

#endif