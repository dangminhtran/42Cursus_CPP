#include "RPN.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    int result = 0;
    std::string expression(argv[1]);
    
    if (!RPN::evaluate(expression, result)) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    std::cout << result << std::endl;
    return 0;
}