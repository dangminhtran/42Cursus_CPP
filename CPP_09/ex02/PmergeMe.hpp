#pragma once

#include <string>
#include <iostream>
#include <cstddef>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <vector>
#include <utility>
#include <deque>
#include <sys/time.h>

class PmergeMe {
private:
    std::vector<int> vector_sequence_;
    std::deque<int> deque_sequence_;
    std::vector<int> vector_sorted_;
    std::deque<int> deque_sorted_;
    long vector_time_;
    long deque_time_;

    // Private helper methods
    static std::vector<int> generateJacobsthalSequence(int n);
    std::vector<int> getInsertionOrder(const std::vector<int>& jacobsthal_seq, size_t n) const;
    long measureTime(const struct timeval& start, const struct timeval& end) const;
    
    template <typename Container>
    void printSequence(const Container& sequence, const std::string& prefix) const;

public:
    // Canonical form
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    // Main functionality
    bool parseInput(char** argv);
    void sortAndBenchmark();
    
    // Ford-Johnson merge-insertion sort algorithm
    template <typename Container>
    Container mergeInsertionSort(Container container);
    
    template <typename Container>
    bool isValidSort(const Container& original, const Container& sorted) const;
};