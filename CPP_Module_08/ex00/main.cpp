#include "easyfind.hpp"


int main()
{
    std::vector<int> array;
    for (int i = 0; i <= 100; i++)
        array.push_back(i);
    // for (int i = 0; i <= 100; i++)
    //    std::cout << array[i] << " ";
    // std::cout << "\n";

    try
    {
        std::vector<int>::iterator it;
        it = easyfind(array, 100);
        std::cout << "Found: " << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}