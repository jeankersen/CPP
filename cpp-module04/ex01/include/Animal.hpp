/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:40:59 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/23 17:03:44 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

#include <string>
#include "Color.hpp"
#include "Brain.hpp"

class Animal
{
    protected:
        std::string type;
        
    public:
        Animal(void);
        Animal(const Animal &src);
        virtual ~Animal(void);
        
        virtual Animal& operator=(const Animal &src);
        
        virtual void makeSound(void) const;
    
        std::string getType(void) const;
        virtual Brain &getBrain(void) const = 0;
        
};

std::ostream	&operator<<(std::ostream &stream, Animal &animal);
#endif


