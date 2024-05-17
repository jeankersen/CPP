/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:43:17 by jvillefr          #+#    #+#             */
/*   Updated: 2024/05/17 16:15:14 by jvillefr         ###   ########.fr       */
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
        bool    _sign;
        int const _gradeToSign;
        int const _gradeToExecute;
        
    public:
        class GradeTooHighException : public std::exception 
        {
            public:
                const char *what() const throw();
        };
        
        class GradeTooLowException :  public std::exception 
        {
            public:
                const char *what() const throw(Form const & form);
        };


        Form();
        Form(std::string name, bool sign, int const getGradeToSign, int const getGradeToExecute);
        Form & operator=(Form const & src);
        Form(Form const & cpy);
        ~Form();
    
        std::string getName() const;
        bool getSign() const;
        int const getGradeToSign() const;
        int const getGradeToExecute() const;
        
        
        void beSigned(Bureaucrat const & bureau);
        
};

std::ostream& operator<<(std::ostream & o, Form const & obj);

#endif