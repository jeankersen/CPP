/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:02:54 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/02 16:07:22 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include<string.h>

const std::string COLOR_BACK = "\033[0m";
const std::string COLOR_GREEN = "\033[38;5;70m";
const std::string COLOR_YELLOW = "\033[38;5;220m";
const std::string COLOR_RED = "\033[38;5;196m";
const std::string COLOR_BLUE = "\033[38;5;21m";
const std::string COLOR_MAGENTA = "\033[38;5;5m";
const std::string COLOR_CYAN = "\033[38;5;44m";
const std::string COLOR_ORANGE = "\033[38;5;214m";
const std::string COLOR_GREY = "\033[38;5;249m";
const std::string COLOR_BASIC = "\033[38;5;153m";

class Weapon
{
	private:
	std::string		_type;
    
    public:
    Weapon(std::string type);
    ~Weapon(void);

    const std::string& getType(void);
    void setType(std::string type);
};

#endif
