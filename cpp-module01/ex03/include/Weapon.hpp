/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:02:54 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/02 09:14:24 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include<string.h>

class Weapon
{
	private:
	std::string		_type;
    
    public:
    Weapon();
    ~Weapon();

    const std::string& getType(void);
    void setType(std::string& type);
};

#endif
