#include "Fixed.hpp"

const int	Fixed::_frac = 8;

Fixed::Fixed(void) : _fixedVar(0)
{

}

Fixed::~Fixed()
{

}

Fixed::Fixed(Fixed const &copy)
{
    *this = copy;
}

Fixed &Fixed::operator=(Fixed const &copy)
{
    this->_fixedVar = copy.getRawBits();
    return (*this);
}

int Fixed::getRawBits( void ) const
{
    return(this->_fixedVar);
}

void Fixed::setRawBits( int const raw )
{
    this->_fixedVar = raw;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

Fixed::Fixed(const int integer)
{
	this->_fixedVar = (integer << Fixed::_frac);
}

Fixed::Fixed(const float floating_point)
{
	this->_fixedVar = roundf(floating_point * (1 << Fixed::_frac));
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_fixedVar / (float)(1 << Fixed::_frac));
}

int		Fixed::toInt(void) const
{
	return (this->_fixedVar >> Fixed::_frac);
}

std::ostream	&operator<<(std::ostream &str, Fixed const &object)
{
	str << object.toFloat();
	return (str);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

bool Fixed::operator>(Fixed const &copy) const
{
    if (this->_fixedVar > copy.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator<(Fixed const &copy) const
{
    if (this->_fixedVar < copy.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator>=(Fixed const &copy) const
{
    if (this->_fixedVar >= copy.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator<=(Fixed const &copy) const
{
    if (this->_fixedVar <= copy.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator==(Fixed const &copy) const
{
    if (this->_fixedVar > copy.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator!=(Fixed const &copy) const
{
    if (this->_fixedVar != copy.getRawBits())
        return (true);
    return (false);
}


Fixed Fixed::operator+(Fixed const &copy)
{
    this->_fixedVar += copy.getRawBits();
    return(*this);
}

Fixed Fixed::operator-(Fixed const &copy)
{
    this->_fixedVar -= copy.getRawBits();
    return(*this);
}

Fixed Fixed::operator/(Fixed const &copy)
{
    this->_fixedVar = (this->toFloat() / copy.toFloat() ) * (1 << _frac);
    return(*this);
}

Fixed Fixed::operator*(Fixed const &copy)
{
    this->_fixedVar = (this->toFloat() * copy.toFloat() ) * (1 << _frac);
    return(*this);
}

Fixed Fixed::operator++()
{
    this->_fixedVar++;
    return(*this);
}

Fixed Fixed::operator--()
{
    this->_fixedVar--;
    return(*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	temp(*this);
	++(*this);
	return (temp);
}

Fixed Fixed::operator--(int)
{
	Fixed	temp(*this);
	--(*this);
	return (temp);
}

Fixed const	&Fixed::min(Fixed const &first, Fixed const &second)
{
	if (first.getRawBits() > second.getRawBits())
		return (second);
	return (first);
}

Fixed const	&Fixed::max(Fixed const &first, Fixed const &second)
{
	if (first.getRawBits() < second.getRawBits())
		return (second);
	return (first);
}

Fixed	&Fixed::min(Fixed &first, Fixed &second)
{
	if (first.getRawBits() > second.getRawBits())
		return (second);
	return (first);
}

Fixed	&Fixed::max(Fixed &first, Fixed &second)
{
	if (first.getRawBits() < second.getRawBits())
		return (second);
	return (first);
}