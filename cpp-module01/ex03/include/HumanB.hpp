#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    private:
    std::string _name;
    Weapon* _weaponPtr; // pointeur vers une arme pouvant etre nul

    public:
    HumanB(const std::string& name);
    ~HumanB();
    void disarm();
    void setWeapon(const Weapon& weapon);
    void attack();
};

#endif