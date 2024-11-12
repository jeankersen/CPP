#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

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
#include <cctype>  

#define RED     "\033[31m"
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

std::map<std::string, float> mappingFile(std::ifstream& file);
void findDataBaseDate(std::map<std::string, float> data, std::string searchDate, float inputValue);
bool isValidDate(const std::string& date);
bool isValidValue(const std::string& valueStr, float& value);
bool isValidDate(std::string& date);
bool fisrtLineFormat(std::string& date, std::string& value);
void bitcoinValue(std::ifstream& fileData, std::ifstream& inputFile);
bool isValidInteger(const std::string &str);

bool hasTxtExtension(char* argv[]);
bool isFileEmpty(std::ifstream& file);

int printError(const std::string& message);
int checkFiles(std::ifstream& dataFile, std::ifstream& inputFile, char *argv[]);
#endif