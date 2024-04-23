/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:23:37 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/23 15:25:32 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Constructors

WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
    std::cout << COLOR_GREEN <<  "WrongAnimal Default constructor called " << COLOR_BACK << std::endl;
}


WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
    std::cout << COLOR_GREEN << "WrongAnimal Copy construtor called" <<  COLOR_BACK << std::endl;
    *this = src;
}

//Operator
WrongAnimal& WrongAnimal::operator=(const WrongAnimal &src)
{
    std::cout << "WrongAnimal assignment operator called" <<  std::endl;
    if(this != &src)
    {
       type = src.type;
    }
    return (*this);
}

// Destructor
WrongAnimal::~WrongAnimal(void)
{
    std::cout << COLOR_RED << getType() << ": WrongAnimal Destructor callled " << COLOR_BACK  <<  std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (this->type);
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "WWWWRONNGGG HHHHHHHHHHHHHHHHH" << std::endl;
}