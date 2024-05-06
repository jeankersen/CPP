/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:18:01 by jvillefr          #+#    #+#             */
/*   Updated: 2024/05/06 16:01:14 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include "Color.hpp"

class Warlock
{
    private:
        std::string name;
        std::string title;
        Warlock & operator=(Warlock const &rhs);
        Warlock(Warlock const &rhs);
        Warlock();
    
    public:
        Warlock(std::string str1, std::string str2);

        //cpy constructor
        //Warlock(const Warlock& other);

        //cpy assignment operator // Juin -- 
        //Warlock& operator=(const Warlock& other);
        
        ~Warlock(void);

        void introduce(void) const;
        std::string  const & getName(void) const;
        std::string  const & getTitle(void) const;
    
        void setTitle(std::string  const & str);
};

#endif