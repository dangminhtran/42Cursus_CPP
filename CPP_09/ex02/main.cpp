#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: Invalid number of arguments" << std::endl;
        return 1;
    }
    
    PmergeMe sorter;
    
    if (!sorter.parseInput(argv)) {
        std::cerr << "Error: Invalid input" << std::endl;
        return 1;
    }
    
    sorter.sortAndBenchmark();
    
    return 0;
}