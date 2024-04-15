#include "Zombie.hpp"

Zombie::Zombie(void)
{
    name = "unnamed";
}

Zombie::Zombie(std::string name)
{
    SetName(name);
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::SetName(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << name << ": Zobmie died" << std::endl;
}

