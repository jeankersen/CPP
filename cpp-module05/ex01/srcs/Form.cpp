/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:37:34 by jvillefr          #+#    #+#             */
/*   Updated: 2024/05/21 15:25:30 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
{
    this->_name = "Default Form";
    this->_isSigned = false;
    this->_gradeToExecute = 150;
    this->_getGradeToExecute = 150;
    std::cout << "Default form construtor created" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute): _name(name), _isSigned(false)
{
    if(gradeToSign < HIGHGRADE || gradeToExecute < HIGHGRADE)
        throw GradeTooHighException();
    else if(gradeToSign > LOWGRADE || gradeToExecute > LOWGRADE)
        throw GradeTooLowException();
    else if(gradeToSign > gradeToExecute)
        throw GradeTooHighException();
    else
        {
            this->_gradeToExecute = gradeToSign;
            this->_gradeToExecute = gradeToExecute;
            std::cout << "Constructor Form witht args " << getName() << "."<< std::endl;
        }
        
}
Form & Form::operator=(Form const & src) 
{
    if( this != & src)
    {
        _name = src.getName();
        _isSigned = src.getSign();
        _gradeToSign = src.getGradeToSign();
        _gradeToExecute = src.getGradeToExecute();
    }
    return (*this);
}

Form::Form(Form const & cpy)
{
    *this = cpy;
    std::cout << "Form with copy" << std::endl;
}

Form::~Form()
{
    std::cout << getName() << " :form deleted!" << std::endl;
}

std::string Form::getName() const
{
    return (this->_name);
}


std::string  Form::getSign() const
{
   if(_isSigned)
        return "True";
    else
        return "False";
}

int Form::getGradeToSign() const
{
    return (this->_gradeToSign);
}

int Form::getGradeToExecute() const
{
    return (this->_gradeToExecute);
}

void Form::beSigned(Bureaucrat const & bureaucrat)
{
    if(this->_isSigned == true)
        std::cout << "Already signed!" << std::endl;
    else if(this->_gradeToSign < bureaucrat.getGrade())
    {
        std::cout << bureaucrat.getName() << " couldn’t signed " << getName() << " because " << std::endl;
        throw Bureaucrat::GradeTooLowhException();
        
    }
    else
    {
        this->_isSigned = true;
         std::cout << bureaucrat.getName() << " signed " << getName() << std::endl;
    }

        
}



std::ostream & operator<<(std::ostream & out, Form const & obj)
{
    out << "Form name: " << obj.getName() << std::endl;
    out << "Sidned: " << obj.getSign() << std::endl;
    out << "Grade to sign: " << obj.getGradeToSign() << std::endl;
    out << "Grade to execute: " << obj.getGradeToExecute() << std::endl;
    return out;
}