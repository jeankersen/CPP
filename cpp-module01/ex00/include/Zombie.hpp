/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:02:54 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/01 10:37:22 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include<string.h>

class Zombie
{
	private:
	std::string		_name;
    
    public:
    Zombie();
    ~Zombie();
     
    void announce(void);
    void set_name(std::string name);
    std::string get_name(void);
};

#endif
