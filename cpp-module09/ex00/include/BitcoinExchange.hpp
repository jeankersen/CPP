#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
public:
    BitcoinExchange(const std::string& csvFilePath);
    BitcoinExchange(const BitcoinExchange& other);          // Constructeur de copie
    BitcoinExchange& operator=(const BitcoinExchange& other); // Opérateur d'affectation
    ~BitcoinExchange();                                     // Destructeur

    float getExchangeRate(const std::string& date) const;

private:
    std::map<std::string, float> exchangeRates;
    void loadExchangeRates(const std::string& csvFilePath);
};

#endif
