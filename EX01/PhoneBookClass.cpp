#include <iostream>
#include "PhoneBookClass.hpp"
#include <iomanip>
#include<string.h>


void Contact::set_fname(std::string str)
{
    this->_fname = str;
}

void Contact::set_lname(std::string str)
{
    this->_lname = str;
}

void Contact::set_nname(std::string str)
{
    this->_nname = str;
}

void Contact::set_nbr(std::string str)
{
    this->_nbr = str;
}

void Contact::set_secret(std::string str)
{
    this->_secret = str;
}

std::string Contact::get_fname(void)
{
     return this->_fname;
}

std::string Contact::get_lname(void)
{
     return this->_lname;
}

std::string Contact::get_nname(void)
{
     return this->_nname;
}

std::string Contact::get_nbr(void)
{
     return this->_nbr;
}

std::string Contact::get_secret(void)
{
     return this->_secret;
}


void PhoneBook::set_index(int i)
{
    this->index = i;
}

int PhoneBook::get_index(void)
{
    return this->index;
}

PhoneBook::PhoneBook(void)
{
    std::cout << "Welcome to PhoneBook" << std::endl;
    this->index = 0;
}

PhoneBook::~PhoneBook(void)
{
    std::cout << "Good Bye" << std::endl;
}

std::string Contact::get_fname_short(void)
{
    std::string name;
    int size;
    size = this->_fname.size();

    if(size >= 10)
    {
       name = this->_fname.substr(0, 10);
       name[9] = '.';
        return (name);
    }
    else
    return this->_fname;
}

std::string Contact::get_lname_short(void)
{
    std::string name;
    int size;
    size = this->_lname.size();

    if(size >= 10)
    {
       name = this->_lname.substr(0, 10);
       name[9] = '.';
        return (name);
    }
    else
        return this->_lname;
}

std::string Contact::get_nname_short(void)
{
    std::string name;
    int size;
    size = this->_nname.size();

    if(size >= 10)
    {
       name = this->_nname.substr(0, 10);
       name[9] = '.';
        return (name);
    }
    else
        return this->_nname;
}

std::string Contact::get_nbr_short(void)
{
    std::string name;
    int size;
    size = this->_nbr.size();

    if(size >= 10)
    {
       name = this->_nbr.substr(0, 10);
       name[9] = '.';
        return (name);
    }
    else
        return this->_nbr;
}

std::string Contact::get_secret_short(void)
{
    std::string name;
    int size;
    size = this->_secret.size();

    if(size >= 10)
    {
       name = this->_secret.substr(0, 10);
       name[9] = '.';
        return (name);
    }
    else
        return this->_secret;
}

