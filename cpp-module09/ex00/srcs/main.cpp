#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

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

void CheckFile(std::ifstream& file)
{
    std::string line, date, value;
    char separator;
    int count = 0;

    while(getline(file, line))
    {
        try
        {
            std::istringstream myStream(line); //streaming my line
            myStream >> date >> separator >> value;
            std::cout << "line size" << line.size() << std::endl;
            if(count == 0 && line.size() == 11 && fisrtLineFormat(date, value))
                continue;
            else
                throw std::runtime_error("Error: Bad name for h");
            if (isValidDate(date) && separator ==  '|')
                std::cout << line << std::endl;
            else
                throw std::runtime_error("Error: Bad input for date: " + date);
            
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        count++;
    }

    file.close();
}

int main(int argc, char* argv[]) {

    std::string line;
    if (argc != 2) {
        std::cerr << " Error: could not open file.\n";
        return 1;
    }

  
    //BitcoinExchange bitcoinExchange("data.csv");

    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open file.\n";
        return 1;
    }
    CheckFile(inputFile);


    return 0;
}
