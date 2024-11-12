#include "RPN.hpp"
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <iostream>


RPN::RPN(const std::string& expression) : _expr(expression) {}


RPN::RPN(const RPN& other) : _expr(other._expr) {}


RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _expr = other._expr;
    }
    return *this;
}

RPN::~RPN() {}

// Méthode pour évaluer l'expression RPN
double RPN::evaluate() {
    std::istringstream tokens(_expr);
    std::string token;
    std::stack<double> stack;

    while (tokens >> token) {
        if (isNumber(token)) {
            double number;
            std::stringstream ss(token);
            ss >> number;
            stack.push(number);
        } else if (isOperator(token)) {
            if (stack.size() < 2) {
                throw std::runtime_error("Erreur : non valid expression");
            }

            double operand2 = stack.top();
            stack.pop();
            double operand1 = stack.top();
            stack.pop();


            stack.push(applyOperator(token, operand1, operand2));
        } else {
            throw std::runtime_error("Erreur : operator invalid");
        }
    }


    if (stack.size() != 1) {
        throw std::runtime_error("Error: bad format expression");
    }

    return stack.top();
}


bool RPN::isNumber(const std::string& token) {
    return !token.empty() && std::isdigit(token[0]);
}


bool RPN::isOperator(const std::string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}


double RPN::applyOperator(const std::string& op, double operand1, double operand2) {
    if (op == "+") return operand1 + operand2;
    if (op == "-") return operand1 - operand2;
    if (op == "*") return operand1 * operand2;
    if (op == "/") {
        if (operand2 == 0) {
            throw std::runtime_error("Erreur : cant / by 0");
        }
        return operand1 / operand2;
    }
    throw std::runtime_error("Erreur : unknow operator");
}
