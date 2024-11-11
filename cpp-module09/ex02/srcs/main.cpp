#include "PmergeMe.hpp"


void PmergeAlgo(std::vector<int>& vec)
{
    std::vector<int> smallVecValue;
    size_t size = vec.size();
    int lastValue = -1;
    int firstValue = -1;
    if(handleFirstCase(vec, lastValue, size))
        return;
    smallVecValue = getSmallValue(vec);
    removeSmallValue(vec);
    if(isSorted(vec))
    {
        firstValue = removeFirstAndReturn(smallVecValue);
        insertValue(vec, firstValue);
        insertElements(vec, smallVecValue);
        if(lastValue >= 0)
            insertValue(vec, lastValue);
    }
    else
    {
        PmergeAlgo(vec);
        insertElements(vec, smallVecValue);
        if(lastValue >= 0)
            insertValue(vec, lastValue);
    }
}

// $(jot -r 10 1 100000)


int main(int argc, char* argv[])
{
    if(argc <= 1)
    {
        std::cout << "Error format" << std::endl;
        return 0;
    }
    std::vector<int> myVec;
    try
    {
        displayVector(myVec);
        clock_t start = clock();
        fillVectorWithArguments(argc, argv, myVec);
        PmergeAlgo(myVec);
        clock_t end = clock();
        double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
        // Output the time taken
    std::cout << "Time to process: " << duration * 1000000 << " microseconds" << std::endl; // in microseconds
        displayVector(myVec);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
