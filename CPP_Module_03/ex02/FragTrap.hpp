#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP



#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
    /* data */
public:
    FragTrap(void);
    FragTrap(std::string const &name);
    FragTrap(FragTrap const &copy);
    ~FragTrap(void);

    FragTrap	&operator=(FragTrap const &copy);

    void	highFivesGuys(void);
};



#endif