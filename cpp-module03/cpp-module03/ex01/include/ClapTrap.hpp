/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:18:01 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/16 15:54:23 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <cmath>
#include <string>

class ClapTrap 
{
    protected:
        std::string _name;
        int _hits;
        int _energy;
        int _attack;
        
    public:
        ClapTrap(void);
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &src);
        ~ClapTrap(void);
        
        ClapTrap& operator=(const ClapTrap &src);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
    
        std::string getName(void) const;
        int getHits(void) const;
        int getEnergy(void) const;
        int getAttack(void) const;
        
        void displayInfo(void);

        void setName(std::string const name);
        void setHits(int const hits);
        void setEnergy(int const energy);
        void setAttack(int const attack);
        
};

std::ostream	&operator<<(std::ostream &stream, ClapTrap &clapTrap);
#endif
