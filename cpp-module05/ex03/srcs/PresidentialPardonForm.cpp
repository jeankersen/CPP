/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:53:29 by jvillefr          #+#    #+#             */
/*   Updated: 2024/06/07 10:13:10 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

const std::string COLOR_ORANGE = "\033[38;5;208m";   // Orange
const std::string COLOR_BACK = "\033[0m";            // Black
const std::string COLOR_GREEN = "\033[38;5;70m";     // Green
const std::string COLOR_RED = "\033[38;5;196m";      // Red


PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5)
{
    std::cout << COLOR_GREEN <<  "Default  PresidentialPardonForm constructor called " << COLOR_BACK << std::endl;
    this->Target = "Default PresidentialPardonForm";
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


AForm * PresidentialPardonForm::clone(std::string target)
{
    return (new PresidentialPardonForm(target));
}

