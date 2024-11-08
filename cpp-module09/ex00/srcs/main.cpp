#include "BitcoinExchange.hpp"

bool hasTxtExtension(char* argv[]) {
    std::string filename = argv[1];  

    if (filename.length() >= 4 && filename.substr(filename.length() - 4) == ".txt") {
        return true;
    }
    return false;
}
bool isFileEmpty(std::ifstream& file) {
    return file.peek() == std::ifstream::traits_type::eof();
}

int printError(const std::string& message) {
    std::cerr <<  RED << "Error: " << message << RESET << std::endl;
    return 1;
}

int checkFiles(std::ifstream& dataFile, std::ifstream& inputFile, char *argv[])
{
    if(!hasTxtExtension(argv))
        return printError("Input file must have .txt extension.");
    if (!dataFile.is_open())        
        return printError("Could not open data.csv.");
    if (!inputFile.is_open())         
        return printError("Could not open input file.");
    if(isFileEmpty(dataFile))
        return printError("File data.csv is empty. 1");
    if(isFileEmpty(inputFile))
        return printError("File input file is empty.");
    return 0;
}

int main(int argc, char* argv[]) {
    std::string line;
    if (argc != 2) {
        std::cerr << " Error: could not open file.\n";
        return 1;
    }
  
    std::ifstream dataFile("data.csv");
    std::ifstream inputFile(argv[1]);
    checkFiles(dataFile, inputFile, argv);
    bitcoinValue(dataFile, inputFile);
    return 0;
}

