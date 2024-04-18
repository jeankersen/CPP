/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:18:01 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/18 09:46:04 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include <cmath>
#include <string>

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap 
{
    private:
        
    public:
        ScavTrap(void);
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &src);
        ~ScavTrap(void);
        
        void attack(const std::string& target);
        ScavTrap& operator=(const ScavTrap &src);

        void guardGate(void);
        
};
#endif
