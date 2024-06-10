/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:37:34 by jvillefr          #+#    #+#             */
/*   Updated: 2024/06/04 09:15:44 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"


const std::string COLOR_ORANGE = "\033[38;5;208m";   // Orange
const std::string COLOR_BACK = "\033[0m";            // Black
const std::string COLOR_GREEN = "\033[38;5;70m";     // Green
const std::string COLOR_RED = "\033[38;5;196m";      // Red



AForm::AForm(): _name("Default AFormName"),  _target("Default target") , _gradeToSign(LOWGRADE), _gradeToExecute(LOWGRADE)
{
    std::cout << COLOR_GREEN <<  "AForm Default constructor called" << COLOR_BACK << std::endl;
    this->_isSigned = false;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute, std::string target): _name(name), _target(target), _isSigned(false),  _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if(gradeToSign < HIGHGRADE || gradeToExecute < HIGHGRADE)
        throw GradeTooHighException();
    else if(gradeToSign > LOWGRADE || gradeToExecute > LOWGRADE)
        throw GradeTooLowException();
    else
        std::cout << COLOR_GREEN <<  getTarget()  << ": AForm Constructor witht args" << COLOR_BACK <<  std::endl;

        
}   
AForm & AForm::operator=(AForm const & src)
{
    if( this != & src)
    {
        this->_target = src._target;
        this->_isSigned = src._isSigned;
    }
    return (*this);
}

AForm::AForm(AForm const & cpy): _name(cpy._name), _target(cpy.getTarget()) ,_isSigned(cpy._isSigned),  _gradeToSign(cpy.getGradeToSign()), _gradeToExecute(cpy.getGradeToExecute())
{
    std::cout << COLOR_GREEN << "AForm with copy" <<  COLOR_BACK << std::endl;
    *this = cpy;
}

AForm::~AForm()
{
    std::cout << COLOR_RED << getName() << ": AForm deleted!" << COLOR_BACK << std::endl;
}

const std::string AForm::getName() const
{
    return (this->_name);
}

std::string AForm::getTarget() const
{
    return (this->_target);
}

std::string AForm::getSign() const
{
    if(this->_isSigned)
        return ("True");
    else
        return ("False");
}

int AForm::getGradeToSign() const
{
    return (this->_gradeToSign);
}

int AForm::getGradeToExecute() const
{
    return (this->_gradeToExecute);
}

void AForm::setSign()
{
    this->_isSigned = true;
}

void AForm::setTarget(std::string target)
{
    this->_target = target;
}

void AForm::beSigned(Bureaucrat const & bureaucrat)
{
    if(this->_isSigned == true)
    {
        std::cout << getName() << ": already signed!" << std::endl;
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


const char * AForm::GradeTooHighException::what() const throw()
{
    return "Grade is to high";
}

const char * AForm::GradeTooLowException::what() const throw()
{
    return "Grade is to low";
}


std::ostream & operator<<(std::ostream & out, AForm const & obj)
{
    out << "AForm name: " << obj.getName() << std::endl;
     out << "AForm target: " << obj.getTarget() << std::endl;
    out << "Sidned: " << obj.getSign() << std::endl;
    out << "Grade to sign: " << obj.getGradeToSign() << std::endl;
    out << "Grade to execute: " << obj.getGradeToExecute() << std::endl;
    return out;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if(this->getSign() == "True")
    {
        if(executor.getGrade() <= getGradeToExecute())
            action();
        else
            throw GradeTooLowException();
    }
}
