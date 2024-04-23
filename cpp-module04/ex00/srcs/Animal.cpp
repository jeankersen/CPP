/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:23:37 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/23 15:25:16 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructors

Animal::Animal(void) : type("Animal")
{
    std::cout << COLOR_GREEN <<  "Animal Default constructor called " << COLOR_BACK << std::endl;
}


Animal::Animal(const Animal &src)
{
    std::cout << COLOR_GREEN << "Animal Copy construtor called" <<  COLOR_BACK << std::endl;
    *this = src;
}

//Operator
Animal& Animal::operator=(const Animal &src)
{
    std::cout << "Animal assignment operator called" <<  std::endl;
    if(this != &src)
    {
       type = src.type;
    }
    return (*this);
}

// Destructor
Animal::~Animal(void)
{
    std::cout << COLOR_RED << getType() << ": Animal Destructor callled " << COLOR_BACK  <<  std::endl;
}

std::string Animal::getType(void) const
{
    return (this->type);
}

void Animal::makeSound(void) const
{
    std::cout << "NOIIIIISE....HHH" << std::endl;
}
