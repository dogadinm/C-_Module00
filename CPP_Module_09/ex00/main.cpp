#include "BitcoinExchange.hpp"


int main(int argc, char **argv)
{
    BitcoinExchange i;

    if (argc == 1)
        std::cout << "cant open input" << std::endl;

    i.getValue(argv[1]);

}