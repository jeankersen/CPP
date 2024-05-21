/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:43:17 by jvillefr          #+#    #+#             */
/*   Updated: 2024/05/21 15:31:27 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include<iostream>
#include<string>
#include<stdexcept>
#include "Bureaucrat.hpp"

class Form
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
                const char *what() const throw();
        };
        
        class GradeTooLowException :  public std::exception 
        {
            public:
                const char *what() const throw();
        };


        Form();
        Form(std::string name, int gradeToSign, int gradeToExecute);
        Form & operator=(Form const & src);
        Form(Form const & cpy);
        ~Form();
    
        std::string getName() const;
        std::string getSign() const;
        int  getGradeToSign() const;
        int  getGradeToExecute() const;
        
        
        void beSigned(Bureaucrat const & bureau);

};

std::ostream& operator<<(std::ostream & out, Form const & obj);

#endif