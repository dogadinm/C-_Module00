#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <sstream>

class Zombie
{
private:
    std::string name;
public:

    void announce(void);
    void SetName(std::string name);

    Zombie(void);
    Zombie(std::string name);
    ~Zombie(void);

};

Zombie* zombieHorde( int N, std::string name );
Zombie* newZombie( std::string name );
void randomChump( std::string name );
#endif