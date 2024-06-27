#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    std::string const _name;
    bool _isSigned;
    int const _gradeRequired;
    int const _gradeExecute;

public:
    Form(void);
    Form(std::string const name, int const gradeRequired, int const gradeExecute);
    Form(Form const &copy);
    virtual ~Form();

    std::string const &getName(void) const;
    std::string const getIsSigned(void) const;
    int const &getGradeRequired(void) const;
    int const  &getGradeExecute(void) const;

    void beSigned(Bureaucrat &bureaucrat);
    

    Form const &operator=(Form const &copy);

    class GradeTooHighException: public std::exception{
        public:
            virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char *what() const throw();
    };   
};

std::ostream	&operator<<(std::ostream &str, Form const &form);

#endif