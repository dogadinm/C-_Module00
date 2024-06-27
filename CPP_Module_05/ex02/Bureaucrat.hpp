
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"
class AForm;

class Bureaucrat
{
private:
    std::string const _name;
    int _grade;
public:
    Bureaucrat(void);
    Bureaucrat(std::string const &name, int grade);
    Bureaucrat(Bureaucrat const &copy);
    ~Bureaucrat();

    Bureaucrat const    &operator=(Bureaucrat const &copy);
    std::string const   &getName(void) const;
    int const           &getGrade(void) const;


    void    increaseGrade(void);
    void    decreaseGarde(void);

    void	executeForm(AForm const &form);

    class GradeTooHighException: public std::exception{
        public:
            virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char *what() const throw();
    };

    void	signForm(AForm &form);

};

std::ostream & operator<<(std::ostream & str, Bureaucrat const & bureaucrat);

#endif