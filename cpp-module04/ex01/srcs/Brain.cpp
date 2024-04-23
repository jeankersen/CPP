/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:23:37 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/23 16:46:53 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Constructors

Brain::Brain(void)
{
    std::cout << COLOR_PURPLE <<  "Brain Default constructor called " << COLOR_BACK << std::endl;
}


Brain::Brain(const Brain &src)
{
    std::cout << COLOR_GREEN << "Brain Copy construtor called" <<  COLOR_BACK << std::endl;
    *this = src;
}

//Operator
Brain& Brain::operator=(const Brain &src)
{
    std::cout << "Brain assignment operator called" <<  std::endl;
    
    if(this != &src)
    {
       for(int i = 0; i < 100; i++)
        this->ideas[i] = src.ideas[i];
    }
    return (*this);
}

// Destructor
Brain::~Brain(void)
{
    std::cout << COLOR_RED << "Brain Destructor callled " << COLOR_BACK  <<  std::endl;
}
