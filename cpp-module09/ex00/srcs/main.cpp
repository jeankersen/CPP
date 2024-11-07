#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>  // Pour std::isdigit en C++98

void findDatabaseDate(std::ifstream& file, std::string query_date, float &f) {

    std::string line;
     std::map<std::string, int> data;

    // Lire le fichier ligne par ligne
    while (std::getline(file, line)) {
        std::string date = line.substr(0, line.find(','));
        int value = std::stoi(line.substr(line.find(',') + 1)); 
        std::cout << "date:" << date << std::endl;
        // Insérer la date et la valeur dans la map
        data[date] = value;
    }

std::cout << "date:"  << std::endl;
    // Chercher la date dans la map
    std::map<std::string, int>::iterator it = data.find(query_date);

    if (it != data.end()) {
        // Si la date est trouvée
        std::cout << query_date << " => " << f << " = " << it->second * f << std::endl;
    } else {
        // Si la date n'est pas trouvée, chercher la date précédente
        it = data.lower_bound(query_date); // Trouver la première date supérieure ou égale

        if (it != data.begin()) {
            --it;  // Aller à la date précédente
            std::cout<< it->first << "=>" << f << " = " << it->second * f << std::endl;
        } else {
            std::cout << "Pas de date précédente disponible." << std::endl;
        }
    }
}

bool isValidDate(const std::string& date) {
    // Simple validation format YYYY-MM-DD
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') return false;
    // Ajoutez une validation plus approfondie si nécessaire
    return true;
}

bool isValidValue(const std::string& valueStr, float& value) {
    try {
        value = std::stof(valueStr);
        return value >= 0.0f && value <= 1000.0f;
    } catch (...) {
        return false;
    }
}

bool isValidDate(std::string& date) {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }

    int year, month, day;
    char dash1, dash2;
    std::istringstream ss(date);

    // Extract year, month, and day, ensuring correct format with '-'
    if (!(ss >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' || dash2 != '-') {
        return false;
    }

    // Check if year, month, and day are within valid ranges
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }

    // Additional check for days in each month
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false; // April, June, September, November have 30 days
    }
    if (month == 2) {
        // Check for leap year
        bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (day > 29 || (day == 29 && !isLeapYear)) {
            return false; // February has 28 days, 29 in a leap year
        }
    }

    return true;
}

bool fisrtLineFormat(std::string& date, std::string& value)
{
    if(date == "date" && value == "value")
        return true;
    return false;
}

void CheckFile(std::ifstream& file, std::ifstream& fileData)
{
    std::string line, date, value;
    char separator;
    float f;
    //int count = 0;

    getline(file, line);
    while(getline(file, line))
    {
        try
        {
            std::istringstream myStream(line); //streaming my line
            myStream >> date >> separator >> value;
            std::istringstream iss(value);
            if (!(isValidDate(date) && separator ==  '|'))
                throw std::runtime_error("Error: Bad input for date: " + date);
            if (!(iss >> f) || !(iss.eof()))
                throw std::runtime_error("Error: Not a valid number.");
            if( f < 0.0)
                throw std::runtime_error("Error: Not a positive number.");
            if (f > 1000.0)
                throw std::runtime_error("Error: Number too large.");
            findDatabaseDate(fileData, "2010-12-02", f);

        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        //count++;
    }

    file.close();
}



// Fonction pour vérifier si une chaîne de caractères est un entier valide
bool isValidInteger(const std::string &str) {
    for (size_t i = 0; i < str.length(); ++i) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    std::map<std::string, int> data;
    std::cout << "hello 1" << std::endl;
    
    // Ouvrir le fichier dans le répertoire courant
    std::ifstream file("data.csv");  // Remplacez "data.csv" par le nom de votre fichier
    if (!file.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier" << std::endl;
        return 1;  // Retourner une erreur si le fichier ne peut pas être ouvert
    }
    std::cout << "hello 2" << std::endl;

    std::string line;
    std::string previousDate;
    int previousValue = -1;  // Valeur de la date précédente

    // Lire chaque ligne du fichier
    while (std::getline(file, line)) {
        // Séparer la date et la valeur
        size_t commaPos = line.find(',');
        std::string date = line.substr(0, commaPos);
        std::string valueStr = line.substr(commaPos + 1);

        // Vérifier si la valeur est un entier valide
        if (isValidInteger(valueStr)) {
            // Conversion de la chaîne en entier
            int value = 0;
            for (size_t i = 0; i < valueStr.length(); ++i) {
                value = value * 10 + (valueStr[i] - '0');
            }
            data[date] = value;

            // Sauvegarder la date et la valeur précédente pour l'usage futur
            previousDate = date;
            previousValue = value;
        } else {
            std::cerr << "Valeur invalide pour la date " << date << ": " << valueStr << std::endl;
        }
    }

    std::cout << "hello 3" << std::endl;

    // Date à rechercher dans le fichier
    std::string searchDate = "2009-01-12";  // Exemple de date à rechercher

    // Chercher la date dans la map
    std::map<std::string, int>::iterator it = data.find(searchDate);
    if (it != data.end()) {
        // La date est trouvée, afficher la valeur
        std::cout << "Date: " << searchDate << ", Valeur: " << it->second << std::endl;
    } else {
        // Si la date n'est pas trouvée, afficher la date précédente
        if (previousDate != "") {
            std::cout << "Date non trouvée. La date précédente était : " << previousDate << ", Valeur: " << previousValue << std::endl;
        } else {
            std::cout << "Aucune date trouvée dans le fichier." << std::endl;
        }
    }

    return 0;
}




/*

int main(int argc, char* argv[]) {



    std::string line;
    if (argc != 2) {
        std::cerr << " Error: could not open file.\n";
        return 1;
    }
    std::map<std::string, float> data;
    std::ifstream file("data.csv");

  
    //BitcoinExchange bitcoinExchange("data.csv");

    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open file.\n";
        return 1;
    }
    CheckFile(inputFile, file);


    return 0;
}
*/


