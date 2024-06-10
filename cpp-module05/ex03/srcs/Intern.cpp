/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:24:57 by jvillefr          #+#    #+#             */
/*   Updated: 2024/06/10 13:52:16 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


const std::string COLOR_ORANGE = "\033[38;5;208m";   // Orange
const std::string COLOR_BACK = "\033[0m";            // Black
const std::string COLOR_GREEN = "\033[38;5;70m";     // Green
const std::string COLOR_RED = "\033[38;5;196m";      // Red


Intern::Intern()
{
    std::cout << COLOR_GREEN <<  "Inter Default constructor called " << COLOR_BACK << std::endl;
}


Intern & Intern::operator=(Intern const & src)
{
    std::cout << COLOR_GREEN << "Intern Copy operator called"  << COLOR_BACK  <<  std::endl;
    (void) src;
    return *this;
}

Intern::Intern(Intern const & cpy)
{
    std::cout << COLOR_GREEN << "Intern Copy assignment called" <<  COLOR_BACK << std::endl;
    *this = cpy;

}

const char * Intern::FormNotFound::what() const throw() 
{
    return "Form Not Found";
}

Intern::~Intern()
{
    std::cout << COLOR_RED << "Intern Destructor callled " << COLOR_BACK  <<  std::endl;

}



AForm * Intern::makeForm(std::string formName, std::string target)
{
    std::string form[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    AForm* newForm = nullptr;

    int i;
    for (i = 0; i < 3; ++i) {
        if (form[i] == formName) {
            break;
        }
    }

    switch(i) 
    {
        case 0:
            newForm = new ShrubberyCreationForm(target);
            std::cout << "Intern creates " << form[i] << std::endl;
            break;
        case 1:
            newForm = new RobotomyRequestForm(target);
            std::cout << "Intern creates " << form[i] << std::endl;
            break;
        case 2:
            newForm = new PresidentialPardonForm(target);
            std::cout << "Intern creates " << form[i] << std::endl;
            break;
        default:
			 std::cout << "Intern can't creates: " << target << std::endl;
            throw Intern::FormNotFound();
    }

    return newForm;
}