#include "Form.hpp"


Form::Form(void): _name("default"), _isSigned(false), _gradeRequired(150), _gradeExecute(150)
{ }

Form::Form(std::string const name, int const gradeRequired, int const gradeExecute): _name(name) ,_isSigned(false), _gradeRequired(gradeRequired), _gradeExecute(gradeExecute)
{
    if (this->_gradeRequired < 1)
		throw (Form::GradeTooHighException());
	else if (this->_gradeRequired > 150)
		throw (Form::GradeTooLowException());
	if (this->_gradeExecute < 1)
		throw (Form::GradeTooHighException());
	else if (this->_gradeExecute > 150)
		throw (Form::GradeTooLowException());

}

Form::Form(Form const &copy): _name(copy._name), _isSigned(copy._isSigned),  _gradeRequired(copy._gradeRequired), _gradeExecute(copy._gradeExecute)
{
    *this = copy;
}

Form::~Form()
{ }

//////////////////////////////////////////////////////////////////////////////////////////////

Form const &Form::operator=(Form const &copy)
{
	this->_isSigned = copy._isSigned;
	return (*this);
}

std::ostream	&operator<<(std::ostream &str, Form const &form)
{
    return (str << form.getName() << " form, signed: " << form.getIsSigned() << ", sign grade: " << form.getGradeRequired() << ", exec grade: " << form.getGradeExecute());
}

//////////////////////////////////////////////////////////////////////////////////////////////

std::string const &Form::getName(void) const
{
    return(_name);
}

std::string const Form::getIsSigned(void) const
{
    if (_isSigned == false)
        return("No");
    else
        return("Yes");
}

int const &Form::getGradeRequired(void) const
{
    return(_gradeRequired);
}

int const  &Form::getGradeExecute(void) const
{
    return(_gradeExecute);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeRequired)
        throw (Form::GradeTooLowException());
    else
    {
        _isSigned = true;
        std::cout << bureaucrat.getName() << " successfully signed " << this->_name << std::endl;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////

char const *Form::GradeTooHighException::what(void) const throw()
{
    return("Grade is too high");
}

char const *Form::GradeTooLowException::what(void) const throw()
{
    return("Grade is too low");
}



