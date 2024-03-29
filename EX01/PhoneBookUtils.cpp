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
std::string	add_spaces(int n)
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

    // Effacer les espaces au début de la chaîne
    if (pos > 0) {
        chaine = chaine.substr(pos);
    }
}
