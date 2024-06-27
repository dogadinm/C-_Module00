#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP



#include "AForm.hpp"
#include "Bureaucrat.hpp"


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

};

std::ostream	&operator<<(std::ostream &str, RobotomyRequestForm const &form);
#endif
