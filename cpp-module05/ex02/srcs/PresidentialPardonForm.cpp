/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:53:29 by jvillefr          #+#    #+#             */
/*   Updated: 2024/06/04 14:13:01 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

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


PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5)
{
    std::cout << COLOR_GREEN <<  "Default  PresidentialPardonForm constructor called " << COLOR_BACK << std::endl;
    this->Target = "Default AFrom";
}

PresidentialPardonForm::PresidentialPardonForm(std::string Target): AForm("PresidentialPardonForm", 25, 5)
{
    std::cout << COLOR_GREEN <<  "Constructor PresidentialPardonForm witht args " << COLOR_BACK <<  std::endl;
    this->Target = Target;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & src)
{
    if(this != &src)
        this->Target = src.Target;
    return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & cpy): AForm("PresidentialPardonForm", 25, 5)
{
    std::cout << COLOR_GREEN << "PresidentialPardonForm with copy" <<  COLOR_BACK << std::endl;
    *this = cpy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << COLOR_RED << getName() << " :PresidentialPardonForm deleted!" << COLOR_BACK << std::endl;
}

void PresidentialPardonForm::action() const 
{
    std::cout << this->Target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}