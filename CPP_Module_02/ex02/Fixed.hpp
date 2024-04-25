#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
# include <cmath>
#include <bitset> 
#include <string> 
#include <cstring>
#include <stdint.h>

class Fixed
{
private:
    int _fixedVar;
    static const int _frac;

public:
    Fixed(void);
    Fixed(const int numb);
    Fixed(float numb);
    
    ~Fixed();

    Fixed(Fixed const &copy);
    Fixed &operator=(Fixed const &copy);


    bool	operator>(Fixed const &copy) const;
    bool	operator<(Fixed const &copy) const;
    bool	operator>=(Fixed const &copy) const;
    bool	operator<=(Fixed const &fcopy) const;
    bool	operator==(Fixed const &copy) const;
    bool	operator!=(Fixed const &fcopy) const;

    Fixed operator+(Fixed const &copy);
    Fixed operator-(Fixed const &copy);
    Fixed operator/(Fixed const &copy);
    Fixed operator*(Fixed const &copy);

    Fixed operator++();
    Fixed operator--();
    Fixed operator++(int);
    Fixed operator--(int);

    static Fixed const &min(Fixed const &first, Fixed const &second);
    static Fixed const &max(Fixed const &first, Fixed const &second);
    static Fixed &min(Fixed &first, Fixed &second);
    static Fixed &max(Fixed &first, Fixed &second);

    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float	toFloat(void) const;
    int		toInt(void) const;

};

std::ostream	&operator<<(std::ostream &str, Fixed const &object);

#endif