/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:23:37 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/23 16:49:02 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"


// Constructors
Dog::Dog(void)
{
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << COLOR_ORANGE <<  "Dog Default constructor called " << COLOR_BACK << std::endl;
}


Dog::Dog(const Dog &src) : Animal(src)
{
    std::cout << COLOR_GREEN << "Dog Copy construtor called" <<  COLOR_BACK << std::endl;
    if (src.brain) {
        brain = new Brain(*src.brain);
    } else {
        brain = nullptr;
    }
}

//Operator
Dog& Dog::operator=(const Dog &src) 
{
   std::cout << "Animal assignment operator called" <<  std::endl;
        if (this != &src) {
            // Perform deep copy of the Brain object
            delete brain; // Deallocate existing memory
            brain = new Brain(*src.brain); // Perform deep copy
        }
        return *this;
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

Brain &Dog::getBrain(void) const
{
    return (*this->brain);
}