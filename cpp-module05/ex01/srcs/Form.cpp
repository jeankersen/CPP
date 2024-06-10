/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:37:34 by jvillefr          #+#    #+#             */
/*   Updated: 2024/06/10 10:08:10 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const std::string COLOR_ORANGE = "\033[38;5;208m";   // Orange
const std::string COLOR_BACK = "\033[0m";            // Black
const std::string COLOR_GREEN = "\033[38;5;70m";     // Green
const std::string COLOR_RED = "\033[38;5;196m";      // Red



Form::Form():_name("Default Form"), _gradeToSign(LOWGRADE), _gradeToExecute(LOWGRADE)
{
    std::cout << COLOR_GREEN <<  "Form Default  form constructor called " << COLOR_BACK << std::endl;
    this->_isSigned = false;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute): _name(name), _isSigned(false),  _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if(gradeToSign < HIGHGRADE || gradeToExecute < HIGHGRADE)
        throw GradeTooHighException();
    else if(gradeToSign > LOWGRADE || gradeToExecute > LOWGRADE)
        throw GradeTooLowException();
    else
        std::cout << COLOR_GREEN <<  getName()  << "Form Constructor Form witht args " << "." << COLOR_BACK <<  std::endl;
}
Form & Form::operator=(Form const & src) 
{
    if( this != & src)
       this->_isSigned = src._isSigned;
    return (*this);
}

Form::Form(Form const & cpy): _name(cpy._name), _isSigned(cpy._isSigned),  _gradeToSign(cpy.getGradeToSign()), _gradeToExecute(cpy.getGradeToExecute())
{
    std::cout << COLOR_GREEN << "Form with copy" <<  COLOR_BACK << std::endl;
    *this = cpy;
}

Form::~Form()
{
    std::cout << COLOR_RED << getName() << " :Form deleted!" << COLOR_BACK << std::endl;
}

const std::string Form::getName() const
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
    if(this->_isSigned == true)
    {
        std::cout << getName() << " already signed!" << std::endl;
    }
    else
    {
        if (bureaucrat.getGrade() <= this->getGradeToSign())
        {
            this->_isSigned = true;
            std::cout << bureaucrat.getName() << " signed " << getName()  << "." << std::endl;
        }
        else
        {
            std::cout << bureaucrat.getName() << " couldn’t signed " << getName() << " because " << GradeTooLowException().what() << "." << std::endl;
            throw GradeTooLowException(); 
        }
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