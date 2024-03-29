#include <iostream>
#include<string.h>
#include <locale>  
#include "PhoneBookClass.hpp"
#include "PhoneBookUtils.hpp"

void ClearConsole()
{
    std::cout << "\033[2J\033[1;1H" << std::endl;
}

void FirstMenu(void)
{
    std::cout << "1_ADD  2_SEARCH  3_EXIT" << std::endl;
}

void BadChoice(std::string choice)
{
    ClearConsole();
    std::cout << "Invalid command: " << choice << std::endl;
    FirstMenu();
}

int main()
{
    PhoneBook phone;
    std::string choice;
    FirstMenu();
    while(1)
    {
        std::getline(std::cin, choice);
        if(std::cin.eof())
            exit(1);
        if (choice == "1" || choice == "ADD")
            OptionAdd(phone);
        else if (choice == "2" || choice == "SEARCH")
            OptionSearch(phone);
        else if (choice == "3" || choice == "EXIT")
            break;
        else
            BadChoice(choice);
    }
    return (0);
}

/*


void OptionAdd(PhoneBook &List, int &i)
{
    int k = 7;
    std::string f_name, l_name, n_name, phone_nbr, secret;
    ClearConsole();
    std::cout << "Enter first name: ";
    std::cin >> f_name;
    if(std::cin.eof())
        exit(1);
    std::cout << "Enter last name: " << std::endl;
    std::cin >> l_name;
    if(std::cin.eof())
        exit(1);
    std::cout << "Enter nickname name: " << std::endl;
    std::cin >> n_name;
    if(std::cin.eof())
        exit(1);
    std::cout << "Enter phone number: " << std::endl;
    std::cin >> phone_nbr;
    if(std::cin.eof())
        exit(1);
    std::cout << "Enter secret: " << std::endl;
    std::cin >> secret;
    if(std::cin.eof())
        exit(1);
    if(i > 7)
    {
        while(k >= 1)
        {
            List.Cons[k].f_name = List.Cons[k - 1].f_name;
            List.Cons[k].l_name = List.Cons[k - 1].l_name;
            List.Cons[k].n_name = List.Cons[k - 1].n_name;
            List.Cons[k].phone_nbr = List.Cons[k - 1].phone_nbr;
            List.Cons[k].secret = List.Cons[k - 1].secret;
            k--;
        }
        List.Cons[0].f_name = f_name;
        List.Cons[0].l_name = l_name;
        List.Cons[0].n_name = n_name;
        List.Cons[0].phone_nbr = phone_nbr;
        List.Cons[0].secret = secret;
        ClearConsole();
        FirstMenu();
    }
    else
    {
        List.Cons[i].f_name = f_name;
        List.Cons[i].l_name = l_name;
        List.Cons[i].n_name = n_name;
        List.Cons[i].phone_nbr = phone_nbr;
        List.Cons[i].secret = secret;
        i++;
        List.index++;
        ClearConsole();
        FirstMenu();
    }
}







*/