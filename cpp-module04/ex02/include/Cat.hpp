/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:40:59 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/23 14:20:47 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{       
    private:
    Brain *brain;
    
    public:
        Cat(void);
        Cat(const Cat &src);
        virtual ~Cat(void);
        
        Cat& operator=(const Cat &src);

        virtual void makeSound(void) const;
        
};

std::ostream	&operator<<(std::ostream &stream, Cat &cat);
#endif
