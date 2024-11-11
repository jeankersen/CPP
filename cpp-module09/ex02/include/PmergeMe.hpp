#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <vector>
#include <iostream>
#include <cstdlib>
#include <exception>
#include <deque>

class InvalidArgumentException : public std::exception {
public:
    const char* what() const throw() {
        return "Error 1";
    }
};

void insertAtBeginning(std::vector<int>& vec, int value);

void removeSmallValue(std::vector<int>& vec);
void fillVectorWithArguments(int argc, char* argv[], std::vector<int>& vec);
std::vector<int> getSmallValue(const std::vector<int>& vec);

void displayVector(const std::vector<int>& vec);
void swap(int& a, int& b);
void makePairSort(std::vector<int>& vec);
bool isSorted(const std::vector<int>& vec);
void insertElements(std::vector<int>& vec, const std::vector<int>& vecToPush);
void insertValue(std::vector<int>& vec, int value);

int removeLastAndReturn(std::vector<int>& vec);
int removeFirstAndReturn(std::vector<int>& vec);
int handleFirstCase(std::vector<int>& vec, int& lastValue, size_t& size);

#endif


#include <vector>
#include <deque>
#include <stdexcept>
#include <iostream>
#include <climits>
#include <cstdlib>

class PmergeMe {
public:
    // Default constructor
    PmergeMe() {}

    // Copy constructor
    PmergeMe(const PmergeMe& other)
        : vec(other.vec), deq(other.deq) {}

    // Assignment operator
    PmergeMe& operator=(const PmergeMe& other) {
        if (this != &other) {
            vec = other.vec;
            deq = other.deq;
        }
        return *this;
    }

    // Destructor
    ~PmergeMe() {}

    // Functions for vector<int>
    void fillVectorWithArguments(int argc, char* argv[]) {
        for (int i = 1; i < argc; ++i) {
            const char* arg = argv[i];
            char* end;
            long value = std::strtol(arg, &end, 10);

            if (*end != '\0' || value > INT_MAX || value < 0) {
                throw std::invalid_argument("Invalid argument");
            }
            vec.push_back(static_cast<int>(value));
        }
    }

    void displayVector() const {
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;
    }

    void insertValueInVector(int value) {
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

    // Functions for deque<int>
    void fillDequeWithArguments(int argc, char* argv[]) {
        for (int i = 1; i < argc; ++i) {
            const char* arg = argv[i];
            char* end;
            long value = std::strtol(arg, &end, 10);

            if (*end != '\0' || value > INT_MAX || value < 0) {
                throw std::invalid_argument("Invalid argument");
            }
            deq.push_back(static_cast<int>(value));
        }
    }

    void displayDeque() const {
        for (size_t i = 0; i < deq.size(); ++i) {
            std::cout << deq[i] << " ";
        }
        std::cout << std::endl;
    }

    void insertValueInDeque(int value) {
        int left = 0;
        int right = deq.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (deq[mid] < value) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        deq.insert(deq.begin() + left, value);
    }

private:
    std::vector<int> vec;
    std::deque<int> deq;
};
