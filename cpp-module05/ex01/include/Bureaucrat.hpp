/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:42:08 by jvillefr          #+#    #+#             */
/*   Updated: 2024/05/17 16:10:02 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#define BUREAUCRAT_HPP

#define LOWGRADE 150
#define HIGHGRADE 1

#include<iostream>
#include<string>
#include<stdexcept>
#include "Form.hpp"



class Bureaucrat
{
    private:
        std::string _name;
        int        _grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat & operator=(Bureaucrat const & src);
        Bureaucrat(Bureaucrat const & cpy);
        ~Bureaucrat();

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

        std::string getName() const;
        int getGrade() const;
        
        void addGrade() const;
        void takeGrade() const;

        void signForm(Form const & form);
};


std::ostream& operator<<(std::ostream & o, Bureaucrat const & obj);

#endif