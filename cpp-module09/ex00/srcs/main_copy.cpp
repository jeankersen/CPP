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

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << " Error: could not open file.\n";
        return 1;
    }

    const std::string inputFilePath = argv[1];
    //BitcoinExchange bitcoinExchange("data.csv");

    std::ifstream inputFile(inputFilePath.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open file.\n";
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream ss(line);
        std::string date, separator, valueStr;
        float value;

        if (!(ss >> date >> separator >> valueStr) || separator != "|" || !isValidDate(date)) {
            std::cerr << "Error: bad input => " << line << '\n';
            continue;
        }

        if (!isValidValue(valueStr, value)) {
            if (value < 0) {
                std::cerr << "Error: not a positive number.\n";
            } else {
                std::cerr << "Error: too large a number.\n";
            }
            continue;
        }

        float exchangeRate = bitcoinExchange.getExchangeRate(date);
        std::cout << date << " => " << value << " = " << (value * exchangeRate) << '\n';
    }
    return 0;
}
