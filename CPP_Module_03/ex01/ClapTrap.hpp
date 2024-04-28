#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
    std::string _name;
    int health;
    int energyPoint;
    int attackDamadge;
public:
    ClapTrap(void);
    ClapTrap(std::string name);
    ClapTrap(ClapTrap const &copy);
    ClapTrap &operator=(ClapTrap const &copy);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    std::string const &get_name(void) const;
    int const &get_health(void) const;
    int const &get_energyPoint(void) const;
    int const &get_attackDamadge(void) const;

    void get_name(std::string const &name);
    void get_health(int const &value);
    void get_energyPoint(int const &value);
    void get_attackDamadge(int const &value);
};




#endif




