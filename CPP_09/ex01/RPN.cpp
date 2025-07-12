#include "RPN.hpp"

// Canonical form implementation
RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

// Private helper methods
bool RPN::isOperator(const std::string& token) const {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool RPN::isValidNumber(const std::string& token) const {

    char* end;
    long value = std::strtol(token.c_str(), &end, 10);
    
    return end != token.c_str() && *end == '\0' && value >= 0 && value <= 9;
}

bool RPN::processOperator(const std::string& op, int& result) {
    if (_stack.size() < 2) {
        return false;
    }
    
    int operand2 = _stack.top();
    _stack.pop();
    int operand1 = _stack.top();
    _stack.pop();
    
    if (op == "+") {
        result = operand1 + operand2;
    } else if (op == "-") {
        result = operand1 - operand2;
    } else if (op == "*") {
        result = operand1 * operand2;
    } else if (op == "/") {
        if (operand2 == 0) {
            return false; // Division by zero
        }
        result = operand1 / operand2;
    }
    
    return true;
}

bool RPN::processNumber(const std::string& token, int& result) {
    if (!isValidNumber(token)) {
        return false;
    }
    
    result = std::strtol(token.c_str(), NULL, 10);
    return true;
}

// Main calculation method
bool RPN::calculate(const std::string& expression, int& result) {
    std::istringstream stream(expression);
    std::string token;
    
    while (stream >> token) {
        if (isOperator(token)) {
            if (!processOperator(token, result)) {
                return false;
            }
        } else {
            if (!processNumber(token, result)) {
                return false;
            }
        }
        _stack.push(result);
    }
    
    if (_stack.size() != 1) {
        return false;
    }
    
    result = _stack.top();
    return true;
}

// Static utility function for backward compatibility
bool RPN::evaluate(const std::string& expression, int& result) {
    RPN calculator;
    return calculator.calculate(expression, result);
}