#include "PmergeMe.hpp"

std::deque<int>& PmergeMe::getDeque(void)
{
	return this->_deq;
}

int PmergeMe::fillDequeWithArguments(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        const char* arg = argv[i];
        
        char* end;
        long value = std::strtol(arg, &end, 10);

        if (*end != '\0' || value > INT_MAX || value < INT_MIN || value < 0) {
            throw std::invalid_argument("Invalid argument");
        }
        getDeque().push_back(static_cast<int>(value));
    }
    return 1;
}

void PmergeMe::displayDeque() {
    for (size_t i = 0; i < getDeque().size(); ++i) {
        std::cout << getDeque()[i] << " ";
    }
    std::cout << RESET <<  std::endl;
}

void PmergeMe::makePairSortDeq() {
    for (size_t i = 0; i + 1 < getDeque().size(); i += 2) {
        if (getDeque()[i] > getDeque()[i + 1]) {
            std::swap(getDeque()[i], getDeque()[i + 1]);
        }
    }
}

std::deque<int> PmergeMe::getSmallValuesDeq() {
    std::deque<int> result;
    for (size_t i = 0; i < getDeque().size(); i += 2) {
        result.push_back(getDeque()[i]);
    }
    return result;
}

void PmergeMe::removeSmallValuesDeq() {
    for (int i = getDeque().size() - 1; i >= 0; --i) {
        if (i % 2 == 0) {
            getDeque().erase(getDeque().begin() + i);
        }
    }
}

void PmergeMe::insertValueDeq(int value) {
    int left = 0;
    int right = getDeque().size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (getDeque()[mid] < value) {
            left = mid + 1;  
        } else {
            right = mid;  
        }
    }
    getDeque().insert(getDeque().begin() + left, value);
}

void PmergeMe::insertElementsDeq(const std::deque<int>& deqToPush) {
    for (size_t i = 0; i < deqToPush.size(); ++i) {
        insertValueDeq(deqToPush[i]);
    }
}

bool PmergeMe::isSortedDeq() {
    for (size_t i = 1; i < getDeque().size(); ++i) {
        if (getDeque()[i] < getDeque()[i - 1]) {
            return false; 
        }
    }
    return true;  
}

int PmergeMe::removeLastValueDeq() {
    if (getDeque().empty()) {
        std::cerr << "The deque is empty, no value to remove.\n";
        return 0;
    }

    int lastValue = getDeque().back();
    getDeque().pop_back();
    return lastValue;
}

int PmergeMe::removeFirstValueDeq(std::deque<int>& deq) {
    if (deq.empty()) {
        std::cerr << "The deque is empty, no value to remove.\n";
        return 0;
    }

    int firstValue = deq.front();
    deq.pop_front();
    return firstValue;
}

void PmergeMe::insertAtBeginningDeq(int value) {
    getDeque().push_front(value);
}



int PmergeMe::handleFirstCaseDeq(int& lastValue, size_t& size) {
    if (size <= 1 || isSortedDeq())
        return 1;

    if (size == 2) {
        makePairSortDeq();
        return 1;
    }

    if (size % 2 != 0)
        lastValue = removeLastValueDeq();
        
    makePairSortDeq();
    if (isSortedDeq()) {
        if (lastValue >= 0)
            insertValueDeq(lastValue);
        return 1;
    }
    return 0;
}

void PmergeMe::PmergeAlgoForDeq() {
    std::deque<int> smallDeqValue;
    size_t size = getDeque().size();
    int lastValue = -1;
    int firstValue = -1;
    
    if (handleFirstCaseDeq(lastValue, size))
        return;
    
    smallDeqValue = getSmallValuesDeq();
    removeSmallValuesDeq();
    
    if (isSortedDeq()) {
        firstValue = removeFirstValueDeq(smallDeqValue);
        insertValueDeq(firstValue);
        insertElementsDeq(smallDeqValue);
        if (lastValue >= 0)
            insertValueDeq(lastValue);
    } else {
        PmergeAlgoForDeq();
        insertElementsDeq(smallDeqValue);
        if (lastValue >= 0)
            insertValueDeq(lastValue);
    }
}

void PmergeMe::sortDeq(int argc, char * argv[]) {
    if(fillDequeWithArguments(argc, argv))
        PmergeAlgoForDeq();

}