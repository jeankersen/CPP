/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:40:59 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/23 14:51:42 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

#include <string>
#include "Color.hpp"

class Animal
{
    protected:
        std::string type;
        
    public:
        Animal(void);
        Animal(std::string ntype);
        Animal(const Animal &src);
        virtual ~Animal(void);
        
        virtual Animal& operator=(const Animal &src);
        
        virtual void makeSound(void) const = 0;
    
        std::string getType(void) const;
        void setType(std::string const ntype);
        
};

std::ostream	&operator<<(std::ostream &stream, Animal &animal);
#endif


/*





int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
delete meta;
delete j;
delete i;

return(0);
}
*/