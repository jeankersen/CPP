/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:42:28 by jvillefr          #+#    #+#             */
/*   Updated: 2024/06/07 09:15:22 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
const std::string COLOR_ORANGE = "\033[38;5;208m";   // Orange
const std::string COLOR_BACK = "\033[0m";            // Black

void test2()
{
    try 
    {
        Form form1("Big Form", 10, 151);
        Form form2("Big Form", 0, 10);
    }
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }
}

void test1()
{
    try 
    {
        Form bigForm;
        std::cout << bigForm<< std::endl;
        
        Bureaucrat randomBureaucrat;
        std::cout << randomBureaucrat << std::endl;
    
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;
        
        
        Form form1("Big Form", 10, 10);      
        bigForm = form1;
        std::cout << bigForm <<  std::endl;
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
        Form bigForm;
        std::cout << bigForm<< std::endl;
        
        Bureaucrat randomBureaucrat;
        std::cout << randomBureaucrat << std::endl;
    
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;
        
        
        Form form1("Big Form", 10, 10);      
        bigForm = form1;
        std::cout << bigForm <<  std::endl;

        bigForm.beSigned(randomBureaucrat);
        
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
        Form bigForm;
        std::cout << bigForm<< std::endl;
        
        Bureaucrat randomBureaucrat;
        std::cout << randomBureaucrat << std::endl;
    
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;
        
        
        Form form1("Big Form", 10, 10);      
        bigForm = form1;
        std::cout << bigForm <<  std::endl;
        
        randomBureaucrat.signForm(form1);
        std::cout << bigForm << std::endl;
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
        Form bigForm;
        std::cout << bigForm<< std::endl;
        
        Bureaucrat randomBureaucrat;
        std::cout << randomBureaucrat << std::endl;
    
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;
        
        
        Form form1("Big Form", 10, 10);      
        bigForm = form1;
        std::cout << bigForm <<  std::endl;
        
        bigForm.beSigned(bob);
        std::cout << bigForm << std::endl;
        bigForm.beSigned(randomBureaucrat);

    }
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }
}


void test6()
{
    try 
    {
        Form bigForm;
        std::cout << bigForm<< std::endl;
        
        Bureaucrat randomBureaucrat;
        std::cout << randomBureaucrat << std::endl;
    
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;
        
        
        Form form1("Big Form", 10, 10);      
        bigForm = form1;
        std::cout << bigForm <<  std::endl;
        
        bob.signForm(bigForm);
        std::cout << bigForm << std::endl;
        randomBureaucrat.signForm(bigForm);
    }
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }
}

void test7()
{
    try 
    {
        Form bigForm;
        std::cout << bigForm<< std::endl;
        
        Bureaucrat randomBureaucrat;
        std::cout << randomBureaucrat << std::endl;
    
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;
        
        
        Form form1("Big Form", 10, 10);      
        bigForm = form1;
        std::cout << bigForm <<  std::endl;
        
        randomBureaucrat.signForm(bigForm);
        std::cout << bigForm << std::endl;
    }
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }
}

int main(void) 
{
    std::cout << COLOR_ORANGE <<  " TEST 1-default and arguments construtor form" << COLOR_BACK << std::endl;
    test1();
    std::cout << std::endl;
    std::cout << COLOR_ORANGE <<  " TEST 2-error  range form" << COLOR_BACK << std::endl;
    test2(); 
    std::cout << std::endl;
    std::cout << COLOR_ORANGE <<  " TEST 3-random cant sign big form (via Form class)" << COLOR_BACK << std::endl;
    test3();
    std::cout << std::endl;
    std::cout << COLOR_ORANGE <<  " TEST 4-random cant sign big form (Bureaucrat class))" << COLOR_BACK << std::endl;
    test4();
    std::cout << std::endl;
    std::cout << COLOR_ORANGE <<  " TEST 5- form can be signed by bob (via Form class) // try to sign again" << COLOR_BACK << std::endl;
    test5(); 
    std::cout << std::endl;
    std::cout << COLOR_ORANGE <<  " TEST 6- form can be signed by bob(via Bbureaucrat class) // try to sign again" << COLOR_BACK << std::endl;
    test6();
    std::cout << std::endl;
    std::cout << COLOR_ORANGE <<  " TEST 7-random cant sign form (via bureaucrat class)" << COLOR_BACK << std::endl;
    test7(); 
}