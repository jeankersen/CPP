#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    private:
    std::string _name;
    Weapon &_weapon; // objet non null, synthaxe simple, code clair

    public:
    HumanA(std::string name, Weapon& weapon);
    ~HumanA(void);
    void attack();
    void setWeapon(Weapon weapon);
};

#endif