#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

BitcoinExchange::BitcoinExchange(const std::string& csvFilePath) {
    loadExchangeRates(csvFilePath);
}

// Constructeur de copie
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : exchangeRates(other.exchangeRates) {}

// Opérateur d'affectation
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        exchangeRates = other.exchangeRates;
    }
    return *this;
}

// Destructeur
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadExchangeRates(const std::string& csvFilePath) {
    std::ifstream file(csvFilePath.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file.");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date;
        float rate;
        if (ss >> date >> rate) {
            exchangeRates[date] = rate;
        }
    }
    file.close();
}

float BitcoinExchange::getExchangeRate(const std::string& date) const {
    // Utiliser un type explicite pour l'itérateur
    std::map<std::string, float>::const_iterator it = exchangeRates.lower_bound(date);
    if (it == exchangeRates.end() || (it->first != date && it != exchangeRates.begin())) {
        --it;
    }
    return it->second;
}
