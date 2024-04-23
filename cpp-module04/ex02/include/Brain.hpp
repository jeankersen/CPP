/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:40:59 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/23 14:20:43 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

#include <string>
#include "Color.hpp"

class Brain
{
    
        
    public:
        Brain(void);
   
        Brain(const Brain &src);
        virtual ~Brain(void);
        
        virtual Brain& operator=(const Brain &src);
        std::string ideas[100];
        
             
        
};

#endif
