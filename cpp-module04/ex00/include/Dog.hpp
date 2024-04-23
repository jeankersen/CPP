/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:40:59 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/23 15:25:05 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{        
    public:
        Dog(void);
        Dog(const Dog &src);
        virtual ~Dog(void);
        
        Dog& operator=(const Dog &src);

        virtual void makeSound(void) const;
        
};
#endif
