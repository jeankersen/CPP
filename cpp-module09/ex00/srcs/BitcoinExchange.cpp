#include "BitcoinExchange.hpp"

std::map<std::string, float> mappingFile(std::ifstream& file) {
    std::map<std::string, float> data;

    if (!file.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier" << std::endl;
        return data;  
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        // Trouver la position de la virgule pour séparer la date et la valeur
        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos) {
            std::cerr << RED << "Format de ligne invalide: " << line  << RESET<< std::endl;
            continue;
        }

        std::string date = line.substr(0, commaPos);
        std::string valueStr = line.substr(commaPos + 1);

        if(!isValidDate(date)){
            std::cerr << RED << "Non valid data base format for date: " << date  << RESET << std::endl;
            continue;
        }

        std::istringstream valueStream(valueStr);
        float value = 0.0;
        valueStream >> value;

        if (valueStream.fail()) {
            std::cerr <<  YELLOW << "WARNING: Bad line format for line" << date << ": " << valueStr <<  " in data.csv file!" << RESET << std::endl;
            continue;
        }

        data[date] = value;
    }

    return data;
}

void findDataBaseDate(std::map<std::string, float> data, std::string searchDate, float inputValue) {

    if (data.empty())
    {
        std::cerr << "Erreur : aucune donnée chargée depuis le fichier." << std::endl;
        return ;
    }
    std::map<std::string, float>::iterator it = data.lower_bound(searchDate);
    if (it != data.end() && it->first == searchDate) {
        // La date exacte a été trouvée
        std::cout << GREEN << searchDate << " => " <<  inputValue << " = " << it->second * inputValue << RESET << std::endl;
    } else {
        // Si la date exacte n'est pas trouvée, chercher la date inférieure la plus proche
        if (it != data.begin()) {
            --it;  // Aller à l'élément précédent
            std::cout <<  searchDate << " => " <<  inputValue << " = " << it->second * inputValue <<  std::endl;
        } else {
            std::cout <<  BLUE << "Aucune date inférieure disponible dans les données. GOOD TRY...AHA HA SEE YAAA! :-)" << RESET <<  std::endl;
        }
    }
}

bool isValidDate(const std::string& date) {
    // Simple validation format YYYY-MM-DD
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') return false;
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

void bitcoinValue(std::ifstream& fileData, std::ifstream& inputFile)
{
    std::string line, date, value,  separator;
    float floatValue;
    std::map<std::string, float> mapData;
    mapData = mappingFile(fileData);
    getline(inputFile, line);
    while(getline(inputFile, line))
    {
        try
        {
            std::istringstream myStream(line); //streaming my line
            myStream >> date >> separator >> value;
            std::istringstream iss(value);
            if (!(isValidDate(date)))
                throw std::runtime_error("Error: Bad input for date: " + date);
            if(separator.size() != 1 && separator != "|")
                throw std::runtime_error("Error: Date and value must be separated with |");
            if (!(iss >> floatValue) || !(iss.eof()))
                throw std::runtime_error("Error: Not a valid number.");
            if( floatValue < 0.0)
                throw std::runtime_error("Error: Not a positive number.");
            if (floatValue > 1000.0)
                throw std::runtime_error("Error: Number too large.");
            findDataBaseDate(mapData, date, floatValue);

        }
        catch(const std::exception& e)
        {
            std::cerr << RED <<  e.what() << RESET <<  '\n';
        }
    }

    inputFile.close();
    fileData.close();
}




