#include "Phonebook.hpp"

void	putst(std::string temp)
{
	std::cout << " | ";
	if (temp.size() > 10)
	{
		temp.resize(9);
		std::cout << temp;
		std::cout << ".";
	}
	else
		std::cout << temp;
}

int main()
{
    PhoneBook contact;
    std::string command;
    int choose_contact;
    contact.index = 0;
     
    while(1)
    {
        system("clear");
        std::cout << "Commands : ADD , SEARCH , EXIT " << std::endl;
        std::cout << "Phonebook " << '[' << contact.index << '/' << '8' << ']' << std::endl; ;
        std::cout << "Enter command : ";
        std::cin >> command;
        if (command == "ADD")
        {
            if (contact.index <= 7)
            {            
                system("clear");
                std::cout << "Adding new contact " << std::endl;
                std::cout << "Enter first name: ";
                std::cin >> contact.Catalog[contact.index].First_name;
                system("clear");
                std::cout << "Adding new contact " << std::endl;
                std::cout << "Enter last name: ";
                std::cin >> contact.Catalog[contact.index].Last_name;
                system("clear");
                std::cout << "Adding new contact " << std::endl;
                std::cout << "Enter nickname: ";
                std::cin >> contact.Catalog[contact.index].Nickname;
                system("clear");
                std::cout << "Adding new contact " << std::endl;
                std::cout << "Phone number: ";
                std::cin >> contact.Catalog[contact.index].phone;
                system("clear");
                std::cout << "Adding new contact " << std::endl;
                std::cout << "Dark secret: ";
                std::cin >> contact.Catalog[contact.index].secret;
                contact.index++;
            }
            else
            {
                while (1)
                {
                    std::cout << "Phonebook full" << std::endl;
                    std::cout << "Enter BACK to main menu: ";
                    std::cin >> command;
                    if (command == "BACK")
                        break;
                }
            }
        }
        else if (command == "SEARCH")
        {
			for (int i = 0; i < contact.index; i++)
			{
				std::string temp;
				std::cout << i + 1 ;
				putst(contact.Catalog[i].First_name);
				putst(contact.Catalog[i].Last_name);
				putst(contact.Catalog[i].Nickname);
				putst(contact.Catalog[i].phone);
				putst(contact.Catalog[i].secret);
				std::cout << " | " << std::endl;
			}
            std::cout << "Enter index of contact : ";
            std::cin >> choose_contact;
            choose_contact--;
            if (choose_contact < contact.index && choose_contact >= 0 && choose_contact < 8)
            {
                std::cout << std::endl;
                std::cout << "First name: " << contact.Catalog[choose_contact].First_name << std::endl;
                std::cout << "Last name: " << contact.Catalog[choose_contact].Last_name << std::endl;
                std::cout << "Nickname: " << contact.Catalog[choose_contact].Nickname << std::endl;
                std::cout << "Phone number: "<< contact.Catalog[choose_contact].phone << std::endl;
                std::cout << "Dark secret: "<< contact.Catalog[choose_contact].secret << std::endl;
                std::cout << std::endl;
            }
            else
                std::cout << "Invalid" << std::endl;
            while (1)
            {
                std::cout << "Enter BACK to main menu: ";
                std::cin >> command;
                if (command == "BACK")
                    break;
            }
        }
        else if (command == "EXIT")
            break;
    }
    return (0);
}