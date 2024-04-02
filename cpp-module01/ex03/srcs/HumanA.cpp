#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {
    // _name et _weapon sont initialisés dans la liste d'initialisation
    std::cout << COLOR_GREEN  <<  "Human A: " << this->_name << " created with " << this->_weapon.getType() << COLOR_BACK << std::endl;
}

HumanA::~HumanA()
{
    std::cout << COLOR_RED << "Human A: " << this->_name << " destroy " << std::endl;
}

void HumanA::attack()
{
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}

void HumanA::setWeapon(Weapon weapon)
{
    this->_weapon = weapon;
}