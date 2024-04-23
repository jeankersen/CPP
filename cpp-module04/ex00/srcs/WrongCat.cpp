/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:23:37 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/23 15:25:37 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"



// Constructors
WrongCat::WrongCat(void) 
{
    this->type = "WrongCat";
    std::cout << COLOR_GREEN <<  "WrongCat Default constructor called " << COLOR_BACK << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
    std::cout << COLOR_GREEN << "WrongCat Copy construtor called" <<  COLOR_BACK << std::endl;
    *this = src;
}

//Operator
WrongCat& WrongCat::operator=(const WrongCat &src)
{
    std::cout << "WrongCat assignment operator called" <<  std::endl;
    if(this != &src)
    {
       type = src.getType();
    }
    return (*this);
}

// Destructor
WrongCat::~WrongCat(void)
{
    std::cout << COLOR_RED << getType() << ": WrongCat Destructor callled " << COLOR_BACK  <<  std::endl;
}

 void WrongCat::makeSound(void) const
{
    std::cout <<"WRONNNNG MIAWOUUUHHHHHHHHHHHH....!" << std::endl;
}


