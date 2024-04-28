#include "FragTrap.hpp"

void	misha_hits(void)
{
	FragTrap misha("Misha");

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
	misha.highFivesGuys();
}

void	egor_get_hit(void)
{
	FragTrap	egor("Egor");

	while (egor.get_health())
	{
		egor.takeDamage(2);
		egor.beRepaired(2);
	}
	egor.takeDamage(1);
	egor.highFivesGuys();
}

int	main(void)
{
	std::cout << std::endl << std::endl << "Performing Misha's rundown..." << std::endl << std::endl;
	misha_hits();
	std::cout << std::endl << std::endl << "Performing Egor's rundown..." << std::endl << std::endl;
	egor_get_hit();
}