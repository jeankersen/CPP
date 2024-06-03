/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:57:21 by jvillefr          #+#    #+#             */
/*   Updated: 2024/06/03 13:23:07 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define LOWGRADE 150
#define HIGHGRADE 1

#include<iostream>
#include<string>
#include<stdexcept>
#include <string>



class Bureaucrat
{
    private:
        std::string _name;
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

        std::string getName() const;
        int getGrade() const;
        
        void addGrade();
        void takeGrade();
};


std::ostream& operator<<(std::ostream & o, Bureaucrat const & obj);

#endif