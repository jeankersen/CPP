/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:18:01 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/10 15:29:38 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include<string.h>

class Fixed 
{
    private:
        int _nbr;
        static const int _bits = 8;
        
    public:
        Fixed(void);
        ~Fixed(void);
        Fixed(Fixed const &src);
        
        Fixed& operator=(const Fixed &src);
        int getRawBits(void) const;
        void setRawBits(int const raw);
    
};

#endif
