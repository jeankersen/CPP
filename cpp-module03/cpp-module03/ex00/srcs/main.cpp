/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:40:59 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/18 12:16:57 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

#include "ClapTrap.hpp"

void test1(void){
    ClapTrap clap1("Clap1");
    ClapTrap clap2;
	clap2.setName("42");
	
    // Affichage des informations initiales
	std::cout << std::endl;
	std::cout << "------------" << std::endl;
    std::cout << clap1 << std::endl;
	std::cout << clap2 << std::endl;
	std::cout << "------------" << std::endl;

    // Attaque et affichage des informations après l'attaque
	clap1.setAttack(11);
    clap1.attack("42");
    clap2.takeDamage(clap1.getAttack());
	std::cout << std::endl;
	std::cout << "------------" << std::endl;
    std::cout << clap1 << std::endl;
	std::cout << clap2 << std::endl;
	std::cout << std::endl;
	std::cout << "------------" << std::endl;

    // Réparation et affichage des informations après la réparation
    clap1.beRepaired(20);
    clap2.beRepaired(15);
	std::cout << std::endl;
	std::cout << "------------" << std::endl;
    std::cout << clap1 << std::endl;
	std::cout << clap2 << std::endl;
	std::cout << "------------" << std::endl;
	std::cout << std::endl;
	clap2.attack("Clap1");
	std::cout << std::endl;
}
	
void displyaState(ClapTrap& a, ClapTrap& b, ClapTrap& c, ClapTrap& d)
{
	std::cout << std::endl;
	std::cout << "------------" << std::endl;
	a.displayInfo();
	b.displayInfo();
	c.displayInfo();
	d.displayInfo();
	std::cout << std::endl;
}

void test2(void)
{
	ClapTrap a("Object");
	ClapTrap b;
	ClapTrap c = a;
	b = c;
	a.setName("42");
	ClapTrap d(a);
	displyaState(a, b, c, d);
	b.setName("PLANET");
	c.setName("You");
	d.setName("ROBOT");
	displyaState(a, b, c, d);


	a.attack("PLANET");
	b.takeDamage(10);
	displyaState(a, b, c, d);
	b.beRepaired(200);
	a.beRepaired(50000);
	displyaState(a, b, c, d);
	std::cout << std::endl;
}

int main(void)
{
	test1();
	//test2();
	return (0);
}




