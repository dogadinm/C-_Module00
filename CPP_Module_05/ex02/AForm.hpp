#ifndef AForm_HPP
# define AForm_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    std::string const _name;
    bool _isSigned;
    int const _gradeRequired;
    int const _gradeExecute;

public:
    AForm(void);
    AForm(std::string const name, int const gradeRequired, int const gradeExecute);
    AForm(AForm const &copy);
    AForm(std::string const &type, std::string const &target);
    virtual ~AForm();

    std::string const &getName(void) const;
    std::string const getIsSigned(void) const;
    int const &getGradeRequired(void) const;
    int const  &getGradeExecute(void) const;

    void beSigned(Bureaucrat &bureaucrat);
    

    AForm const &operator=(AForm const &copy);
    
    AForm const execute(Bureaucrat const & executor) const;

    class GradeTooHighException: public std::exception{
        public:
            virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char *what() const throw();
    };   
};

std::ostream	&operator<<(std::ostream &str, AForm const &aform);

#endif