#include "Zombie.hpp"


int main()
{

	int	size;

	size = 5;
	Zombie *horde = zombieHorde(size, "Zom");
	for (int i = 0; i < size; i++)
		horde[i].announce();
	delete [] horde;
    // Zombie *head;

    // head = newZombie("Heap");
    // head->announce();
    // randomChump("Stack");

	// delete head;
	return 0;
}