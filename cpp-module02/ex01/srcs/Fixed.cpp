/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:23:37 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/10 17:35:05 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


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
Fixed::Fixed(void): _nbr(0)
{
    std::cout << COLOR_GREEN <<  "Default constructor called " << COLOR_BACK << std::endl;
}

Fixed::Fixed(const int val) : _nbr(val << _bits)
{
    std::cout << COLOR_GREEN  << "Int constructor called" <<  COLOR_BACK <<  std::endl;
}


Fixed::Fixed(const float val): _nbr(roundf(val * (1 << _bits)))
{
    std::cout << COLOR_GREEN << "Float constructor called" << COLOR_BACK << std::endl;
}

// Copy constructor
Fixed::Fixed(Fixed const &src): _nbr(src.getRawBits())
{
    std::cout << COLOR_GREEN << "Copy construtor called" <<  COLOR_BACK << std::endl;
}


//Operator
Fixed& Fixed::operator=(const Fixed &src)
{
    std::cout << "Copy assignment called" <<  std::endl;
    if(this != &src)
       _nbr = src.getRawBits();

    return (*this);
}

// Destructor
Fixed::~Fixed(void)
{
    std::cout << COLOR_RED << "Destructor callled " << COLOR_BACK  <<  std::endl;
}


int Fixed::getRawBits(void) const
{
    std::cout << "Get Rawbit called" <<  std::endl;
    return (this->_nbr);
}

void Fixed::setRawBits(int const raw)
{
    this->_nbr = raw;
}


int Fixed::toInt(void) const
{
    return (_nbr >> _bits);
}

float Fixed::toFloat(void) const
{
    return ((float)_nbr  / (1 << _bits));
}

std::ostream &operator<<(std::ostream &str, Fixed const &fixed_nbr)
{
    return (str << fixed_nbr.toFloat());
}