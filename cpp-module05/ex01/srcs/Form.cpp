/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:37:34 by jvillefr          #+#    #+#             */
/*   Updated: 2024/05/17 16:05:56 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"



void Form::beSigned(Bureaucrat const & bureaucrat)
{
    if(bureaucrat.getGrade() > this->_gradeToSign)
        throw Bureaucrat::GradeTooLowhException();
    this->_sign = true;
        
}


std::ostream & operator<<(std::ostream & o, Form const & obj)
{
    o << obj.getName() <<  ":" << obj.getSign() << ".";
    return o;
}