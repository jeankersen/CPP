#include "PmergeMe.hpp"



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


/*

void makeFirstPair(std::vector<int>& vec, std::deque<int>& deq)
{
    
    int vecFirst = vec[0];
    int vecSecond = vec[1];
    vec.erase(vec.begin(), vec.begin() + 2);
    if (vecFirst > vecSecond)
    {
        deq.push_back(vecSecond);
        deq.push_back(vecFirst);
        return ;
    }
    deq.push_back(vecFirst);
    deq.push_back(vecSecond);
}




void PmergeMeAlgo(std::vector<int>& vec, std::deque<int>& deq)
{
    size_t size = vec.size();
    if(size % 2 == 0)
    {
        size_t nbrOfPair = size / 2;
        while(nbrOfPair > 0)
        {
            makeFirstPair(vec, deq);
            nbrOfPair--;
        }
    }
    else
    {
        int vecFirst = vec[0];
        vec.erase(vec.begin());
        deq.push_back(vecFirst);
        size_t size = vec.size();
        size_t nbrOfPair = size / 2;
        while(nbrOfPair > 0)
        {
            makeFirstPair(vec, deq);
            nbrOfPair--;
        }
    }
}

template <typename VecContainer, typename DeqContainer>
void PmergeMeAlgo(VecContainer& vec, DeqContainer& deq)
{
    if(isSorted(vec))
        return;
    size_t size = vec.size();
    if(size % 2 != 0)
    {
        typename VecContainer::value_type vecFirst = vec[0];
        vec.erase(vec.begin());
        deq.push_back(vecFirst);
    }



    if (size % 2 == 0) {
        size_t nbrOfPair = size / 2;
        while (nbrOfPair > 0) {
            makeFirstPair(vec, deq);
            nbrOfPair--;
        }
    } else {
        
        size = vec.size();  // Update size after removing the first element
        size_t nbrOfPair = size / 2;
        while (nbrOfPair > 0) {
            makeFirstPair(vec, deq);
            nbrOfPair--;
        }
    }
}

*/