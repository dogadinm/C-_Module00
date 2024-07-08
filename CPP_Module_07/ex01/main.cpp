#include "iter.hpp"

void print(std::string const &s) 
{
    std::cout << s << std::endl;
}

void plus_one(int const &n) 
{
    std::cout << n + 1  << std::endl;
}

int main(void) 
{
    std::string strings[] = {"s1", "s2", "s3"};
    int array[] = {1, 2, 3, 4, 5};
    
    ::iter(strings, 3, print);
    ::iter(array, 5, plus_one);
}