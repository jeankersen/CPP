/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:52:36 by jvillefr          #+#    #+#             */
/*   Updated: 2024/06/04 13:53:08 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include<iostream>
#include<string>
#include<stdexcept>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <fstream>


class Bureaucrat;
class AForm;
class PresidentialPardonForm : public AForm
{

    private:
        std::string Target;
        
    public:
        PresidentialPardonForm();
        
        PresidentialPardonForm(std::string Target);
        PresidentialPardonForm & operator=(PresidentialPardonForm const & src);
        PresidentialPardonForm(PresidentialPardonForm const & cpy);
        ~PresidentialPardonForm();

        void action() const;
    

};

#endif