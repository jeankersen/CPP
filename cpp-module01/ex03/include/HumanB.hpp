#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    private:
    std::string _name;
    Weapon* _weapon; // pointeur vers une arme pouvant etre nul// gestion memoire // reassignation

    public:
    HumanB(std::string name);
    ~HumanB(void);
    void setWeapon( Weapon &weapon);
    void attack(void);
};

#endif