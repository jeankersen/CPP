#ifndef SERIAL_HPP
# define SERIAL_HPP

#include <iostream>
#include <cstdint>

struct Data
{
    int value;
    std::string name;
};

uintptr_t serialize(Data* ptr); // convert pointer to numeric value
Data* deserialize(uintptr_t raw);

#endif