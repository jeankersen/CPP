#include "RPN.hpp"


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " \"expression RPN\"" << std::endl;
        return 1;
    }

    try {
        RPN calculator(argv[1]);
        double result = calculator.evaluate();
        std::cout << GREEN << result  << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
