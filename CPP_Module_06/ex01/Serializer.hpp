#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include <string>

struct Data 
{
	int n;
};


class Serializer
{
private:
    Serializer(void);
    Serializer(const Serializer &copy);
    ~Serializer();

public:

    Serializer &operator=(const Serializer &copy);

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif