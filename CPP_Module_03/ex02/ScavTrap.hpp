#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
private:
    /* data */
public:
    ScavTrap(void);
    ScavTrap(std::string name);
    ScavTrap(ScavTrap const &copy);
    ScavTrap &operator=(ScavTrap const &copy);
    ~ScavTrap();

    
    void	guardGate(void);
    void    attack(const std::string& target);
};

#endif