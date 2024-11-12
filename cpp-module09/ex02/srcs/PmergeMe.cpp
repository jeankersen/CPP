#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){

}

PmergeMe& PmergeMe::operator = (const PmergeMe& other) {
        if (this != &other) {
            this->_vec = other._vec;
            this->_deq = other._deq;
        }
        return *this;
}
PmergeMe::PmergeMe(const PmergeMe& other): _vec(other._vec), _deq(other._deq) {}

PmergeMe::~PmergeMe() {}

int PmergeMe::fillVectorWithArguments(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        const char* arg = argv[i];
        
        char* end;
        long value = std::strtol(arg, &end, 10);

        if (*end != '\0' || value > INT_MAX || value < INT_MIN || value < 0) {
            throw InvalidArgumentException();
        }
        getVector().push_back(static_cast<int>(value));
    }
    return 1;
}


std::vector<int>& PmergeMe::getVector(void)
{
	return this->_vec;
}

void PmergeMe::displayVector() {
    for (size_t i = 0; i < getVector().size(); ++i) {
        std::cout << getVector()[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::displayContainer() {
    for (size_t i = 0; i < getVector().size(); ++i) {
        std::cout << getVector()[i] << " ";
    }
    std::cout << RESET << std::endl;
}

void PmergeMe::swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void PmergeMe::makePairSortVec() {
    for (size_t i = 0; i + 1 < getVector().size(); i += 2) {
        if (getVector()[i] > getVector()[i + 1]) {
            std::swap(getVector()[i], getVector()[i + 1]);
        }
    }
}

std::vector<int> PmergeMe::getSmallValuesVec() {
    std::vector<int> result;
    for (size_t i = 0; i < getVector().size(); i += 2) {
        result.push_back(getVector()[i]);
    }
    return result;
}

void PmergeMe::removeSmallValuesVec() {
    for (int i = getVector().size() - 1; i >= 0; --i) {
        if (i % 2 == 0) {
            getVector().erase(getVector().begin() + i);
        }
    }
}


void PmergeMe::insertValueVec(int value) {
    int left = 0;
    int right = getVector().size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (getVector()[mid] < value) {
            left = mid + 1;  
        } else {
            right = mid;  
        }
    }

    getVector().insert(getVector().begin() + left, value);
}


void PmergeMe::insertElementsVec(const std::vector<int>& vecToPush) {
    for (size_t i = 0; i < vecToPush.size(); ++i)
    {
        insertValueVec(vecToPush[i]);

    }
}

bool PmergeMe::isSortedVec() {
    for (size_t i = 1; i < getVector().size(); ++i) {
        if (getVector()[i] < getVector()[i - 1]) {
            return false; 
        }
    }
    return true;  
}

int PmergeMe::removeLastValueVec() {
    if (getVector().empty()) {
        std::cerr << "Le vecteur est vide, aucune valeur à supprimer.\n";
        return 0;
    }

    int lastValue = getVector().back();
    getVector().pop_back();
    return lastValue;
}

int PmergeMe::removeFirstValueVec(std::vector<int>& vec) {
    if (vec.empty()) {
        std::cerr << "Le vecteur est vide, aucune valeur à supprimer.\n";
        return 0;
    }

    int firstValue = vec.front();
    vec.erase(vec.begin());
    return firstValue;
}

void PmergeMe::insertAtBeginningVec(int value) {
    getVector().insert(getVector().begin(), value);
}


int PmergeMe::handleFirstCaseVec(int& lastValue, size_t& size)
{
    if(size <= 1 || isSortedVec()) // vev <= 1 elem
        return 1;

    if(size == 2) // can rid of that maybe // getVector == 2 elem
    {
        makePairSortVec();
        return 1;
    }

    if(size % 2 != 0) // getVector >= 3 elem
        lastValue = removeLastValueVec();
        
    makePairSortVec();
    if(isSortedVec())//  >= 3 elem
    {
        if(lastValue >= 0)
            insertValueVec(lastValue);
        return 1;
    }
    return 0;
}

void PmergeMe::PmergeAlgoForVec()
{
    std::vector<int> smallVecValue;
    size_t size = getVector().size();
    int lastValue = -1;
    int firstValue = -1;
    if(handleFirstCaseVec(lastValue, size))
        return;
    smallVecValue = getSmallValuesVec();
    removeSmallValuesVec();
    if(isSortedVec())
    {
        firstValue = removeFirstValueVec(smallVecValue);
        insertValueVec(firstValue);
        insertElementsVec(smallVecValue);
        if(lastValue >= 0)
            insertValueVec(lastValue);
    }
    else
    {
        PmergeAlgoForVec();
        insertElementsVec(smallVecValue);
        if(lastValue >= 0)
            insertValueVec(lastValue);
    }
}


void PmergeMe::sortVec(int argc, char* argv[]) {
    if(fillVectorWithArguments(argc, argv))
    {
        std::cout << RED <<  "Vector Before: ";
        displayVector();
        PmergeAlgoForVec();
        std::cout <<  GREEN << "Vector After: ";
        displayVector();
    }
}