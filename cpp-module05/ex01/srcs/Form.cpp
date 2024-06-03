/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:37:34 by jvillefr          #+#    #+#             */
/*   Updated: 2024/06/03 14:36:01 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


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



Form::Form()
{
    std::cout << COLOR_GREEN <<  "Default  form constructor called " << COLOR_BACK << std::endl;
    this->_name = "Default Form";
    this->_isSigned = false;
    this->_gradeToSign = LOWGRADE;
    this->_gradeToExecute = LOWGRADE;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute): _name(name), _isSigned(false)
{
    if(gradeToSign < HIGHGRADE || gradeToExecute < HIGHGRADE)
        throw GradeTooHighException();
    else if(gradeToSign > LOWGRADE || gradeToExecute > LOWGRADE)
        throw GradeTooLowException();
    else
        {
            this->_gradeToSign = gradeToSign;
            this->_gradeToExecute = gradeToExecute;
            std::cout << COLOR_GREEN <<  getName()  << "Constructor Form witht args " << "." << COLOR_BACK <<  std::endl;
        }
        
}
Form & Form::operator=(Form const & src) 
{
    if( this != & src)
    {
        _name = src.getName();
        _isSigned = src._isSigned;
        _gradeToSign = src.getGradeToSign();
        _gradeToExecute = src.getGradeToExecute();
    }
    return (*this);
}

Form::Form(Form const & cpy)
{
    std::cout << COLOR_GREEN << "Form with copy" <<  COLOR_BACK << std::endl;
    *this = cpy;
}

Form::~Form()
{
    std::cout << COLOR_RED << getName() << " :form deleted!" << COLOR_BACK << std::endl;
}

std::string Form::getName() const
{
    return (this->_name);
}


std::string Form::getSign() const
{
    if(this->_isSigned)
        return ("True");
    else
        return ("False");
}

int Form::getGradeToSign() const
{
    return (this->_gradeToSign);
}

int Form::getGradeToExecute() const
{
    return (this->_gradeToExecute);
}

void Form::setSign()
{
    this->_isSigned = true;
}

void Form::beSigned(Bureaucrat const & bureaucrat)
{
    if(this->_isSigned == false)
    {
        if (bureaucrat.getGrade() <= this->getGradeToSign())
                this->_isSigned = true;
            //std::cout << bureaucrat.getName() << " signed " << getName() << std::endl;
        else
            //std::cout << bureaucrat.getName() << " couldn’t signed " << getName() << " because " << std::endl;
            throw GradeTooLowException();
    }   
}


const char * Form::GradeTooHighException::what() const throw()
{
    return "Grade is to high";
}

const char * Form::GradeTooLowException::what() const throw()
{
    return "Grade is to low";
}


std::ostream & operator<<(std::ostream & out, Form const & obj)
{
    out << "Form name: " << obj.getName() << std::endl;
    out << "Sidned: " << obj.getSign() << std::endl;
    out << "Grade to sign: " << obj.getGradeToSign() << std::endl;
    out << "Grade to execute: " << obj.getGradeToExecute() << std::endl;
    return out;
}