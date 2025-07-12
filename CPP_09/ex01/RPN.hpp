#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>

class RPN {
private:
    std::stack<int> _stack;
    
    bool isOperator(const std::string& token) const;
    bool isValidNumber(const std::string& token) const;
    bool processOperator(const std::string& op, int& result);
    bool processNumber(const std::string& token, int& result);

public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();
    
    bool calculate(const std::string& expression, int& result);
    static bool evaluate(const std::string& expression, int& result);
};

#endif