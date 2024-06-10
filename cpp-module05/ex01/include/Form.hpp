/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:43:17 by jvillefr          #+#    #+#             */
/*   Updated: 2024/06/10 10:02:02 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include<iostream>
#include<string>
#include<stdexcept>
#include "Bureaucrat.hpp"


class Bureaucrat;
class Form
{
    private:
        const std::string _name;
        bool    _isSigned;
        const int  _gradeToSign;
        const int  _gradeToExecute;
        
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
        

        Form();
        Form(std::string name, int gradeToSign, int gradeToExecute);
        Form & operator=(Form const & src);
        Form(Form const & cpy);
        ~Form();
    
        const std::string getName() const;
        std::string getSign() const;
        int  getGradeToSign() const;
        int  getGradeToExecute() const;
        void setSign();
        
        void beSigned(Bureaucrat const & bureau);

};

std::ostream& operator<<(std::ostream & out, Form const & obj);

#endif