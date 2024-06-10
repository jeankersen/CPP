/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:42:28 by jvillefr          #+#    #+#             */
/*   Updated: 2024/06/10 14:00:54 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
const std::string COLOR_ORANGE = "\033[38;5;208m";   // Orange
const std::string COLOR_BACK = "\033[0m";            // Black

void test1()
{
    try 
	{
        Intern intern;
        AForm *ShrubberyCreationForm  = intern.makeForm("ShrubberyCreationForm", "garden");
        Bureaucrat bob("Bob", 137);
        Bureaucrat jhon("Jhon", 145);
        
        bob.signForm(*ShrubberyCreationForm);
        jhon.executeForm(*ShrubberyCreationForm);

        jhon.executeForm(*ShrubberyCreationForm);

        delete ShrubberyCreationForm ;
    }
    
	catch (std::exception & e) 
	{
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test2()
{
    try 
	{
        Intern intern;
        AForm *RobotomyRequestForm = intern.makeForm("RobotomyRequestForm", "garden");
        Bureaucrat bob("bob", 44);
        Bureaucrat jhon("jhon", 72);
        bob.executeForm(*RobotomyRequestForm);
        jhon.signForm(*RobotomyRequestForm);

        jhon.executeForm(*RobotomyRequestForm);

        delete RobotomyRequestForm;
    }

    catch (std::exception & e) 
	{
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test3()
{

    try
	{
        Intern intern;
        AForm *PresidentialPardonForm = intern.makeForm("PresidentialPardonForm", "garden");
        Bureaucrat bob("bob", 5);
        Bureaucrat jhon("jhon", 24);
        jhon.signForm(*PresidentialPardonForm);
        bob.executeForm(*PresidentialPardonForm);
        jhon.executeForm(*PresidentialPardonForm);
        
        delete PresidentialPardonForm;
    }

    catch (std::exception & e) 
	{
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test4()
{
    Intern intern;

    try 
	{
        AForm *PresidentialPardonForm = intern.makeForm("Whatever AForm", "MIAOU");
        Bureaucrat bob("bob", 5);
        Bureaucrat jhon("jhon", 24);
        jhon.signForm(*PresidentialPardonForm);
        bob.executeForm(*PresidentialPardonForm);

        jhon.executeForm(*PresidentialPardonForm);

        delete PresidentialPardonForm;       

    }

    catch (std::exception & e) 
	{
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

int main(void) 
{

    std::cout << COLOR_ORANGE <<  " TEST 1-Intern construtor, try to sign and execute ShrubberyCreationForm" << COLOR_BACK << std::endl;
    test1();

    std::cout << std::endl;
    std::cout << COLOR_ORANGE <<  " TEST 2-Intern construtor, try to sign and execute RobotomyRequestForm" << COLOR_BACK << std::endl;
    test2();

    std::cout << std::endl;
    std::cout << COLOR_ORANGE <<  " TEST 3-Intern construtor, try to sign and execute RobotomyRequestForm" << COLOR_BACK << std::endl;
    test3();
    
    std::cout << std::endl;
    std::cout << COLOR_ORANGE <<  " TEST 4-Intern construtor, try to sign and execute AForm that does not exist" << COLOR_BACK << std::endl;
    test4();

}