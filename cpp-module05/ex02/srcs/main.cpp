/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:42:28 by jvillefr          #+#    #+#             */
/*   Updated: 2024/06/04 16:05:30 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void test1()
{
    try 
    {
        PresidentialPardonForm PForm1;

        ShrubberyCreationForm RForm1;
        ShrubberyCreationForm RForm2("RForm2");

        RobotomyRequestForm BForm1;
        RobotomyRequestForm BForm2("BForm2");
        

        
        RForm1 = RForm2;
        PForm1.action();
        BForm1 = BForm2;
        BForm1.action();

        
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

       
       // ShrubberyCreationForm RForm2("SForm");

     
       // RobotomyRequestForm BForm2("BForm");
       
        
        Bureaucrat bob("bob", 5);
        PForm.beSigned(bob);
        PForm.execute(bob);

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
        PresidentialPardonForm PForm("PForm");

       
       // ShrubberyCreationForm RForm2("SForm");

     
       // RobotomyRequestForm BForm2("BForm");
       
        Bureaucrat random;
        Bureaucrat bob("bob", 5);
        PForm.beSigned(bob);
        PForm.execute(random);

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
        PresidentialPardonForm PForm("PForm");

       
       // ShrubberyCreationForm RForm2("SForm");

     
       // RobotomyRequestForm BForm2("BForm");
       
        
        Bureaucrat bob("bob", 5);
        PForm.beSigned(bob);
        bob.executeForm(PForm);

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
       // PresidentialPardonForm PForm("PForm");
       RobotomyRequestForm BForm("BForm");
       
        
        Bureaucrat bob("bob", 5);
        BForm.beSigned(bob);
       // BForm.action();
        bob.executeForm(BForm);

    }
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }
}



int main(void) 
{
    
    //test1(); // default and arguments construtor AForm
   // test2(); // error  range form
   // test3(); // random cant sign big form (via form)
   //test4(); // random cant sign big form (via form)
    test5(); // bigform can be signed by bob (via form)
   // test6(); // big form can be signed by bob(via bureaucrat class)
   //test7(); // random cant sign form (via bureaucrat class)
}