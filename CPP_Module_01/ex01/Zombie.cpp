#include "Zombie.hpp"

void Zombie::SetName(std::string name)
{
    this->name = name;
}


Zombie::Zombie(void)
{
    name = "unnamed";
}

Zombie::Zombie(std::string name)
{
    SetName(name);
}

void Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << name << ": Zobmie died" << std::endl;
}

