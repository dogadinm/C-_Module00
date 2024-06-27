#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("defaut"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string const &name, int grade): _name(name)
{
    _grade = grade;
    if(_grade < 1)
        throw (GradeTooHighException());
    else if (_grade > 150)
        throw (GradeTooLowException());  
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
    if (copy._grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (copy._grade > 150)
        throw  Bureaucrat::GradeTooLowException();
    *this = copy;
}

Bureaucrat::~Bureaucrat() {}

//////////////////////////////////////////////////////////////////////////////////////////////

Bureaucrat const &Bureaucrat::operator=(Bureaucrat const &copy)
{
    if (copy._grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (copy._grade > 150)
        throw  Bureaucrat::GradeTooLowException();
    this->_grade = copy._grade;
    return (*this);
}

std::ostream	&operator<<(std::ostream &str, Bureaucrat const &bureaucrat)
{
	return (str << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade());
}

//////////////////////////////////////////////////////////////////////////////////////////////

std::string const &Bureaucrat::getName(void) const
{
    return(this->_name);
}

int const &Bureaucrat::getGrade(void) const
{
    return(this->_grade);
}

void Bureaucrat::increaseGrade(void)
{
    
    if (_grade - 1 < 1)
        throw(GradeTooHighException());
    _grade--;   
}

void Bureaucrat::decreaseGarde(void)
{
    
    if (_grade + 1 > 150)
        throw(GradeTooLowException());
    _grade++;   
}

//////////////////////////////////////////////////////////////////////////////////////////////

char const *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return("Grade is too high");
}

char const *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return("Grade is too low");
}


