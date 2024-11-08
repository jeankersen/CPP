#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <iostream>

#define GREEN   "\033[32m"
#define RESET   "\033[0m"

class RPN {
public:
    explicit RPN(const std::string& expression);

    RPN(const RPN& other);

    RPN& operator=(const RPN& other);

    ~RPN();
    double evaluate();

private:
    std::string _expr;

    bool isNumber(const std::string& token);

    bool isOperator(const std::string& token);

    double applyOperator(const std::string& op, double operand1, double operand2);
};

#endif // RPN_HPP
