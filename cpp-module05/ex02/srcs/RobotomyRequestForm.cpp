/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:03:52 by jvillefr          #+#    #+#             */
/*   Updated: 2024/06/04 14:13:55 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RobotomyRequestForm.hpp"

const std::string COLOR_YELLOW = "\033[38;5;226m";   // Yellow
const std::string COLOR_MAGENTA = "\033[38;5;201m";  // Magenta
const std::string COLOR_CYAN = "\033[38;5;51m";      // Cyan
const std::string COLOR_WHITE = "\033[38;5;15m";     // White
const std::string COLOR_ORANGE = "\033[38;5;208m";   // Orange
const std::string COLOR_PURPLE = "\033[38;5;93m";    // Purple
const std::string COLOR_PINK = "\033[38;5;198m";     // Pink
const std::string COLOR_SKYBLUE = "\033[38;5;75m";   // Sky Blue
const std::string COLOR_LIME = "\033[38;5;154m";     // Lime
const std::string COLOR_GRAY = "\033[38;5;242m";     // Gray
const std::string COLOR_BACK = "\033[0m";            // Black
const std::string COLOR_GREEN = "\033[38;5;70m";     // Green
const std::string COLOR_RED = "\033[38;5;196m";      // Red


RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45)
{
    std::cout << COLOR_GREEN <<  "Default  RobotomyRequestForm constructor called " << COLOR_BACK << std::endl;
    this->Target = "Default AFrom";
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