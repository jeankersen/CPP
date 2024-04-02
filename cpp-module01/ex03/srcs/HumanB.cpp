#include "HumanB.hpp"

HumanB::HumanB(const std::string& name)
{
    this->_name = name;
    this->_weaponPtr = nullptr;
}

HumanB::~HumanB()
{
    delete this->_weaponPtr;
}


void HumanB::attack()
{
    if (this->_weaponPtr)
    {
        std::cout << this->_name << " attacks with their " << this->_weaponPtr->getType() << std::endl;
    } 
    else 
    {
        std::cout << this->_name << " attacks with bare hands" << std::endl;
    }
}

void HumanB::setWeapon(const Weapon& weapon)
{
    delete this->_weaponPtr; // Libérer la mémoire de l'ancien objet Weapon, s'il existe
    this->_weaponPtr = new Weapon(weapon); // Allouer un nouvel objet Weapon et le copier
}

void HumanB::disarm()
{
    delete this->_weaponPtr;
    this->_weaponPtr = nullptr;
}