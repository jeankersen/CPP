#include "PmergeMe.hpp"

#include <ctime> 

void fillVectorWithArguments(int argc, char* argv[], std::vector<int>& vec) {
    for (int i = 1; i < argc; ++i) {
        const char* arg = argv[i];
        
        char* end;
        long value = std::strtol(arg, &end, 10);

        if (*end != '\0' || value > INT_MAX || value < INT_MIN || value < 0) {
            throw InvalidArgumentException();
        }
        vec.push_back(static_cast<int>(value));
    }
}

void displayVector(const std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}


void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void makePairSort(std::vector<int>& vec) {
    for (size_t i = 0; i + 1 < vec.size(); i += 2) {
        if (vec[i] > vec[i + 1]) {
            std::swap(vec[i], vec[i + 1]);
        }
    }
}

std::vector<int> getSmallValue(const std::vector<int>& vec) {
    std::vector<int> result;
    for (size_t i = 0; i < vec.size(); i += 2) {
        result.push_back(vec[i]);
    }
    return result;
}

void removeSmallValue(std::vector<int>& vec) {
    for (int i = vec.size() - 1; i >= 0; --i) {
        if (i % 2 == 0) {
            vec.erase(vec.begin() + i);
        }
    }
}


void insertValue(std::vector<int>& vec, int value) {
    int left = 0;
    int right = vec.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] < value) {
            left = mid + 1;  
        } else {
            right = mid;  
        }
    }

    vec.insert(vec.begin() + left, value);
}


void insertElements(std::vector<int>& vec, const std::vector<int>& vecToPush) {
    for (size_t i = 0; i < vecToPush.size(); ++i)
    {
        insertValue(vec, vecToPush[i]);

    }
}

bool isSorted(const std::vector<int>& vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] < vec[i - 1]) {
            return false; 
        }
    }
    return true;  
}

int removeLastAndReturn(std::vector<int>& vec) {
    if (vec.empty()) {
        std::cerr << "Le vecteur est vide, aucune valeur à supprimer.\n";
        return 0;
    }

    int lastValue = vec.back();
    vec.pop_back();
    return lastValue;
}

int removeFirstAndReturn(std::vector<int>& vec) {
    if (vec.empty()) {
        std::cerr << "Le vecteur est vide, aucune valeur à supprimer.\n";
        return 0;
    }

    int firstValue = vec.front();
    vec.erase(vec.begin());
    return firstValue;
}

void insertAtBeginning(std::vector<int>& vec, int value) {
    vec.insert(vec.begin(), value);
}


int handleFirstCase(std::vector<int>& vec, int& lastValue, size_t& size)
{
    if(size <= 1 || isSorted(vec)) // vev <= 1 elem
        return 1;

    if(size == 2) // can rid of that maybe // vec == 2 elem
    {
        makePairSort(vec);
        return 1;
    }

    if(size % 2 != 0) // vec >= 3 elem
        lastValue = removeLastAndReturn(vec);
        
    makePairSort(vec);
    if(isSorted(vec))//  >= 3 elem
    {
        if(lastValue >= 0)
            insertValue(vec, lastValue);
        return 1;
    }
    return 0;
}



