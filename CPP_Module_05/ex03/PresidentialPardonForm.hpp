#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP


#include "AForm.hpp"


class Bureaucrat;
class AForm;

class PresidentialPardonForm: public AForm
{
private:
    std::string _target;
public:
    PresidentialPardonForm(void);
    PresidentialPardonForm(PresidentialPardonForm const &copy);
    PresidentialPardonForm(std::string const &target);
    ~PresidentialPardonForm();

    std::string const	&getTarget(void) const;

    PresidentialPardonForm const &operator=(PresidentialPardonForm const &copy);

    void    beExecuted(const Bureaucrat &bureaucrat) const;

};

std::ostream	&operator<<(std::ostream &str, PresidentialPardonForm const &form);



#endif