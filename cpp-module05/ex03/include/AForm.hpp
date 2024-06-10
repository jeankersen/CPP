/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:43:17 by jvillefr          #+#    #+#             */
/*   Updated: 2024/06/10 13:16:29 by jvillefr         ###   ########.fr       */
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
        const std::string _name;
        std::string _target;
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
        

        AForm();
        AForm(std::string name, int gradeToSign, int gradeToExecute, std::string target);
        AForm & operator=(AForm const & src);
        AForm(AForm const & cpy);
        virtual ~AForm();
    
        const std::string getName() const;
        std::string getTarget() const;
        std::string getSign() const;
        int  getGradeToSign() const;
        int  getGradeToExecute() const;
        void setSign();
        void setTarget(std::string target);
        
        void beSigned(Bureaucrat const & bureau);

        virtual void action() const = 0;

        void execute(Bureaucrat const & executor) const;

};

std::ostream& operator<<(std::ostream & out, AForm const & obj);

#endif