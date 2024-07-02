#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"



AForm::AForm(void): _name("default"), _isSigned(false), _gradeRequired(150), _gradeExecute(150)
{ }

AForm::AForm(std::string const name, int const gradeRequired, int const gradeExecute): _name(name) ,_isSigned(false), _gradeRequired(gradeRequired), _gradeExecute(gradeExecute)
{
    if (this->_gradeRequired < 1)
		throw (AForm::GradeTooHighException());
	else if (this->_gradeRequired > 150)
		throw (AForm::GradeTooLowException());
	if (this->_gradeExecute < 1)
		throw (AForm::GradeTooHighException());
	else if (this->_gradeExecute > 150)
		throw (AForm::GradeTooLowException());

}

AForm::AForm(AForm const &copy): _name(copy._name), _isSigned(copy._isSigned),  _gradeRequired(copy._gradeRequired), _gradeExecute(copy._gradeExecute)
{
    *this = copy;
}

AForm::~AForm()
{ }

//////////////////////////////////////////////////////////////////////////////////////////////

AForm const &AForm::operator=(AForm const &copy)
{
	this->_isSigned = copy._isSigned;
	return (*this);
}

std::ostream	&operator<<(std::ostream &str, AForm const &form)
{
    return (str << form.getName() << " form, signed: " << form.getIsSigned() << ", sign grade: " << form.getGradeRequired() << ", exec grade: " << form.getGradeExecute());
}

//////////////////////////////////////////////////////////////////////////////////////////////

std::string const &AForm::getName(void) const
{
    return(_name);
}

std::string const AForm::getIsSigned(void) const
{
    if (_isSigned == false)
        return("No");
    else
        return("Yes");
}

int const &AForm::getGradeRequired(void) const
{
    return(_gradeRequired);
}

int const  &AForm::getGradeExecute(void) const
{
    return(_gradeExecute);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeRequired)
        throw (AForm::GradeTooLowException());
    else
    {
        _isSigned = true;
        std::cout << bureaucrat.getName() << " successfully signed " << this->_name << std::endl;
    }
}

AForm	*AForm::makeForm(const std::string &type, const std::string &target)
{
	AForm	*form;

	form = NULL;
	form = ShrubberyCreationForm::makeForm(form, type, target);
	form = RobotomyRequestForm::makeForm(form, type, target);
	form = PresidentialPardonForm::makeForm(form, type, target);
	return (form);
}


//////////////////////////////////////////////////////////////////////////////////////////////

char const *AForm::GradeTooHighException::what(void) const throw()
{
    return("Grade is too high");
}

char const *AForm::GradeTooLowException::what(void) const throw()
{
    return("Grade is too low");
}

char const	*AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form not signed");
}

char const	*AForm::InvalidFormException::what(void) const throw()
{
	return ("Invalid Form Request");
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (!this->_isSigned)
		throw (AForm::FormNotSignedException());
	else if (executor.getGrade() > this->_gradeRequired)
		throw (AForm::GradeTooLowException());
	else
	{
		std::cout << executor.getName() << " executes form: " << this->_name << std::endl;
		this->beExecuted(executor);
	}
}


