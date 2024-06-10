/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:53:29 by jvillefr          #+#    #+#             */
/*   Updated: 2024/06/10 13:12:01 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

const std::string COLOR_ORANGE = "\033[38;5;208m";   // Orange
const std::string COLOR_BACK = "\033[0m";            // Black
const std::string COLOR_GREEN = "\033[38;5;70m";     // Green
const std::string COLOR_RED = "\033[38;5;196m";      // Red


PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm ", 25, 5, "Default Presidential target")
{
    std::cout << COLOR_GREEN <<  "Default PresidentialPardonForm constructor called" << COLOR_BACK << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5, target)
{
    std::cout << COLOR_GREEN <<  getTarget() << ": Constructor PresidentialPardonForm witht args" << COLOR_BACK <<  std::endl;

}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & src)
{
    if (this != &src)
		this->setTarget(src.getTarget());
    return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & cpy): AForm("PresidentialPardonForm", 25, 5, cpy.getTarget())
{
    std::cout << COLOR_GREEN << getTarget() <<  ": PresidentialPardonForm with copy" <<  COLOR_BACK << std::endl;
    *this = cpy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << COLOR_RED << getTarget() << ": PresidentialPardonForm deleted!" << COLOR_BACK << std::endl;
}

void PresidentialPardonForm::action() const 
{
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

