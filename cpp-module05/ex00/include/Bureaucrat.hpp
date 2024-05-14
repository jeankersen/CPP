/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:57:21 by jvillefr          #+#    #+#             */
/*   Updated: 2024/05/14 15:10:28 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define LOWGRADE 150
#define HIGHGRADE 1

#include<iostream>





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
                const char *what() const throw();
        };
        
        class GradeTooLowException :  public std::exception 
        {
            public:
                const char *what() const throw();
        };

        std::string getName() const;
        int getGrade() const;
        
        void addGrade();
        void takeGrade();
};


std::ostream& operator<<(std::ostream & o, Bureaucrat const & obj);

#endif