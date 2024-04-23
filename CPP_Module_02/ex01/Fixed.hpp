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

    
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float	toFloat(void) const;
    int		toInt(void) const;

};

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr);

#endif