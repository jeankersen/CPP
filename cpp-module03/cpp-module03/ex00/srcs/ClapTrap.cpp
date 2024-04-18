/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:23:37 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/18 12:15:48 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

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

ClapTrap::ClapTrap(const ClapTrap &src)
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
       _name= src._name;
       _hits = src._hits;
       _energy = src._energy;
       _attack = src._attack;
    }
    return (*this);
}

// Destructor
ClapTrap::~ClapTrap(void)
{
    std::cout << COLOR_RED << getName() << ": Destructor callled " << COLOR_BACK  <<  std::endl;
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
        std::cout <<  "Sorry " << getName() << ", no hits points left to attacks!" << std::endl;
    }
    if(getEnergy() <= 0)
        std::cout <<  "Sorry " << getName() << ", no energy left to attacks!" << std::endl;
    
}

void ClapTrap::beRepaired(unsigned int amount) {
    
    if(amount < 0)
        return;
    if(getEnergy() > 0 && getHits() > 0)
    {
        
        setHits(getHits() + amount);
        std::cout << getName() << " repairing... total is:  " << getHits() << " hits points." << std::endl;
        setEnergy(getEnergy() - 1);
       
        return;
    }
    if(getHits() <= 0)
    {
        std::cout << "Sorry " << getName() << ", no hits points left to repair!" << std::endl;
    }
    if(getEnergy() <= 0)
        std::cout << "Sorry " << getName() << ", No energy energy to repair!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if(amount < 0)
        return;
    setHits(getHits() - amount);
    if(getHits() < 0)
        setHits(0);
    std::cout << getName() << " taking damage, hits points left: " << getHits() << std::endl;
}

void ClapTrap::displayInfo(void)
{
    std::cout <<  "Name :" << COLOR_ORANGE <<  getName() << COLOR_BACK  << "  Hits :" << COLOR_SKYBLUE <<  
    getHits() << COLOR_BACK <<  " Energy: " <<  COLOR_SKYBLUE <<  getEnergy() << COLOR_BACK  <<
      " Attacks :" <<  COLOR_SKYBLUE <<  getAttack() << COLOR_BACK  << std::endl;
}

std::ostream &operator<<(std::ostream &stream, ClapTrap &clapTrap)
{
    stream <<  "Name :" << COLOR_ORANGE <<  clapTrap.getName() << COLOR_BACK  << "  Hits :" << COLOR_SKYBLUE <<  
    clapTrap.getHits() << COLOR_BACK <<  " Energy: " <<  COLOR_SKYBLUE <<  clapTrap.getEnergy() << COLOR_BACK  <<
      " Attacks :" <<  COLOR_SKYBLUE <<  clapTrap.getAttack() << COLOR_BACK ;
    return (stream);
}