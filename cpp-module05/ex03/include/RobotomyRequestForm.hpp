/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:01:50 by jvillefr          #+#    #+#             */
/*   Updated: 2024/06/04 16:48:06 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include<iostream>
#include<string>
#include<stdexcept>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <fstream>


class Bureaucrat;
class AForm;
class RobotomyRequestForm : public AForm
{

    private:
        std::string Target;
        
    public:
        RobotomyRequestForm();
        
        RobotomyRequestForm(std::string Target);
        RobotomyRequestForm & operator=(RobotomyRequestForm const & src);
        RobotomyRequestForm(RobotomyRequestForm const & cpy);
        ~RobotomyRequestForm();

        AForm * clone(std::string Target);

        void action() const;
    

};

#endif