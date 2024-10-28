#include <iostream>
#include <cstdlib>
#include <ctime>

// ANSI color codes
#define YLL "\033[33m" // Yellow
#define WHT "\033[0m"   // Reset
#define  GRN "\033[38;5;70m"    // Green
#define RED  "\033[38;5;196m"     // Red

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void delay(int milliseconds) {
    clock_t endTime = clock() + milliseconds * CLOCKS_PER_SEC / 1000;
    while (clock() < endTime) {}
}


Base* generate() {

    int randomNumber;
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generate a random delay
    delay(300);
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    randomNumber = std::rand() % 3;
    switch (randomNumber) {
        case 0: {
            std::cout << RED << "Object created as A Class" << WHT << std::endl;
            return new A();
        } 
        case 1: {
             std::cout << RED << "Object created as B Class" << WHT << std::endl;
            return new B();
        }
            
        case 2: {
            std::cout << RED << "Object created as C Class" << WHT << std::endl;
            return new C();
        } 
    }
    return nullptr;
}

void identify(Base *p) {
    if (A *ptrA = dynamic_cast<A*>(p)) {
       std::cout << "A" << std::endl;
    } else if (B *ptrB = dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (C *ptrC = dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown" << std::endl;
    }
}

// take a Base object and try to dynamic cast it
void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    } catch (const std::bad_cast& e) {}
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    } catch (const std::bad_cast& e) {}
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    } catch (const std::bad_cast& e) {}
}




int main(void) {

    std::cout << YLL << "Generating 5 random base classes using generate()" << WHT << std::endl;
    Base *randomBase1 = generate();
    Base *randomBase2 = generate();
    Base *randomBase3 = generate();
    Base *randomBase4 = generate();
    Base *randomBase5 = generate();

    std::cout << std::endl;
    std::cout << GRN << "USING POINTER VERSION" << WHT << std::endl;
    std::cout << YLL << "identifying randomBase1" << WHT << std::endl;
    identify(randomBase1);
    std::cout << YLL << "identifying randomBase2" << WHT << std::endl;
    identify(randomBase2);
    std::cout << YLL << "identifying randomBase3" << WHT << std::endl;
    identify(randomBase3);
    std::cout << YLL << "identifying randomBase4" << WHT << std::endl;
    identify(randomBase4);
    std::cout << YLL << "identifying randomBase5" << WHT << std::endl;
    identify(randomBase5);

    std::cout << std::endl;
    std::cout << GRN << "USING NON POINTER VERSION" << WHT << std::endl;
    std::cout << YLL << "identifying randomBase1" << WHT << std::endl;
    identify(*randomBase1);
    std::cout << YLL << "identifying randomBase2" << WHT << std::endl;
    identify(*randomBase2);
    std::cout << YLL << "identifying randomBase3" << WHT << std::endl;
    identify(*randomBase3);
    std::cout << YLL << "identifying randomBase4" << WHT << std::endl;
    identify(*randomBase4);
    std::cout << YLL << "identifying randomBase5" << WHT << std::endl;
    identify(*randomBase5);

    return 0;
}
