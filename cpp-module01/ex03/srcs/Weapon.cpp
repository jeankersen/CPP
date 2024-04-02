/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:41:53 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/02 13:24:32 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
    this->_type = nullptr;
}

Weapon::Weapon(const std::string& type)
{
    this->_type = type;
}

Weapon::~Weapon()
{

}

const std::string& Weapon::getType(void)
{
    return  this->_type;
}

void Weapon::setType(const std::string& type)
{
    this->_type = type;
}