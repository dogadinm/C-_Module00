
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm::AForm("RobotomyRequestForm", 72, 45), _target("null")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target): AForm::AForm("RobotomyRequestForm", 72, 45), _target(target) 
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy): AForm::AForm(copy), _target(copy._target) 
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}


RobotomyRequestForm const	&RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	AForm::operator=(copy);
	this->_target = copy._target;
	return (*this);
}

void	RobotomyRequestForm::beExecuted(const Bureaucrat &bureaucrat) const
{
	srand((unsigned) time(NULL));
	// success = rand() % 2;
	(void)bureaucrat;
	if (rand() % 2)
	{
		 std::cout << "RIZZZZZZZZZZZZZZ..." << std::endl;
		 std::cout << this->_target << " has been robotomized successfully" << std::endl;
	}
	else
		std::cout << this->_target << "'s robotomization failed" << std::endl;
}

AForm	*RobotomyRequestForm::makeForm(AForm *form, std::string const &type, std::string const &target)
{
	if (form == NULL && type == "robotomy request")
		return (new RobotomyRequestForm(target));
	return (form);
}

std::string const	&RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

std::ostream	&operator<<(std::ostream &str, RobotomyRequestForm const &form)
{
	return (str << form.getName() << " form, signed: " << form.getIsSigned() << ", sign grade: " << form.getGradeRequired() << ", exec grade: " << form.getGradeExecute());
}