#include "Zombie.hpp"


int main()
{
    Zombie *head;

    head = newZombie("Heap");
    head->announce();
    randomChump("Stack");

	delete head;
	return 0;
}