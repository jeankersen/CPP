#include "PmergeMe.hpp"
#include <ctime> 
#include <deque>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <climits>

void fillDequeWithArguments(int argc, char* argv[], std::deque<int>& deq) {
    for (int i = 1; i < argc; ++i) {
        const char* arg = argv[i];
        
        char* end;
        long value = std::strtol(arg, &end, 10);

        if (*end != '\0' || value > INT_MAX || value < INT_MIN || value < 0) {
            throw std::invalid_argument("Invalid argument");
        }
        deq.push_back(static_cast<int>(value));
    }
}

void displayDeque(const std::deque<int>& deq) {
    for (size_t i = 0; i < deq.size(); ++i) {
        std::cout << deq[i] << " ";
    }
    std::cout << std::endl;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void makePairSort(std::deque<int>& deq) {
    for (size_t i = 0; i + 1 < deq.size(); i += 2) {
        if (deq[i] > deq[i + 1]) {
            std::swap(deq[i], deq[i + 1]);
        }
    }
}

std::deque<int> getSmallValue(const std::deque<int>& deq) {
    std::deque<int> result;
    for (size_t i = 0; i < deq.size(); i += 2) {
        result.push_back(deq[i]);
    }
    return result;
}

void removeSmallValue(std::deque<int>& deq) {
    for (int i = deq.size() - 1; i >= 0; --i) {
        if (i % 2 == 0) {
            deq.erase(deq.begin() + i);
        }
    }
}

void insertValue(std::deque<int>& deq, int value) {
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

void insertElements(std::deque<int>& deq, const std::deque<int>& deqToPush) {
    for (size_t i = 0; i < deqToPush.size(); ++i) {
        insertValue(deq, deqToPush[i]);
    }
}

bool isSorted(const std::deque<int>& deq) {
    for (size_t i = 1; i < deq.size(); ++i) {
        if (deq[i] < deq[i - 1]) {
            return false; 
        }
    }
    return true;  
}

int removeLastAndReturn(std::deque<int>& deq) {
    if (deq.empty()) {
        std::cerr << "The deque is empty, no value to remove.\n";
        return 0;
    }

    int lastValue = deq.back();
    deq.pop_back();
    return lastValue;
}

int removeFirstAndReturn(std::deque<int>& deq) {
    if (deq.empty()) {
        std::cerr << "The deque is empty, no value to remove.\n";
        return 0;
    }

    int firstValue = deq.front();
    deq.pop_front();
    return firstValue;
}

void insertAtBeginning(std::deque<int>& deq, int value) {
    deq.push_front(value);
}

int handleFirstCase(std::deque<int>& deq, int& lastValue, size_t& size) {
    if (size <= 1 || isSorted(deq))
        return 1;

    if (size == 2) {
        makePairSort(deq);
        return 1;
    }

    if (size % 2 != 0)
        lastValue = removeLastAndReturn(deq);
        
    makePairSort(deq);
    if (isSorted(deq)) {
        if (lastValue >= 0)
            insertValue(deq, lastValue);
        return 1;
    }
    return 0;
}

void PmergeAlgo(std::deque<int>& deq) {
    std::deque<int> smallDeqValue;
    size_t size = deq.size();
    int lastValue = -1;
    int firstValue = -1;
    
    if (handleFirstCase(deq, lastValue, size))
        return;
    
    smallDeqValue = getSmallValue(deq);
    removeSmallValue(deq);
    
    if (isSorted(deq)) {
        firstValue = removeFirstAndReturn(smallDeqValue);
        insertValue(deq, firstValue);
        insertElements(deq, smallDeqValue);
        if (lastValue >= 0)
            insertValue(deq, lastValue);
    } else {
        PmergeAlgo(deq);
        insertElements(deq, smallDeqValue);
        if (lastValue >= 0)
            insertValue(deq, lastValue);
    }
}
