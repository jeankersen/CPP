/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:23:37 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/23 15:25:21 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"



// Constructors
Cat::Cat(void) 
{
    this->type = "Cat";
    std::cout << COLOR_GREEN <<  "Cat Default constructor called " << COLOR_BACK << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
    std::cout << COLOR_GREEN << "Cat Copy construtor called" <<  COLOR_BACK << std::endl;
    *this = src;
}

//Operator
Cat& Cat::operator=(const Cat &src)
{
    std::cout << "Cat assignment operator called" <<  std::endl;
    if(this != &src)
    {
       type = src.getType();
    }
    return (*this);
}

// Destructor
Cat::~Cat(void)
{
    std::cout << COLOR_RED << getType() << ": Cat Destructor callled " << COLOR_BACK  <<  std::endl;
}

 void Cat::makeSound(void) const
{
    std::cout <<"MIAOUW MIAWOUWWW MIAWOUUUHHHHHHHHHHHH....!" << std::endl;
}



