
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	std::cout << "HumanA " << name << " with ";
	std::cout << weapon.getType() << std::endl;
}

void HumanA::attack()
{
    std::cout << this->_name << " attacks with their" << this->_weapon.getType() << std::endl;
}

void HumanA::setWeapon(Weapon weapon)
{
    this->_weapon = weapon;
}

HumanA::~HumanA()
{
    std::cout << "HumanA" << " destroid" << std::endl;
}
