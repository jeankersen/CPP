/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:02:33 by jvillefr          #+#    #+#             */
/*   Updated: 2024/03/29 16:02:42 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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