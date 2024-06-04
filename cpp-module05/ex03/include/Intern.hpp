/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:16:29 by jvillefr          #+#    #+#             */
/*   Updated: 2024/06/04 16:38:15 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INTERN_HPP
#define INTERN_HPP

#define LOWGRADE 150
#define HIGHGRADE 1

#include<iostream>
#include<string>
#include<stdexcept>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


class AForm;
class Intern
{
    private:
        AForm *forms[3];

    public:
        Intern();
        Intern & operator=(Intern const & src);
        Intern(Intern const & cpy);
        ~Intern();

        class FormNotFound : public std::exception 
		{
            public:
                const char *what() const throw();
        };
        
        AForm * makeForm(std::string formName, std::string target);

};



#endif