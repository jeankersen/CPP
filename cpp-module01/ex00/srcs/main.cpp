/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:40:59 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/01 10:41:00 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "Zombie.hpp"
#include "Function.hpp"

int main(void)
{
    Zombie* zombie;

    zombie = newZombie("zombie1");
    zombie->announce();
    randomChump("zombie2");

    delete zombie;
}