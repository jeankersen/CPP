/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:43:17 by jvillefr          #+#    #+#             */
/*   Updated: 2024/06/04 17:01:12 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include<iostream>
#include<string>
#include<stdexcept>
#include "Bureaucrat.hpp"


class Bureaucrat;
class AForm
{
    private:
        std::string _name;
        bool    _isSigned;
        int  _gradeToSign;
        int  _gradeToExecute;
        
    public:
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
        

        AForm();
        AForm(std::string name, int gradeToSign, int gradeToExecute);
        AForm & operator=(AForm const & src);
        AForm(AForm const & cpy);
        virtual ~AForm();
    
        std::string getName() const;
        std::string getSign() const;
        int  getGradeToSign() const;
        int  getGradeToExecute() const;
        void setSign();
        
        virtual AForm * clone(std::string Target) = 0;
        
        void beSigned(Bureaucrat const & bureau);

        virtual void action() const = 0;

        void execute(Bureaucrat const & executor) const;

};

std::ostream& operator<<(std::ostream & out, AForm const & obj);

#endif