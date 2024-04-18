/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:40:59 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/18 12:39:41 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap a;
	a.setName("42");
	FragTrap b("BIG");
	std::cout << "-------------------------" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout <<  std::endl;

	a.attack("Bid");
	b.takeDamage(a.getAttack());
	std::cout << "-------------------------" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout <<  std::endl;
	b.attack("42");
	a.beRepaired(5000);
	std::cout << "-------------------------" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout <<  std::endl;
	b.beRepaired(10000);
	a.highFives();
	std::cout << std::endl;
	return (0);
}


