/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:40:59 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/23 14:23:00 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{        
    private:
        Brain *brain;
    
    public:
        Dog(void);
        Dog(const Dog &src);
        virtual ~Dog(void);
        
        Dog& operator=(const Dog &src);

        virtual void makeSound(void) const;
        
};

std::ostream	&operator<<(std::ostream &stream, Dog &dog);
#endif
