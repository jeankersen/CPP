#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->_name = name;
    this->_weapon = nullptr;
    std::cout  << COLOR_GREEN << "Human A: " << this->_name  <<  " created" << COLOR_BACK << std::endl;

}

HumanB::~HumanB()
{
    delete _weapon;
    std::cout  << COLOR_RED  << "Human B: " << this->_name << " destroy " << std::endl;
}

void HumanB::attack()
{
    std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;

}

void HumanB::setWeapon(Weapon& weapon) {
    delete _weapon; // Libérer la mémoire de l'ancienne arme, s'il y en a une
    _weapon = new Weapon(weapon); // Allouer une nouvelle arme et copier le contenu de weapon
}

