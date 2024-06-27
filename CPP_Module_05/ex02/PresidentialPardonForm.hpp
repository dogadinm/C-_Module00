#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP


#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat; 

class PresidentialPardonForm: public AForm
{
private:
    std::string _target;
public:
    PresidentialPardonForm(void);
    PresidentialPardonForm(PresidentialPardonForm const &copy);
    PresidentialPardonForm(std::string const &target);
    ~PresidentialPardonForm();

    PresidentialPardonForm const &operator=(PresidentialPardonForm const &copy);

    void    beExecuted(const Bureaucrat &bureaucrat) const;

};

std::ostream	&operator<<(std::ostream &str, PresidentialPardonForm const &form);



#endif