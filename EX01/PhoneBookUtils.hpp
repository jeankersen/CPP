#ifndef PHONEBOOKUTILS_HPP
# define PHONEBOOKUTILS_HPP

#include <iostream>
#include<string.h>
#include <locale>  

#include "PhoneBookClass.hpp"

bool IsNumber(char c);

bool OnlyNumber(std::string &chaine);

bool ValidChaine(std::string &chaine);

bool OnlySpace(std::string &chaine);

std::string	add_spaces(int n);

void RipSpace(std::string &chaine);

void MenuSearch(PhoneBook &phone);
void OptionSearch(PhoneBook &phone);

void OptionAdd(PhoneBook &phone);
void BadChoice(std::string choice);

void ClearConsole();
void CheckEntry(std::string &fname, std::string Msg);


void FirstMenu(void);

#endif