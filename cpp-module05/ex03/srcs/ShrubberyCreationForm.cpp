/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:58:49 by jvillefr          #+#    #+#             */
/*   Updated: 2024/06/04 16:59:38 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"

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


ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137)
{
    std::cout << COLOR_GREEN <<  "Default  ShrubberyCreationForm constructor called " << COLOR_BACK << std::endl;
    this->Target = "Default AForm";
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
    return (new ShrubberyCreationForm(target));
}
