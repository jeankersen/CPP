/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:18:01 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/10 17:36:34 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int _nbr;
    static const int _bits = 8;

public:
    // Constructeurs et destructeur
    Fixed();
    Fixed(const int val);
    Fixed(const float val);
    Fixed(const Fixed &src);
    ~Fixed();

    // Opérateurs de comparaison
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    // Opérateurs arithmétiques
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    // Opérateurs d'incrémentation/décrémentation
    Fixed &operator++(); // Pré-incrémentation
    Fixed operator++(int); // Post-incrémentation
    Fixed &operator--(); // Pré-décrémentation
    Fixed operator--(int); // Post-décrémentation

    // Opérateur d'assignation
    Fixed &operator=(const Fixed &src);

    // Fonctions statiques min et max
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

    // Fonctions membres
    int getRawBits() const;
    void setRawBits(int const raw);
    int toInt() const;
    float toFloat() const;
};

// Opérateur d'affichage
std::ostream &operator<<(std::ostream &str, const Fixed &fixed_nbr);

#endif

