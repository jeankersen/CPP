/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:18:01 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/10 17:35:22 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include<string.h>
#include <cmath>

class Fixed 
{
    private:
        int _nbr;
        static const int _bits = 8;
        
    public:
        Fixed(void);
        Fixed(const int val);
        Fixed(const float val);
        Fixed(Fixed const &src);
        ~Fixed(void);
        
        Fixed& operator=(const Fixed &src);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        int toInt(void) const;
        float toFloat(void) const;
    
};
std::ostream &operator<<(std::ostream &str, Fixed const &fixed_nbr);
#endif
