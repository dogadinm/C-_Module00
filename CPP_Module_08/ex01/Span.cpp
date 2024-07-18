#include "Span.hpp"

Span::Span()
{}

Span::Span(unsigned int number): _size(number)
{}

Span::Span(Span const &copy): _array(copy._array) ,_size(copy._size)
{
    *this = copy;
}

Span &Span::operator=(Span const &copy)
{
    if(this == &copy)
        return *this;
    this->_array = copy._array;
    this->_size = copy._size;
    return *this;
}

Span::~Span()
{
}

void Span::addRange(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end)
{
    size_t dist = static_cast<size_t>(std::distance(begin, end));
    if (dist > _size - _array.size()) {
            throw SpanFullException();
        }
    _array.insert(_array.end(), begin, end);
}

void Span::addNumber(unsigned int number)
{
    if(_array.size() >= this->_size)
        throw SpanFullException();
    _array.push_back(number);
}

unsigned int Span::shortestSpan()
{
    if (this->_size < 2 || this->_array.size() < 2) 
        throw SizeSmallException();
    
    std::sort(_array.begin(), _array.end());

    unsigned int min_span = _array[1] - _array[0];

    for (size_t i = 0; i < _array.size(); i++)
    {
        unsigned int diff_span = _array[i + 1] - _array[i];
        if (min_span > diff_span)
            min_span = diff_span;
    }

    return min_span;
}



unsigned int Span::longestSpan()
{
    if (this->_size < 2 || this->_array.size() < 2) 
        throw SizeSmallException();
    std::vector<unsigned int>::iterator num_max = std::max_element(_array.begin(),_array.end());
    std::vector<unsigned int>::iterator num_min = std::min_element(_array.begin(),_array.end());
    return (*num_max - *num_min);
}


size_t Span::GetSize() const
{
    return this->_size;
}

const char* Span::SpanFullException::what() const throw()
{
    return("Span is full");
}

const char* Span::SizeSmallException::what() const throw()
{
    return("Size of span is less or equal to 1, no span to find");
}