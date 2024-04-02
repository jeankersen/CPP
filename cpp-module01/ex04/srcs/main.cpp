#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

/*
void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', advance start_pos to avoid infinite loop
    }
}

int main () {
    std::ifstream infile("filename.txt", std::ios::binary);
    std::ofstream outfile("filename1.replace", std::ios::binary | std::ios::trunc);

    if (infile.is_open() && outfile.is_open()) {
        std::string content((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());

        replaceAll(content, "chat", "ELEPHANT");

        outfile << content;
        std::cout << "File replaced successfully!" << std::endl;

        infile.close();
        outfile.close();
    } else {
        std::cerr << "Unable to open file(s)!" << std::endl;
    }

    return 0;
}


*/


#include <iostream>
#include <fstream>
#include <string>

void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Avance start_pos pour éviter une boucle infinie si 'to' contient 'from'
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    const std::string filename = argv[1];
    const std::string s1 = argv[2];
    const std::string s2 = argv[3];

    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Error: Unable to open input file: " << filename << std::endl;
        return 1;
    }

    std::ofstream outfile(filename + ".replace");
    if (!outfile) {
        std::cerr << "Error: Unable to create output file: " << filename << ".replace" << std::endl;
        return 1;
    }

    std::string content((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
    replaceAll(content, s1, s2);

    outfile << content;

    std::cout << "Replacement completed successfully!" << std::endl;

    return 0;
}
