#pragma once

# include <iostream>
# include <vector>
# include <algorithm>

class Span
{
private:
    std::vector<unsigned int> _array;
    size_t _size;

public:

    Span();
    Span(unsigned int number);
    Span(Span const &copy);
    ~Span();

    Span &operator=(Span const &copy);

    unsigned int shortestSpan();
    unsigned int longestSpan();

    void addNumber(unsigned int number);
    void addRange(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end);

    size_t GetSize() const;


    class SpanFullException : public std::exception 
    {
        public: 
            virtual const char* what() const throw();
    };

    class SizeSmallException : public std::exception 
    {
        public: 
            virtual const char* what() const throw();
    };
};
