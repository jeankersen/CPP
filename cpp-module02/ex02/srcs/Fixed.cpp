/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:23:37 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/10 17:36:56 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


const std::string COLOR_YELLOW = "\033[38;5;226m";   // Yellow
const std::string COLOR_MAGENTA = "\033[38;5;201m";  // Magenta
const std::string COLOR_CYAN = "\033[38;5;51m";      // Cyan
const std::string COLOR_WHITE = "\033[38;5;15m";     // White
const std::string COLOR_ORANGE = "\033[38;5;208m";   // Orange
const std::string COLOR_PURPLE = "\033[38;5;93m";    // Purple
const std::string COLOR_PINK = "\033[38;5;198m";     // Pink
const std::string COLOR_SKYBLUE = "\033[38;5;75m";   // Sky Blue
const std::string COLOR_LIME = "\033[38;5;154m";     // Lime
const std::string COLOR_GRAY = "\033[38;5;242m";     // Gray
const std::string COLOR_BACK = "\033[0m";            // Black
const std::string COLOR_GREEN = "\033[38;5;70m";     // Green
const std::string COLOR_RED = "\033[38;5;196m";      // Red

#include "Fixed.hpp"

// Constructeurs et destructeur
Fixed::Fixed() : _nbr(0) {}

Fixed::Fixed(const int val) : _nbr(val << _bits) {}

Fixed::Fixed(const float val) : _nbr((int)roundf(val * (1 << _bits))) {}

Fixed::Fixed(const Fixed &src) : _nbr(src._nbr) {}

Fixed::~Fixed() {}

// Opérateurs de comparaison
bool Fixed::operator>(const Fixed &other) const {
    return _nbr > other._nbr;
}

bool Fixed::operator<(const Fixed &other) const {
    return _nbr < other._nbr;
}

bool Fixed::operator>=(const Fixed &other) const {
    return _nbr >= other._nbr;
}

bool Fixed::operator<=(const Fixed &other) const {
    return _nbr <= other._nbr;
}

bool Fixed::operator==(const Fixed &other) const {
    return _nbr == other._nbr;
}

bool Fixed::operator!=(const Fixed &other) const {
    return _nbr != other._nbr;
}

// Opérateurs arithmétiques
Fixed Fixed::operator+(const Fixed &other) const {
    return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
    return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
    return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
    return Fixed(toFloat() / other.toFloat());
}

// Opérateurs d'incrémentation/décrémentation
Fixed &Fixed::operator++() {
    ++_nbr;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed &Fixed::operator--() {
    --_nbr;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --(*this);
    return temp;
}

// Opérateur d'assignation
Fixed &Fixed::operator=(const Fixed &src) {
    if (this != &src) {
        _nbr = src._nbr;
    }
    return *this;
}

// Fonctions statiques min et max
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

// Fonctions membres
int Fixed::getRawBits() const {
    return _nbr;
}

void Fixed::setRawBits(const int raw) {
    _nbr = raw;
}

int Fixed::toInt() const {
    return _nbr >> _bits;
}

float Fixed::toFloat() const {
    return (float)_nbr / (1 << _bits);
}

// Opérateur d'affichage
std::ostream &operator<<(std::ostream &str, const Fixed &fixed_nbr) {
    str << fixed_nbr.toFloat();
    return str;
}
