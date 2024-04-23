/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:23:37 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/23 16:48:29 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"



// Constructors
Cat::Cat(void)
{
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << COLOR_MAGENTA <<  "Cat Default constructor called " << COLOR_BACK << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
    std::cout << COLOR_GREEN << "Cat Copy construtor called" <<  COLOR_BACK << std::endl;
    *this = src;
    *this->brain = *src.brain;
}

//Operator
Cat& Cat::operator=(const Cat &src)
{
        if (this != &src) {
            // Perform deep copy of the Brain object
            delete brain; // Deallocate existing memory
            brain = new Brain(*src.brain); // Perform deep copy
        }
        return *this;
}

// Destructor
Cat::~Cat(void)
{
    std::cout << COLOR_RED << getType() << ": Cat Destructor callled " << COLOR_BACK  <<  std::endl;
    delete this->brain;
}

 void Cat::makeSound(void) const
{
    std::cout <<"MIAOUW MIAWOUWWW MIAWOUUUHHHHHHHHHHHH....!" << std::endl;
}


Brain &Cat::getBrain(void) const
{
    return (*this->brain);
}




