/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:40:59 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/18 12:37:06 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap a;
	a.setName("42");
	ScavTrap b("BIG");
	std::cout << "-------------------------" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout <<  std::endl;

	a.attack("BiG");
	a.attack("BiG");
	b.takeDamage(a.getHits());
	b.takeDamage(a.getHits());
	std::cout << "-------------------------" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout <<  std::endl;
	b.attack("42");
	std::cout << "-------------------------" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout <<  std::endl;
	a.beRepaired(5000);
	std::cout << "-------------------------" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout <<  std::endl;
	b.beRepaired(10000);
	a.guardGate();
	std::cout << std::endl;
	return (0);
}


