/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:03:52 by jvillefr          #+#    #+#             */
/*   Updated: 2024/06/10 12:30:24 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RobotomyRequestForm.hpp"


const std::string COLOR_ORANGE = "\033[38;5;208m";   // Orange
const std::string COLOR_BACK = "\033[0m";            // Black
const std::string COLOR_GREEN = "\033[38;5;70m";     // Green
const std::string COLOR_RED = "\033[38;5;196m";      // Red


RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45, "Default RobotomyRequest target")
{
    std::cout << COLOR_GREEN <<  "Default RobotomyRequestForm constructor called" << COLOR_BACK << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45, target)
{
    std::cout << COLOR_GREEN <<  getTarget()  <<  ": Constructor RobotomyRequestForm witht args " << COLOR_BACK <<  std::endl;

}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & src) 
{
    if (this != &src)
		this->setTarget(src.getTarget());
    return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & cpy): AForm("RobotomyRequestForm", 72, 45, cpy.getTarget())
{
    std::cout << COLOR_GREEN <<  getTarget()  << ": RobotomyRequestForm with copy" <<  COLOR_BACK << std::endl;
    *this = cpy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << COLOR_RED << getTarget() << ": RobotomyRequestForm deleted!" << COLOR_BACK << std::endl;
}

void RobotomyRequestForm::action() const
{ 
    srand((long) this);
    if (rand() & 1) 
	{
        std::cout << "ROUUUUZZZZZZZZZZZZZZZZSSSSSSSSSSSS..." << std::endl
                  << getTarget() << " has been robotomized successfully." << std::endl;
    }
    else 
	{
        std::cout << getTarget() << " robotomy failed!" << std::endl;
    }
}