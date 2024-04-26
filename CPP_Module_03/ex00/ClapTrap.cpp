#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): health(10), energyPoint(10), attackDamadge(10)
{
    std::cout << "ClapTrap " << this->_name << " created with default constructor." << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), health(10), energyPoint(10), attackDamadge(10)
{
    std::cout << "ClapTrap " << this->_name << " created with default constructor." << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->_name << " destroyed." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
    std::cout << "ClapTrap " << this->_name << " copied." << std::endl;
    *this = copy;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &copy)
{
	std::cout << "Assignment operator for ClapTrap called." << std::endl;
    this->_name = copy.get_name();
    this->health = copy.get_health();
    this->energyPoint = copy.get_energyPoint();
    this->attackDamadge = copy.get_attackDamadge();
    return (*this);
}


void ClapTrap::attack(const std::string& target)
{
    if (this->energyPoint && this->health > 0)
    {
        std::cout << "ClapTrap " << this->_name << " attacked " << target << ", hits for " << this->attackDamadge << " point(s) of damage!" << std::endl;
        this->energyPoint--;
    }
    if (this->health <= 0)
        std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
    else if (this->energyPoint <= 0)
        std::cout << "ClapTrap " << this->_name << " is out of energy points!" << std::endl;

}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->health > 0)
    {
        std::cout << "ClapTrap " << this->_name << " took " << amount << " point(s) of damage!" << std::endl;
        this->health -= amount;
    }
    else 
        std::cout << "ClapTrap " << this->_name << " is already dead" << std::endl;
    
    if (this->health < 0)
		this->health = 0;

}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->health > 0 && this->energyPoint > 0)
    {
       std::cout << "ClapTrap " << this->_name << " healed " << amount << " point(s)." << std::endl;
       this->health += amount;
       this->energyPoint--; 
    }
	if (this->health <= 0)
		std::cout << "Cannot repair because: ClapTrap " << this->_name << " is dead." << std::endl;
    else if (this->energyPoint <= 0)
        std::cout << "ClapTrap " << this->_name << " is out of energy points!" << std::endl;
}

std::string const &ClapTrap::get_name(void) const
{
    return(this->_name);
}

int const &ClapTrap::get_health(void) const
{
    return(this->health);
}
int const &ClapTrap::get_energyPoint(void) const
{
    return(this->energyPoint);
}
int const &ClapTrap::get_attackDamadge(void) const
{
    return(this->attackDamadge);
}


void ClapTrap::get_name(std::string const &name) 
{
    this->_name = name;
}

void ClapTrap::get_health(int const &value)
{
    this->health = value;
}
void ClapTrap::get_energyPoint(int const &value)
{
    this->energyPoint = value;
}
void ClapTrap::get_attackDamadge(int const &value)
{
    this->attackDamadge = value;
}