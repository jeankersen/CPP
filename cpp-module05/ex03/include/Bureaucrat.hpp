/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:42:08 by jvillefr          #+#    #+#             */
/*   Updated: 2024/06/10 13:08:30 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define LOWGRADE 150
#define HIGHGRADE 1

#include<iostream>
#include<string>
#include<stdexcept>
#include "AForm.hpp"

class AForm;


class Bureaucrat
{
    private:
        const std::string _name;
        int        _grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat & operator=(Bureaucrat const & src);
        Bureaucrat(Bureaucrat const & cpy);
        ~Bureaucrat();

        class GradeTooHighException : public std::exception 
        {
            public:
                virtual const char *what() const throw();
        };
        
        class GradeTooLowException :  public std::exception 
        {
            public:
                virtual const char *what() const throw();
        };

        const std::string getName() const;
        int getGrade() const;
        
        void addGrade();
        void takeGrade();

        void signForm(AForm & form);

        void executeForm(AForm const & form);
};


std::ostream& operator<<(std::ostream & o, Bureaucrat const & obj);



#endif