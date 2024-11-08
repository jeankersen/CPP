#include "PmergeMe.hpp"




int main(int argc, char* argv[])
{
    if(argc <= 1)
    {
        std::cout << "Error format" << std::endl;
        return 0;
    }
    std::vector<int> myVec;
    std::deque<int> myDeq;
    try
    {

        fillVectorWithArguments(argc, argv, myVec);
        if(!isSorted(myVec))
            PmergeMeAlgo(myVec, myDeq);
        std::cout << "deq" << std::endl;
        displayContainer(myDeq);
        std::cout << std::endl;
        std::cout << "vec" << std::endl;
        displayContainer(myVec);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
