/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:44:54 by jvillefr          #+#    #+#             */
/*   Updated: 2024/06/10 11:58:07 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include<iostream>
#include<string>
#include<stdexcept>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#define SIGNED 145
#define EXECUT 137
#include <fstream>



class Bureaucrat;
class AForm;
class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm();
        
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm & operator=(ShrubberyCreationForm const & src);
        ShrubberyCreationForm(ShrubberyCreationForm const & cpy);
        ~ShrubberyCreationForm();

        void action() const;
    

};

#endif