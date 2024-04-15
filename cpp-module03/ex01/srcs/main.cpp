/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:40:59 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/15 17:17:08 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main() {
	ClapTrap han("PAPA");
	ClapTrap leia("AMERICA");
	ClapTrap luke("COUNTRY");
	unsigned int amount = 2;
	
	// Display initial stats
	std::cout << "COUNTRY: name: " << luke.getName() << ", health: " << luke.getHits()
			  << ", energy: " << luke.getEnergy() << ", damage: " << luke.getAttack() << std::endl;
	std::cout << "PAPA: name: " << han.getName() << ", health: " << han.getHits()
			  << ", energy: " << han.getEnergy() << ", damage: " << han.getAttack() << std::endl;
	std::cout << "AMERICA: name: " << leia.getName() << ", health: " << leia.getHits()
			  << ", energy: " << leia.getEnergy() << ", damage: " << leia.getAttack() << std::endl;

	// Perform actions
	han.takeDamage(luke.getAttack());
	han.beRepaired(amount);
	leia.attack("COUNTRY");
	luke.takeDamage(leia.getAttack());
	luke.beRepaired(amount);
	luke.attack("PAPA");

	// Display updated stats
	std::cout << "COUNTRY: name: " << luke.getName() << ", health: " << luke.getHits()
			  << ", energy: " << luke.getEnergy() << ", damage: " << luke.getAttack() << std::endl;
	std::cout << "PAPA: name: " << han.getName() << ", health: " << han.getHits()
			<< ", energy: " << han.getEnergy() << ", damage: " << han.getAttack() << std::endl;
	std::cout << "AMERICA: name: " << leia.getName() << ", health: " << leia.getHits()
			<< ", energy: " << leia.getEnergy() << ", damage: " << leia.getAttack() << std::endl;

	return 0;
}
