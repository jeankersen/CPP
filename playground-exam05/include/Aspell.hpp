
#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include "Color.hpp"



class Aspell
{
    protected:
        std::string name;
        std::string effects;

    public:
        Aspell(std::string str1, std::string str2);



        std::string getName(void) const;
        std::string  getEffects(void) const;
        Aspell & clone(void) const;

};

#endif