/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:42:28 by jvillefr          #+#    #+#             */
/*   Updated: 2024/06/07 10:04:50 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

const std::string COLOR_ORANGE = "\033[38;5;208m";   // Orange
const std::string COLOR_BACK = "\033[0m";            // Black

void test1()
{
    try 
    {
        PresidentialPardonForm PForm1;
        PresidentialPardonForm PForm2("PForm2");

        ShrubberyCreationForm SForm1;
        ShrubberyCreationForm SForm2("SForm2");

        RobotomyRequestForm RForm1;
        RobotomyRequestForm RForm2("RForm2");
        

        PForm1 = PForm2;
        PForm1.action();
        
        SForm1 = SForm2;
        SForm1.action();
        
        RForm1 = RForm2;
        RForm1.action();

        
    }
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }
}





void test2()
{
    try 
    {
        PresidentialPardonForm PForm("PForm");
        
        Bureaucrat random;
        Bureaucrat bob("bob", 5);
        PForm.beSigned(bob);
        PForm.execute(bob);
        PForm.execute(random);

    }
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }
}




void test3()
{
    try 
    {
        ShrubberyCreationForm SForm("SForm");
        
        Bureaucrat random;
        Bureaucrat bob("bob", 5);
        SForm.beSigned(bob);
        SForm.execute(bob);
        SForm.execute(random);

    }
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }

}




void test4()
{
    try 
    {
        RobotomyRequestForm RForm("BForm");
        
        Bureaucrat random;
        Bureaucrat bob("bob", 5);
        
        RForm.beSigned(bob);
        RForm.execute(bob);
        RForm.execute(random);

    }
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }
}



void test5()
{
    try 
    {
        RobotomyRequestForm RForm("BForm");
        
        Bureaucrat random;
        Bureaucrat bob("bob", 5);
        
        bob.signForm(RForm);
        bob.executeForm(RForm);
        random.executeForm(RForm);

    }
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }
}



int main(void) 
{
    std::cout << COLOR_ORANGE <<  " TEST 1-default and arguments construtor forms with all forms and their actions" << COLOR_BACK << std::endl;
    test1();
    
    std::cout << std::endl;
    std::cout << COLOR_ORANGE <<  " TEST 2- try execute and sign PresidentialForm" << COLOR_BACK << std::endl;
    test2();
    
    std::cout << std::endl;
    std::cout << COLOR_ORANGE <<  " TEST 3-try execute and sign ShrubberyCreationForm" << COLOR_BACK << std::endl;
    test3(); 
    
    std::cout << std::endl;
    std::cout << COLOR_ORANGE <<  " TEST 4-try execute and sign RobotomyRequestForm" << COLOR_BACK << std::endl;
    test4();
    
    std::cout << std::endl;
    std::cout << COLOR_ORANGE <<  " TEST 4-try execute and sign RobotomyRequestForm" << COLOR_BACK << std::endl;
    test5();
}