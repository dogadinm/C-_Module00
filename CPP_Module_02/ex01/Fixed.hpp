#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int _fixedVar;
    static const int _frac;

public:
    Fixed(void);
    Fixed(const int numb);
    
    ~Fixed();

    Fixed(Fixed const &copy);
    Fixed &operator=(Fixed const &copy);

    int getRawBits( void ) const;
    void setRawBits( int const raw );
};



#endif