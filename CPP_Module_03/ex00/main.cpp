#include "ClapTrap.hpp"

void	misha_hits(void)
{
	ClapTrap misha("Misha");

	misha.attack("Bob");
	misha.attack("Chris");
	misha.attack("Diana");
	misha.attack("Elisa");
	misha.attack("Fred");
	misha.attack("Gemma");
	misha.attack("Henry");
	misha.attack("Isabella");
	misha.attack("Jack");
	misha.attack("Kevin");
	misha.attack("Laura");
	misha.attack("Mike");
}

void	egor_get_hit(void)
{
	ClapTrap	egor("Egor");

	while (egor.get_health())
	{
		egor.takeDamage(2);
		egor.beRepaired(2);
	}
	egor.takeDamage(1);
}

int	main(void)
{
	std::cout << std::endl << std::endl << "Performing Misha's rundown..." << std::endl << std::endl;
	misha_hits();
	std::cout << std::endl << std::endl << "Performing Egor's rundown..." << std::endl << std::endl;
	egor_get_hit();
}