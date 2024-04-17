#include "Harl.hpp"

int	karen_translate(char *argv)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
		if (levels[i] == argv)
			return (i);
	return (-1);
}

void	karen_switch(char *argv, Harl &k)
{
	switch (karen_translate(argv))
	{
		case 0:
			k.complain("DEBUG");
		case 1:
			k.complain("INFO");
		case 2:
			k.complain("WARNING");
		case 3:
			k.complain("ERROR");
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

int	main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	else
		karen_switch(argv[1], harl);
	return (0);
}