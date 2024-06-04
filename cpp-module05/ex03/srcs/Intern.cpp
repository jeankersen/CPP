/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:24:57 by jvillefr          #+#    #+#             */
/*   Updated: 2024/06/04 17:08:02 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


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


Intern::Intern()
{
      std::cout << COLOR_GREEN <<  " Inter Default constructor called " << COLOR_BACK << std::endl;
    this->forms[0] = new ShrubberyCreationForm();
    this->forms[1] = new RobotomyRequestForm();
    this->forms[2] = new PresidentialPardonForm();
}


Intern & Intern::operator=(Intern const & src)
{
    std::cout << COLOR_GREEN << " Intern Copy operator called"  << COLOR_BACK  <<  std::endl;
    (void) src;
    return *this;
}

Intern::Intern(Intern const & cpy)
{
    std::cout << COLOR_GREEN << " Intern Copy assignment called" <<  COLOR_BACK << std::endl;
    (void) cpy;

    this->forms[0] = new ShrubberyCreationForm();
    this->forms[1] = new RobotomyRequestForm();
    this->forms[2] = new PresidentialPardonForm();
}

const char * Intern::FormNotFound::what() const throw() 
{
    return "From Not Found";
}

Intern::~Intern()
{
    std::cout << COLOR_RED << "Intern Destructor callled " << COLOR_BACK  <<  std::endl;
    delete forms[0];
    delete forms[1];
    delete forms[2];
}



AForm * Intern::makeForm(std::string formName, std::string target)
{
    std::string froms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    
	int i = 0;
    for (; i < 3 && formName != froms[i]; i++);
    return i < 3 ? forms[i]->clone(target) : throw Intern::FormNotFound();
}