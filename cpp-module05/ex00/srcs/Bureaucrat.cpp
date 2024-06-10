/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:57:30 by jvillefr          #+#    #+#             */
/*   Updated: 2024/06/10 09:47:05 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const std::string COLOR_BACK = "\033[0m";            // Black
const std::string COLOR_GREEN = "\033[38;5;70m";     // Green
const std::string COLOR_RED = "\033[38;5;196m";      // Red


Bureaucrat::Bureaucrat(): _name("random"), _grade(LOWGRADE)
{
      std::cout << COLOR_GREEN <<  "Bureaucrat Default constructor called " << COLOR_BACK << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
    std::cout << COLOR_GREEN <<  "Bureaucrat Constructor called with args " << COLOR_BACK << std::endl;
    if(grade < HIGHGRADE)
        throw Bureaucrat::GradeTooHighException();
    if(grade > LOWGRADE)
        throw Bureaucrat::GradeTooLowException();
}


Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src)
{
    std::cout << COLOR_GREEN << "Bureaucrat Copy operator called"  << COLOR_BACK <<  std::endl;
    if(this != & src)
        this->_grade = src.getGrade();
    return (*this);
}

Bureaucrat::Bureaucrat(Bureaucrat const & cpy)
{
    std::cout << COLOR_GREEN << "Bureaucrat Copy assignment called" <<  COLOR_BACK << std::endl;
    *this = cpy;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << COLOR_RED << getName() << ": Bureaucrat Destructor callled " << COLOR_BACK  <<  std::endl;
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

const std::string &Bureaucrat::getName() const
{
    return (this->_name);
}

void Bureaucrat::addGrade()
{
    if(this->_grade  - 1 < HIGHGRADE)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}


void Bureaucrat::takeGrade()
{

    if(this->_grade + 1 > LOWGRADE)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & obj)
{
    o << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return o;
}


const char * Bureaucrat::GradeTooHighException::what() const throw()
{
    return "TooHighException";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return "TooLowExecption";
}
