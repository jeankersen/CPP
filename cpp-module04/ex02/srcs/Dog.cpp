/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:23:37 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/23 14:23:32 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"


// Constructors
Dog::Dog(void)
{
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << COLOR_GREEN <<  "Dog Default constructor called " << COLOR_BACK << std::endl;
}


Dog::Dog(const Dog &src) : Animal(src)
{
    std::cout << COLOR_GREEN << "Dog Copy construtor called" <<  COLOR_BACK << std::endl;
    *this = src;
}

//Operator
Dog& Dog::operator=(const Dog &src) 
{
    std::cout << "Dog assignment called" <<  std::endl;
    if(this != &src)
    {
       type = src.getType();
    }
    return (*this);
}

// Destructor
Dog::~Dog(void)
{
    std::cout << COLOR_RED << getType() << ": Dog Destructor callled " << COLOR_BACK  <<  std::endl;
    delete this->brain;
}

void Dog::makeSound(void) const
{
    std::cout << "WOPPP WOUAFFFFF WOUAFFF" << std::endl;
}

std::ostream &operator<<(std::ostream &stream, Dog &dog)
{
    stream <<  "Name :" << COLOR_ORANGE <<  dog.getType() << COLOR_BACK ;
    return (stream);
}
