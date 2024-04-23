/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:40:59 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/23 15:28:51 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

#include <string>
#include "Color.hpp"

class WrongAnimal
{
    protected:
        std::string type;
        
    public:
        WrongAnimal(void);
   
        WrongAnimal(const WrongAnimal &src);
        virtual ~WrongAnimal(void);
        
        virtual WrongAnimal& operator=(const WrongAnimal &src);
        
        virtual void makeSound(void) const;
    
        std::string getType(void) const;
        
};

#endif
