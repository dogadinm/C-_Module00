
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm::AForm("PresidentialPardonForm", 25, 5), _target("null")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target): AForm::AForm("PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy): AForm::AForm(copy), _target(copy._target)
{

}


PresidentialPardonForm::~PresidentialPardonForm(){}


PresidentialPardonForm const	&PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	AForm::operator=(copy);
	this->_target = copy._target;
	return (*this);
}


void	PresidentialPardonForm::beExecuted(const Bureaucrat &bureaucrat) const
{
	(void)bureaucrat;
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

AForm	*PresidentialPardonForm::makeForm(AForm *form, std::string const &type, std::string const &target)
{
	if (form == NULL && type == "presidential pardon")
		return (new PresidentialPardonForm(target));
	return (form);
}

std::string const	&PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}


std::ostream	&operator<<(std::ostream &str, PresidentialPardonForm const &form)
{
	return (str << form.getName() << " form, signed: " << form.getIsSigned() << ", sign grade: " << form.getGradeRequired() << ", exec grade: " << form.getGradeExecute());
}

