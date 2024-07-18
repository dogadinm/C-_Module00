#include "Span.hpp"

int main()
{
    Span sp = Span(15);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::vector<unsigned int> myVector;
    for (int i = 1000; i < 10000; i = i + 1000)
    {
        myVector.push_back(i);
    }
    for (std::vector<unsigned int>::iterator i = myVector.begin(); i != myVector.end(); i++)
    {
        std::cout << *i << std::endl;
    }
    std::vector<unsigned int>::iterator start = myVector.begin();
    std::vector<unsigned int>::iterator end = myVector.end();
    sp.addRange(start, end);

    std::cout << sp.GetSize() << std::endl;
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;

}