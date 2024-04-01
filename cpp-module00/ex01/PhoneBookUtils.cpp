/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookUtils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:03:14 by jvillefr          #+#    #+#             */
/*   Updated: 2024/03/29 16:10:01 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBookUtils.hpp"
#include "PhoneBookClass.hpp"

bool IsNumber(char c)
{
    return (c >= '0' && c <= '9');
}

bool OnlyNumber(std::string &chaine)
{
    for (unsigned long i = 0; i < chaine.size(); i++)
    {
        if (!IsNumber(chaine[i]))
            return false; 
    }
    return true;
}

bool ValidChaine(std::string &chaine)
{
    for (unsigned long i = 0; i < chaine.size(); i++)
    {
        if (isspace(chaine[i]))
            return false; 
    }
    return true;
}

bool OnlySpace(std::string &chaine)
{
    unsigned long j = 0;
    for (unsigned long i = 0; i < chaine.size(); i++)
    {
        if ((chaine[i]) == ' ')
            j++; 
    }
    if(j == chaine.size())
        return true;
    else
        return false;
}

std::string	AddSpaces(int n)
{
	std::string	str;

	while (n--)
		str.append(" ");
	return (str);
}

void RipSpace(std::string &chaine)
{
    size_t pos = 0;
    while (pos < chaine.size() && std::isspace(chaine[pos])) {
        ++pos;
    }

    if (pos > 0) {
        chaine = chaine.substr(pos);
    }
}
