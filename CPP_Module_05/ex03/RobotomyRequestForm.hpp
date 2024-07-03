#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP



#include "AForm.hpp"
#include <cstdlib>

class Bureaucrat;
class AForm;

class RobotomyRequestForm: public AForm
{
private:
    std::string	_target;
public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &copy);
		~RobotomyRequestForm(void);

        RobotomyRequestForm const	&operator=(RobotomyRequestForm const &copy);

        void	beExecuted(Bureaucrat const &bureaucrat) const;

		/* Getters & Setters */
		std::string const	&getTarget(void) const;
};

std::ostream	&operator<<(std::ostream &str, RobotomyRequestForm const &form);
#endif
