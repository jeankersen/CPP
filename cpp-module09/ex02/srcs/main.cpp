#include "PmergeMe.hpp"




// $(jot -r 10 1 100000)


int main(int argc, char* argv[])
{


    try
    {
        PmergeMe myMerge;
        clock_t startFisrtClock = clock();
        myMerge.sortVec(argc, argv);
        clock_t endFisrtClock = clock();
        double durationForVec = static_cast<double>(endFisrtClock - startFisrtClock) / CLOCKS_PER_SEC;
        clock_t startSecondClock = clock();
        std::cout << BLUE <<  "Time to process a range of: " << argc- 1 << " elements " << durationForVec * 1000000 << " microseconds" << std::endl;
        myMerge.sortDeq(argc, argv);
        clock_t endSecondClock = clock();
        double durationForDeq = static_cast<double>(endSecondClock - startSecondClock) / CLOCKS_PER_SEC;
        std::cout << "Time to process a range of: " << argc - 1 << " elements " << durationForDeq * 1000000 << " microseconds" << RESET << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}

