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
        return "Error";
    }
};

template <typename Container>
Container copyContainerTemporarily(const Container& input) {
    // Créer une copie temporaire du container
    Container tempContainer = input;

    // Retourner la copie temporaire
    return tempContainer;
}


void fillVectorWithArguments(int argc, char* argv[], std::vector<int>& vec);

template <typename T>
void displayContainer(const T& container)
{
    std::cout << "Contenu du conteneur : ";
    for (typename T::size_type i = 0; i < container.size(); ++i) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
bool isSorted(const T& container)
{
    for (typename T::size_type i = 0; i < container.size() - 1; ++i) {
        if (container[i] > container[i + 1]) {
            return false;
        }
    }
    return true;
}


//void PmergeMeAlgo(std::vector<int>& vec, std::deque<int>& deq);
//void makeFirstPair(std::vector<int>& vec, std::deque<int>& deq);


template <typename Container, typename T>
void binaryInsert(Container& container, const T& element) {
    typename Container::iterator left = container.begin();
    typename Container::iterator right = container.end();

 
    while (left < right) {
        typename Container::iterator mid = left + (right - left) / 2;
        if (*mid < element) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    container.insert(left, element);
}


template <typename VecContainer, typename DeqContainer>
void makePair(VecContainer& vec, DeqContainer& deq) {
    // Check that vec has at least two elements to form a pair
    if (vec.size() < 2) return;

    // Get the first two elements
    typename VecContainer::value_type vecFirst = vec[0];
    typename VecContainer::value_type vecSecond = vec[1];

    // Remove the first two elements from vec
    vec.erase(vec.begin(), vec.begin() + 2);

    // Compare and add to deq in sorted order
    if (vecFirst > vecSecond) {
        deq.push_back(vecSecond);
        deq.push_back(vecFirst);
    } else {
        deq.push_back(vecFirst);
        deq.push_back(vecSecond);
    }
}

template <typename Container>
Container filterOddIndexes(const Container& input) {
    Container result;

    for (size_t i = 1; i < input.size(); i += 2) {  
        result.push_back(input[i]);
    }

    //  indices impairs
    return result;
}

template <typename Container>
Container filterEvenIndexes(const Container& input) {
    Container result;

    for (size_t i = 0; i < input.size(); i += 2) {  
        result.push_back(input[i]);
    }

    // ppairs
    return result;
}

template <typename VecContainer, typename DeqContainer>
void PmergeMeAlgo(VecContainer& vec, DeqContainer& deq)
{
    size_t size = vec.size();
    if (isSorted(vec))
        return;

    if (size % 2 != 0)
    {
        int nbrOfPair = (size - 1) / 2;
        typename VecContainer::value_type vecFirst = vec[0];
        vec.erase(vec.begin());

        while (nbrOfPair > 0)
        {
            makePair(vec, deq);
            nbrOfPair--;
        }

        if (isSorted(deq))
        {
            binaryInsert(deq, vecFirst);
            return;
        }
        else
        {
            DeqContainer temp =  copyContainerTemporarily(deq);
            deq.clear();
            deq = filterOddIndexes(temp);

            PmergeMeAlgo(deq, vec); // This recursive call appears correct.
        }
    }
    else
    {
        int nbrOfPair = size / 2;
        while (nbrOfPair > 0)
        {
            makePair(vec, deq);
            nbrOfPair--;
        }

        if (isSorted(deq))
        {
            return;
        }
        else
        {
            PmergeMeAlgo(deq, vec); // This recursive call appears correct.
        }
    }
}

#endif