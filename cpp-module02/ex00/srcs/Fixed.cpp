/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:23:37 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/10 15:32:54 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _nbr(0)
{
    std::cout << "Default constructor called " << std::endl;
}

Fixed::~Fixed(void)
{
    std::cout << "destructor callled " << std::endl;
}

//copy
Fixed::Fixed(Fixed const &src): _nbr(src.getRawBits())
{
    std::cout << "Copy construtor called" <<  std::endl;
}

//operator
Fixed& Fixed::operator=(const Fixed &src)
{
    std::cout << "Copy assignment called" <<  std::endl;
    if(this != &src)
       _nbr = src.getRawBits();

    return (*this);
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
