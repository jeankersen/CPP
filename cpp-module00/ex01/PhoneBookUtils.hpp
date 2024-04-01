/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookUtils.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:03:23 by jvillefr          #+#    #+#             */
/*   Updated: 2024/03/29 16:10:10 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOKUTILS_HPP
# define PHONEBOOKUTILS_HPP

#include "PhoneBookClass.hpp"

#include <iostream>
#include<string.h>

//PhoneBookUtils.cpp
bool IsNumber(char c);
bool OnlyNumber(std::string &chaine);
bool ValidChaine(std::string &chaine);
bool OnlySpace(std::string &chaine);
std::string	AddSpaces(int n);
void RipSpace(std::string &chaine);

//PhoneBookMenu.cpp
void MenuSearch(PhoneBook &phone);
void OptionAdd(PhoneBook &phone);
void OptionSearch(PhoneBook &phone);
void CheckEntry(std::string &fname, std::string Msg);

// main.cpp
void ClearConsole();
void FirstMenu(void);

#endif