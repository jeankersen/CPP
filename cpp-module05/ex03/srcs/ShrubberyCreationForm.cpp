/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:58:49 by jvillefr          #+#    #+#             */
/*   Updated: 2024/06/10 13:13:27 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/ShrubberyCreationForm.hpp"

const std::string COLOR_ORANGE = "\033[38;5;208m";   // Orange
const std::string COLOR_BACK = "\033[0m";            // Black
const std::string COLOR_GREEN = "\033[38;5;70m";     // Green
const std::string COLOR_RED = "\033[38;5;196m";      // Red


ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137, "Default ShrubberyCreationForm")
{
    std::cout << COLOR_GREEN <<  "Default  ShrubberyCreationForm constructor called " << COLOR_BACK << std::endl;

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137, target)
{
    std::cout << COLOR_GREEN <<  getTarget() <<  ": ShrubberyCreationForm constructor witht args " << "." << COLOR_BACK <<  std::endl;

}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src)
{
    if (this != &src)
		this->setTarget(src.getTarget());
    return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & cpy): AForm("RobotomyRequestForm", 72, 45, cpy.getTarget())
{
    std::cout << COLOR_GREEN <<  getTarget()  << ": ShrubberyCreationForm with copy" <<  COLOR_BACK << std::endl;
    *this = cpy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << COLOR_RED << getTarget() << ": ShrubberyCreationForm deleted!" << COLOR_BACK << std::endl;
}

void ShrubberyCreationForm::action() const
{
    std::ofstream outFile(getTarget() + "_shrubbery");
    if (!outFile) 
	{
        std::cerr << "can't open/create" << getTarget() + "_shrubbery" << std::endl;
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