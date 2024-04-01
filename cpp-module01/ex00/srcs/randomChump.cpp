/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:41:46 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/01 10:41:49 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "Function.hpp"

void randomChump(std::string name)
{
    Zombie zombie;
    zombie.set_name(name);    
    zombie.announce();
}