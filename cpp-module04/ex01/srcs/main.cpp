/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:32:36 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/23 17:01:42 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"




int	main( void )
{
	Animal *tab[4];
	Brain *catBrain;
	Brain *dogBrain;
    std::cout << "--------0--------" << std::endl;
    
	Dog a;
	std::cout << "--------1--------" << std::endl;
	Dog b(a);
	std::cout << "---------2-------" << std::endl;

	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
		{
			tab[i] = new Dog();
			tab[i]->makeSound();
		}
		else
		{
			tab[i] = new Cat();
			tab[i]->makeSound();
		}
	}
	dogBrain = &tab[0]->getBrain();
	catBrain = &tab[2]->getBrain();
	catBrain->ideas[0] = dogBrain->ideas[0] = "TON TON TONMMM !!";
	catBrain->ideas[1] = dogBrain->ideas[1] = "MY NAME IS MY NAME";
	catBrain->ideas[2] = dogBrain->ideas[2] = "WILL YOU ROCK WITH ME";
	catBrain->ideas[3] = dogBrain->ideas[3] = "42424242424242424224";
	std::cout << "************************************" << std::endl;
	std::cout << "|" << tab[0]->getBrain().ideas[0] << "|" << std::endl;
	*(tab[1]) = *(tab[0]);
	std::cout << "|" << tab[1]->getBrain().ideas[1] << "|" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "|" << tab[2]->getBrain().ideas[2] << "|" << std::endl;
	*(tab[3]) = *(tab[2]);
	std::cout << "|" << tab[3]->getBrain().ideas[3] << "|" << std::endl;
	std::cout << "-----------------------------------" << std::endl;

	delete tab[0];
	delete tab[1];
	delete tab[2];
    delete tab[3];


	std::cout << "===================================" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	return (0);
}

