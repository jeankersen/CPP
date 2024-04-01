/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:41:53 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/01 10:41:57 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{

}

Zombie::~Zombie()
{
    std::cout << get_name() << ": destroyed" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << get_name() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name)
{
    this->_name = name;
}

std::string Zombie::get_name(void)
{
    return this->_name;
}
