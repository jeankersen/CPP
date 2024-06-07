/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:58:49 by jvillefr          #+#    #+#             */
/*   Updated: 2024/06/07 13:55:06 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/ShrubberyCreationForm.hpp"

const std::string COLOR_ORANGE = "\033[38;5;208m";   // Orange
const std::string COLOR_BACK = "\033[0m";            // Black
const std::string COLOR_GREEN = "\033[38;5;70m";     // Green
const std::string COLOR_RED = "\033[38;5;196m";      // Red


ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137)
{
    std::cout << COLOR_GREEN <<  "Default  ShrubberyCreationForm constructor called " << COLOR_BACK << std::endl;
   this->Target = "Default ShrubberyCreationForm";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string Target): AForm("ShrubberyCreationForm", 145, 137)
{
    std::cout << COLOR_GREEN <<  "Constructor ShrubberyCreationForm witht args " << "." << COLOR_BACK <<  std::endl;
    this->Target = Target;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src) 
{
    if(this != &src)
        this->Target = src.Target;
    return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & cpy): AForm("RobotomyRequestForm", 72, 45)
{
    std::cout << COLOR_GREEN << "ShrubberyCreationForm with copy" <<  COLOR_BACK << std::endl;
    *this = cpy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << COLOR_RED << getName() << " :ShrubberyCreationForm deleted!" << COLOR_BACK << std::endl;
}

void ShrubberyCreationForm::action() const
{
    std::ofstream outFile(this->Target + "_shrubbery");
    if (!outFile) 
	{
        std::cerr << "can't open/create" << this->Target + "_shrubbery" << std::endl;
        return ;
    }
    outFile << 
    "                             :--:::.                ..................\n"
    "                         .-=+***#####*#+-:..          ................\n"
    "                     .--=**##%#######%#####*=..       ................\n"
    "                  .-++**#%%%###%###%%##%%%###%+==-.   ................\n"
    "              .-++###*##%@%#%%%%#%%%%%%@@%%%%%%###*:..................\n"
    "           :-=*###***##%%%%%*#%%%%%%%@%%%@@@@@%%%##%#*-...............\n"
    "         :***###*#%%###%%#%%#%%%@@@@%%@@@%%@@@%%%@@@@%##=.............\n"
    "       :=***####%%%%##%%%#%%%@%@@@@@@@@@@@@%%%%%%%@@@%#%###*=:........\n"
    "    .:-*##*##%%%%%%%%%@@%%%%@%@@@@@@@@@@@@@@@@@@%@@%%%@%%@%%%#=:......\n"
    "   .=*####%@%##%%%%%@%#%#%%@@@@@@@@%%%@%@@@@@%@@@%%#%#%%%%%%%%%#=:....\n"
    "  .=*##%##%%@##%%%%%%%%%@@%%%@@%%%%%%%%@@@@%%%%@@%%%@@%%%%%%%%%%@%+...\n"
    " -*#####%%##*#%%%%%%@@@@@@@%%%%@%%%%%%%%%%%@%%@%%%@%@@%%%%%%%%@%%%%+..\n"
    ".+####%%###%%%%%%%%@@@@@@%%%%%%%%#%%%##%%%#%%%%%@@@@@@@@@@@%@%%%%%@%#.\n"
    " .=###*#%#%%%%@%%%%%@@@@%%%%%###=+*####%%%%%#%%%%%@@@%@@@@@@@@%%@@%%%%-\n"
    " .=###%@%%%%%@%%%%#%@%%%#%%+-##+-+##%##%%%#%#####%%%%%@@@@@@@@@%@@@%*:\n"
    "  .+###%%%%%%%%%%%##%%##+=====+*####%##%%##*##*#%%=+#%%%@@%@@@@@@%%%+.\n"
    "   -#%%%#%%%%#%%#*::=:.:.     .-**+*#-*%#*-*+:+*##=+%#%%%%%%%@%%%#=:..\n"
    "   .+*#**#%###%##+.            :-...*#+**=-=+*#%#-..-=#=-:*#%%%*-... .\n"
    "     :*#*+*%%#=:..                 :##+-.   .:::=:    .   -*%=+-......\n"
    "     .-+-+****:                   .**#*.                  .::.........\n"
    "         ....                   .:=#%%%%*-:..      ...................\n"
    "                          .::-+*#%%%@@@@@@@@@%#*+=--:.................\n"
    "                         -*###%%%%%%%%@@@@@@@@@@@@@@%%#*-.............\n"
    "                  ........====++***########%%%%%%%%####*..............\n"
    "..........................:==+++*****##########%%%%%%%#=..............\n"
    "................:::::::::::-==++****#####%%%%%%%%@@@@%#-----::::::::::\n"
    "..................::::::::------=====+++++*************+------::::::::\n"
    ".........................:::::::::::--------------------::::::::::::::\n"
    << std::endl;
}




AForm * ShrubberyCreationForm::clone(std::string target)
{
   return new ShrubberyCreationForm(target);
}
