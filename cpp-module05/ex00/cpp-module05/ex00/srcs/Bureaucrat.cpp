/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:57:30 by jvillefr          #+#    #+#             */
/*   Updated: 2024/05/17 13:51:21 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
    if(grade < HIGHGRADE)
        throw Bureaucrat::GradeTooHighException();
    if(grade > LOWGRADE)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
}


Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src)
{
    if(this != & src)
    {
        if(src.getGrade() < HIGHGRADE)
            throw Bureaucrat::GradeTooHighException();
        if(src.getGrade() > LOWGRADE)
            throw Bureaucrat::GradeTooLowException();
        this->_name = src.getName();
        this->_grade = src.getGrade();
    }
    return (*this);
}

Bureaucrat::Bureaucrat(Bureaucrat const & cpy)
{
    *this = cpy;
}

Bureaucrat::~Bureaucrat()
{
    
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

std::string Bureaucrat::getName() const
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

    if(this->_grade + 1> LOWGRADE)
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