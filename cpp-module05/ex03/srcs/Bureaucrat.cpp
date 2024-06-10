/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:42:21 by jvillefr          #+#    #+#             */
/*   Updated: 2024/06/10 14:02:03 by jvillefr         ###   ########.fr       */
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
    std::cout << COLOR_GREEN <<  getName() <<  ": bureaucrat Constructor called with args " << COLOR_BACK << std::endl;
    if(grade < HIGHGRADE)
        throw Bureaucrat::GradeTooHighException();
    if(grade > LOWGRADE)
        throw Bureaucrat::GradeTooLowException();

}


Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src)
{
    std::cout << COLOR_GREEN << "Bureaucrat Copy operator called"  << COLOR_BACK  <<  std::endl;
    if(this != & src)
    {
        if(src.getGrade() < HIGHGRADE)
            throw Bureaucrat::GradeTooHighException();
        if(src.getGrade() > LOWGRADE)
            throw Bureaucrat::GradeTooLowException();
    }
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

const std::string Bureaucrat::getName() const
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

void Bureaucrat::signForm(AForm & form)
{
    if(form.getSign() == "True")
    {
        std::cout << form.getName() << " already signed!" << std::endl;
    }
    else
    {
        if(this->getGrade() <= form.getGradeToSign())
        {
            form.setSign();
            std::cout << getName() << " signed " << form.getName() << "." << std::endl;
        }
        else
        {
            std::cout << getName() << " couldn’t signed " << form.getName() << " because " << GradeTooLowException().what() << "." << std::endl;
           throw Bureaucrat::GradeTooLowException();
        }
    }
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

void Bureaucrat::executeForm(AForm const & form)
{
    if(getGrade() <= form.getGradeToExecute() && form.getSign() == "True")
    {
        form.execute(*(this));
        std::cout << getName() << " executed " << form.getName() << std::endl;
    }
    else
    {
        std::cout << "Grade of " << getName() << " is too low." << std::endl;
        //throw Bureaucrat::GradeTooLowException();
    }
}