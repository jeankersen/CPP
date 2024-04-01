/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookMenu.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:03:02 by jvillefr          #+#    #+#             */
/*   Updated: 2024/03/29 16:09:46 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBookUtils.hpp"
#include "PhoneBookClass.hpp"

void DisplaySingleContact(PhoneBook &phone, std::string index)
{
    std::string fname, lname, nname, nbr, secret;

    std::cout << "First Name: " << phone.Cons[index[0] - 1 - '0'].get_fname() << std::endl;
    std::cout << "Last Name: " << phone.Cons[index[0] - 1 - '0'].get_lname() << std::endl;
    std::cout << "Nickame: " << phone.Cons[index[0] - 1 - '0'].get_nname() << std::endl;
    std::cout << "Phone Number: " << phone.Cons[index[0] - 1 - '0'].get_nbr() << std::endl;
    std::cout << "Darkest Secret: " << phone.Cons[index[0] - 1 - '0'].get_secret() << std::endl;
}

void MenuSearch(PhoneBook &phone)
{
    std::string index;
    while(!std::cin.eof())
    {
        std::cout << "Select an index: " << std::endl;
        if(std::getline(std::cin, index) && index != "")
        {
            if(index.size() == 1 && index[0] >= '1' && index[0] - '0' <= phone.index)
            {
                DisplaySingleContact(phone, index);
                break;
            }
            else
                std::cout << "Invalid index!" << std::endl;
        }
    }
    std::cout << std::endl;
    FirstMenu();
}

void DisplayContact(PhoneBook &phone, int i)
{
    std::string index, fname, lname, nname, nbr, secret;

    index = AddSpaces(8) + std::to_string(i + 1) + "_";
    fname = AddSpaces(10 - phone.Cons[i].get_fname_short().size()) + phone.Cons[i].get_fname_short();
    lname = AddSpaces(10 - phone.Cons[i].get_lname_short().size()) + phone.Cons[i].get_lname_short();
    nname = AddSpaces(10 - phone.Cons[i].get_nname_short().size()) + phone.Cons[i].get_nname_short();

    std::cout << "|" << index << "|" << fname << "|" << lname << "|" << nname << "|" << std::endl;
}

void DisplayContactBoard(PhoneBook &phone)
{
    std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
    for(int i = 0; i < phone.index; i++)
        DisplayContact(phone, i);
    std::cout << " ------------------------------------------- " << std::endl;
    std::cout << std::endl;
}

void OptionSearch(PhoneBook &phone)
{
    ClearConsole();
    if(phone.index <= 0)
    {
        std::cout << "No contacts found !" << std::endl;
        FirstMenu();
    }
    else
    {
        DisplayContactBoard(phone);
        MenuSearch(phone);
    }
}

std::string FillForm(std::string Msg)
{
    std::string  name;
    std::cout << Msg << std::endl;
    std::getline(std::cin, name);
    if(std::cin.eof())
        exit(1);
    CheckEntry(name, Msg);
    return name;
}

void SetAndSWitch(PhoneBook &phone, std::string &fname, std::string &lname, std::string &nname, std::string &nbr, std::string &secret)
{
    int k = 7;
    while( k >= 1)
    {
        phone.Cons[k].set_fname(phone.Cons[ k -1].get_fname());
        phone.Cons[k].set_lname(phone.Cons[ k -1].get_lname());
        phone.Cons[k].set_nname(phone.Cons[ k -1].get_nname());
        phone.Cons[k].set_nbr(phone.Cons[ k -1].get_nbr());
        phone.Cons[k].set_secret(phone.Cons[ k -1].get_secret());
        k--;
    }
        phone.Cons[0].set_fname(fname);
        phone.Cons[0].set_lname(lname);
        phone.Cons[0].set_nname(nname);
        phone.Cons[0].set_nbr(nbr);
        phone.Cons[0].set_secret(secret);
}

void SetNames(PhoneBook &phone, std::string &fname, std::string &lname, std::string &nname, std::string &nbr, std::string &secret)
{
    int i = phone.index;
    phone.Cons[i].set_fname(fname);
    phone.Cons[i].set_lname(lname);
    phone.Cons[i].set_nname(nname);
    phone.Cons[i].set_nbr(nbr);
    phone.Cons[i].set_secret(secret);
    phone.index++;
    std::cout << "First name: " << phone.Cons[i].get_fname() << std::endl;
    std::cout << "Last name: " << phone.Cons[i].get_lname() << std::endl;
    std::cout << "Nickname: " << phone.Cons[i].get_nname() << std::endl;
    std::cout << "Phone number: " << phone.Cons[i].get_nbr() << std::endl;
    std::cout << "Darkest secret: " << phone.Cons[i].get_secret() << std::endl;
    std::cout << std::endl;
    std::cout << "contact set!" << std::endl;
}

void OptionAdd(PhoneBook &phone)
{
    std::string fname, lname, nname, nbr, secret;
    int i, k;

    k = 7;
    i = phone.index;
    fname = FillForm("Enter first name: ");
    lname = FillForm("Enter last name: ");
    nname = FillForm("Enter nickname");
    nbr = FillForm("Enter phone numer");
    secret = FillForm("Enter darkest secret");

    ClearConsole();

    RipSpace(fname);
    RipSpace(lname);
    RipSpace(nname);
    RipSpace(nbr);
    RipSpace(secret);
    if(i > 7)
        SetAndSWitch(phone, fname, lname, nname, nbr, secret);
    else
        SetNames(phone, fname, lname, nname, nbr, secret);
    FirstMenu();
}

void CheckEntry(std::string &fname, std::string Msg)
{
    while(fname.empty() || OnlySpace(fname))
    {
        std::cout << "Cannot be empty !" << std::endl;
        std::cout << Msg << std::endl;
        std::getline(std::cin, fname);
        if(std::cin.eof())
            exit(1);
    }
}