 	

// reading an entire binary file



#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
size_t findp(std::string str, size_t i)
{
    size_t pos = str.find("chat", i);
        if (pos != std::string::npos) {
             i = pos;
             return i;
        } else {
            return -1;
         }
}


std::string replAll(std::string str)
{
    std::string str1 = "";

    size_t size = str.size();
    size_t i = 0;

    i = findp(str, 0);
    std::cout << i << std::endl;
    i = 0;
    size_t j = 0;
    while(i < size)
    {
        j = findp(str, i);
        std::cout << j << std::endl;
        if(j >= 0 && j <= size)
        {
            while( i < j && i < size)
            {
                str1.append(1, str[i]);
                i++;
            }
            i += 4;
            str1.append("AAAAAAAAAAAAAAAAAAAAA");
        }
        else
        {
            while(i < size)
            {
                str1.append(1, str[i]);
                i++;
            }
        }
    }
    
    return str1;
}

std::string readFileToString(const std::string& filename) {
    std::ifstream infile(filename); // Open the input file for reading
    std::stringstream buffer;
    std::string line;

    if (infile.is_open()) {
        while (std::getline(infile, line)) { // Read each line from the input file
            buffer << line << std::endl; // Append the line to the stringstream
        }
        infile.close(); // Close the input file after reading
    } else {
        std::cerr << "Error: Unable to open the file '" << filename << "' for reading." << std::endl;
    }

    return buffer.str(); // Convert the stringstream to a string and return it
}

void writeStringToFile(const std::string& filename, const std::string& content) {
    std::ofstream outfile(filename); // Open the output file for writing

    if (outfile.is_open()) {
        outfile << content; // Write the content to the output file
        outfile.close(); // Close the output file after writing
        std::cout << "Contents have been written to the file '" << filename << "'." << std::endl;
    } else {
        std::cerr << "Error: Unable to open the file '" << filename << "' for writing." << std::endl;
    }
}

int main() {
    std::string inputFilename = "filename.txt";
    std::string outputFilename = "output.txt";

    // Read the contents of the input file
    std::string fileContent = readFileToString(inputFilename);
    std::string fileRep = replAll(fileContent);
    // Write the file content to the output file
    writeStringToFile(outputFilename, fileRep);

    return 0;
}





 
/*

#include <iostream>
#include <string>

size_t findp(std::string str, size_t i)
{
    size_t pos = str.find("is", i);
        if (pos != std::string::npos) {
             i = pos;
             return i;
        } else {
            return -1;
         }
}

std::string replAll(std::string str)
{
    std::string str = "";

    size_t size = str.size();
    size_t i = 0;

    i = findp(str, 0);
    std::cout << i << std::endl;
    i = 0;
    size_t j = 0;
    while(i < size)
    {
        j = findp(str, i);
        std::cout << j << std::endl;
        if(j >= 0 && j <= size)
        {
            while( i < j && i < size)
            {
                str1.append(1, str[i]);
                i++;
            }
            i += 2;
            str1.append("Bid");
        }
        else
        {
            while(i < size)
            {
                str1.append(1, str[i]);
                i++;
            }
        }
    }
    
    return str;
}

int main() {
    // Define a string
    std::string str = "Hello, world! This is a world string. world";
    std::string str1;

    size_t size = str.size();
    size_t i = 0;

    i = findp(str, 0);
    std::cout << i << std::endl;
    i = 0;
    size_t j = 0;
    while(i < size)
    {
        j = findp(str, i);
        std::cout << j << std::endl;
        if(j >= 0 && j <= size)
        {
            while( i < j && i < size)
            {
                str1.append(1, str[i]);
                i++;
            }
            i += 2;
            str1.append("Bid");
        }
        else
        {
            while(i < size)
            {
                str1.append(1, str[i]);
                i++;
            }
        }
    }
    
    std::cout << str1 << std::endl;

    return 0;
}

*/