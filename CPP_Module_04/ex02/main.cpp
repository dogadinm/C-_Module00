#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <sstream>
#include <string>
#define N_ANIMALS 4


int	main( void )
{
	Animal *tab[N_ANIMALS];
	Brain *catBrain;
	Brain *catBrain1;
	Brain *dogBrain;
	Brain *dogBrain1;

	for (int i = 0; i < N_ANIMALS; i++)
	{
		if (i < 2)
		{
			tab[i] = new Dog();
			tab[i]->makeSound();
		}
		else
		{
			tab[i] = new Cat();
			tab[i]->makeSound();
		}
	}
	catBrain = &tab[0]->getBrain();
	catBrain1 = &tab[1]->getBrain();
	dogBrain = &tab[2]->getBrain();
	dogBrain1 = &tab[3]->getBrain();
	for (int i = 0; i < 110; i++)
	{
        std::ostringstream oss;
        oss << "he he cat brain " << i;  
        catBrain->setIdea(oss.str(), i);
		oss.str("");
		catBrain1->setIdea("he he cat brain ", i);

		oss << "he he dog brain " << i;
		dogBrain->setIdea(oss.str(), i);
		dogBrain1->setIdea("he he dog brain ", i);
	}
	for (int i = 0; i < 4; i++)
	{
		std::cout << "------------------" << std::endl;
		for (int j = 0; j < 110; j++)
		{
			std::cout << "|" << tab[i]->getBrain().getIdea(j) << "|" << std::endl;
		}
		std::cout << "------------------" << std::endl;
		
	}

	delete tab[0];
	delete tab[1];
	delete tab[2];
	delete tab[3];

	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Dog class using copy constructor:\n" << std::endl;
		Dog *dogA = new Dog;
		Dog *dogB = new Dog(*dogA);

		delete dogA;
		delete dogB;
	}
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Dog class using assignment operator overload:\n" << std::endl;
		Dog *dogA = new Dog;
		Dog *dogB = new Dog;

		*dogA = *dogB;
		delete dogA;
		delete dogB;
	}

	return (0);
}
