#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>

class Contact
{
public:

	std::string		First_name;
	std::string		Last_name;
	std::string		Nickname;
	std::string		phone;
	std::string		secret;
};

class PhoneBook
{
public:

	Contact Catalog[8];
	int		index;
};

#endif