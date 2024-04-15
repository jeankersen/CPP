/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:18:01 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/15 16:11:25 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <cmath>
#include <string>

class ClapTrap 
{
    private:
        std::string _name;
        int _hits;
        int _energy;
        int _attack;
        
    public:
        ClapTrap(void);
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const &src);
        ~ClapTrap(void);
        
        ClapTrap& operator=(const ClapTrap &src);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
    
        std::string getName(void) const;
        int getHits(void) const;
        int getEnergy(void) const;
        int getAttack(void) const;

        void setName(std::string const name);
        void setHits(int const hits);
        void setEnergy(int const energy);
        void setAttack(int const attack);
        
};

        std::ostream &operator<<(std::ostream &str, ClapTrap const &fixed_nbr);
#endif
