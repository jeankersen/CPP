/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:23:37 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/18 09:46:47 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

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
FragTrap::FragTrap(void): ClapTrap()
{
    std::cout << COLOR_GREEN <<  "FragTrap  Default constructor called" << COLOR_BACK << std::endl;
    setHits(100);
    setEnergy(100);
    setAttack(30);
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    
    std::cout << COLOR_GREEN <<  "FragTrap  Default constructor called with args" << COLOR_BACK << std::endl;
    setHits(100);
    setEnergy(100);
    setAttack(30);
}

FragTrap::FragTrap(const FragTrap &src)
{
    std::cout << COLOR_GREEN << "FragTrap Copy construtor called " <<  COLOR_BACK << std::endl;
    *this = src;
}

//Operator
FragTrap& FragTrap::operator=(const FragTrap &src)
{
    std::cout << "FragTrap Copy assignment called" <<  std::endl;
    if(this != &src)
    {
        this->setName(src.getName());
        this->setHits(src.getHits());
        this->setEnergy(src.getAttack());
        this->setAttack(src.getAttack());
    }
    return (*this);
}

// Destructor
FragTrap::~FragTrap(void)
{
    std::cout << COLOR_RED << getName() << ": FragTrap Destructor callled " << COLOR_BACK  <<  std::endl;
}

void FragTrap::highFives(void)
{
    std::cout <<  COLOR_LIME << getName() <<  ":  GIVE YOUR BEST HIGHFIVES :-)" << COLOR_BACK <<  std::endl;
}




