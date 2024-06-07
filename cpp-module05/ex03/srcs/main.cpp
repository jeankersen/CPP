/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:42:28 by jvillefr          #+#    #+#             */
/*   Updated: 2024/06/07 14:29:09 by jvillefr         ###   ########.fr       */
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

    Intern intern;

    try 
	{
        AForm *theForm = intern.makeForm("ShrubberyCreationForm", "garden");
        Bureaucrat b1("Bob", 136);
        Bureaucrat b2("Jhon", 145);
        b2.signForm(*theForm);
        b1.executeForm(*theForm);

        b2.executeForm(*theForm);
        delete theForm;
    }
    
	catch (std::exception & e) 
	{
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test2()
{
    Intern intern;

    try 
	{
        AForm *theForm = intern.makeForm("RobotomyRequestForm", "garden");
        Bureaucrat b1("bob", 44);
        Bureaucrat b2("perry", 72);
        b2.signForm(*theForm);
        b1.executeForm(*theForm);

        b2.executeForm(*theForm);
        delete theForm;
    }

    catch (std::exception & e) 
	{
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void test3()
{
    Intern intern;

    try
	{
        AForm *theForm = intern.makeForm("PresidentialPardonForm", "garden");
        Bureaucrat b1("bob", 5);
        Bureaucrat b2("perry", 24);
        b2.signForm(*theForm);
        b1.executeForm(*theForm);

        b2.executeForm(*theForm);
        delete theForm;
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
        AForm *theForm = intern.makeForm("Whatever AForm", "MIAOU");
        Bureaucrat b1("bob", 5);
        Bureaucrat b2("perry", 24);
        b2.signForm(*theForm);
        b1.executeForm(*theForm);

        b2.executeForm(*theForm);
        delete theForm;
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