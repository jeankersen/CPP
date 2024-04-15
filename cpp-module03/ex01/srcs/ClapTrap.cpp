/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:23:37 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/15 17:11:01 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

const std::string COLOR_YELLOW = "\033[38;5;226m";   // Yellow
const std::string COLOR_MAGENTA = "\033[38;5;201m";  // Magenta
const std::string COLOR_CYAN = "\033[38;5;51m";      // Cyan
const std::string COLOR_WHITE = "\033[38;5;15m";     // White
const std::string COLOR_ORANGE = "\033[38;5;208m";   // Orange
const std::string COLOR_PURPLE = "\033[38;5;93m";    // Purple
const std::string COLOR_PINK = "\033[38;5;198m";     // Pink
const std::string COLOR_SKYBLUE = "\033[38;5;75m";   // Sky Blue
const std::string COLOR_LIME = "\033[38;5;154m";     // Lime
const std::string COLOR_GRAY = "\033[38;5;242m";     // Gray
const std::string COLOR_BACK = "\033[0m";            // Black
const std::string COLOR_GREEN = "\033[38;5;70m";     // Green
const std::string COLOR_RED = "\033[38;5;196m";      // Red


// Constructors
ClapTrap::ClapTrap(void): _hits(10), _energy(10), _attack(0)
{
    std::cout << COLOR_GREEN <<  "Default constructor called " << COLOR_BACK << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hits(10), _energy(10), _attack(0)
{
    std::cout << COLOR_GREEN <<  "Default constructor called with args " << COLOR_BACK << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
    std::cout << COLOR_GREEN << "Copy construtor called" <<  COLOR_BACK << std::endl;
    *this = src;
}

//Operator
ClapTrap& ClapTrap::operator=(const ClapTrap &src)
{
    std::cout << "Copy assignment called" <<  std::endl;
    if(this != &src)
    {
       _name= src.getName();
       _hits = src.getHits();
       _energy = src.getEnergy();
       _attack = src.getAttack();
    }
    return (*this);
}

// Destructor
ClapTrap::~ClapTrap(void)
{
    std::cout << COLOR_RED << "Destructor callled " << COLOR_BACK  <<  std::endl;
}

std::string ClapTrap::getName(void) const
{
    return (this->_name);
}

int ClapTrap::getHits(void) const
{
    return (this->_hits);
}

int ClapTrap::getEnergy(void) const
{
    return (this->_energy);
}

int ClapTrap::getAttack(void) const
{
    return (this->_attack);
}

void ClapTrap::setName(std::string name)
{
    this->_name = name;   
}
void ClapTrap::setHits(int const hits)
{
    this->_hits = hits;
}

void ClapTrap::setEnergy(int const energy)
{
    this->_energy = energy;
}

void ClapTrap::setAttack(int const attack)
{
    this->_attack = attack;
}

void ClapTrap::attack(const std::string& target)
{
    if(getEnergy() > 0 && getHits() > 0)
    {
        std::cout << "ClapTrap " << getName() << " attacks " << target <<  ", causing " << getAttack() << " hit points" << std::endl;
        setEnergy(getEnergy() - 1);
        return;
    }
    if(getHits() <= 0)
    {
        std::cout << "No hits points left!" << std::endl;
        return;
    }
    if(getEnergy() <= 0)
        std::cout << "No energy left to attacks" << std::endl;
    
}

void ClapTrap::beRepaired(unsigned int amount) {
    if(getEnergy() > 0 && getHits() > 0)
    {
        setHits(getHits() + amount);
        setEnergy(getEnergy() - 1);
    }
    if(getHits() <= 0)
    {
        std::cout << "No hits hits left!" << std::endl;
        return;
    }
    if(getEnergy() <= 0)
        std::cout << "No energy left to repair" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    setHits(getHits() - amount);
}