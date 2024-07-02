#pragma once


#include <iostream>


class Bureaucrat;

class AForm
{
private:
    std::string const   _name;
    bool                _isSigned;
    int const           _gradeRequired;
    int const           _gradeExecute;

public:
    // Constructors and Destructors
    AForm(void);
    AForm(std::string const name, int const gradeRequired, int const gradeExecute);
    AForm(AForm const &copy);
    AForm(std::string const &type, std::string const &target);
    virtual ~AForm();

    // Geters and Setters
    std::string const           &getName(void) const;
    std::string const           getIsSigned(void) const;
    int const                   &getGradeRequired(void) const;
    int const                   &getGradeExecute(void) const;
    virtual std::string const	&getTarget(void) const = 0;

    // Operators 
    AForm const         &operator=(AForm const &copy);

    // Class members
    void                beSigned(Bureaucrat &bureaucrat);
    void                execute(Bureaucrat const &executor) const;
    virtual void	    beExecuted(Bureaucrat const &bureaucrat) const = 0;
    static AForm		*makeForm(std::string const &type, std::string const &target);

    // Exceptions
    class GradeTooHighException: public std::exception{
        public:
            virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char *what() const throw();
    };
    class FormNotSignedException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};
    class InvalidFormException: public std::exception
    {
        public:
            virtual char const	*what(void) const throw();
    };
};

std::ostream	&operator<<(std::ostream &str, AForm const &aform);

