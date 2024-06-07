/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:03:52 by jvillefr          #+#    #+#             */
/*   Updated: 2024/06/07 10:12:58 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RobotomyRequestForm.hpp"

const std::string COLOR_ORANGE = "\033[38;5;208m";   // Orange
const std::string COLOR_BACK = "\033[0m";            // Black
const std::string COLOR_GREEN = "\033[38;5;70m";     // Green
const std::string COLOR_RED = "\033[38;5;196m";      // Red


RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45)
{
    std::cout << COLOR_GREEN <<  "Default  RobotomyRequestForm constructor called " << COLOR_BACK << std::endl;
    this->Target = "Default RobotomyRequestForm";
}

RobotomyRequestForm::RobotomyRequestForm(std::string Target): AForm("RobotomyRequestForm", 72, 45)
{
    std::cout << COLOR_GREEN <<  "Constructor RobotomyRequestForm witht args " << "." << COLOR_BACK <<  std::endl;
    this->Target = Target;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & src) 
{
    if(this != &src)
        this->Target = src.Target;
    return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & cpy): AForm("RobotomyRequestForm", 72, 45)
{
    std::cout << COLOR_GREEN << "RobotomyRequestForm with copy" <<  COLOR_BACK << std::endl;
    *this = cpy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << COLOR_RED << getName() << " :RobotomyRequestForm deleted!" << COLOR_BACK << std::endl;
}

void RobotomyRequestForm::action() const
{ 
    srand((long) this);
    if (rand() & 1) 
	{
        std::cout << "ROUUUUZZZZZZZZZZZZZZZZSSSSSSSSSSSS..." << std::endl
                  << this->Target << " has been robotomized successfully." << std::endl;
    }
    else 
	{
        std::cout << this->Target << " robotomy failed." << std::endl;
    }
}



AForm * RobotomyRequestForm::clone(std::string target)
{
    return (new RobotomyRequestForm(target));
}
