#include "HumanB.hpp"


HumanB::HumanB(std::string name) : _name(name)
{
    std::cout << "HumanB " << name << " created with no weapon" << std::endl;   
}

void HumanB::attack()
{
    std::cout << this->_name << " attacks with their" << this->weapon->getType() << std::endl;
}
void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

HumanB::~HumanB()
{
    std::cout << "HumanB" << " destroid" << std::endl;
}
