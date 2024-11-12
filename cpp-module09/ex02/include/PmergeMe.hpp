#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <vector>
#include <iostream>
#include <cstdlib>
#include <exception>
#include <deque>
#include <ctime> 


#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

class InvalidArgumentException : public std::exception {
public:
    const char* what() const throw() {
        return "Error";
    }
};

class PmergeMe {

    private:
        std::vector<int> _vec;
        std::deque<int> _deq;

  
        std::deque<int>& getDeque(void);
		std::vector<int>& getVector(void);


        void insertAtBeginningVec(int value);
        void insertAtBeginningDeq(int value);

        void removeSmallValuesVec();
        void removeSmallValuesDeq();

        std::vector<int> getSmallValuesVec();
        std::deque<int> getSmallValuesDeq();

        void swap(int& a, int& b);

        void makePairSortVec();
        void makePairSortDeq();

        bool isSortedVec();
        bool isSortedDeq();

        void insertElementsDeq(const std::deque<int>& deqToPush);
        void insertElementsVec(const std::vector<int>& vecToPush);

        void insertValueDeq(int value);
        void insertValueVec(int value);

        int removeLastValueVec();
        int removeLastValueDeq();

        int removeFirstValueDeq(std::deque<int>& deq);
        int removeFirstValueVec(std::vector<int>& vec);

        int handleFirstCaseVec(int& lastValue, size_t& size);
        int handleFirstCaseDeq(int& lastValue, size_t& size);

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe& operator = (const PmergeMe& other);
        PmergeMe(const PmergeMe& other);

        int fillVectorWithArguments(int argc, char* argv[]);
        int fillDequeWithArguments(int argc, char* argv[]);
        void displayDeque();
        void PmergeAlgoForDeq();
        void PmergeAlgoForVec();
        void displayVector();
        void displayContainer();
        void sortVec(int argc, char* argv[]);
        void sortDeq(int argc, char* argv[]);
};

#endif