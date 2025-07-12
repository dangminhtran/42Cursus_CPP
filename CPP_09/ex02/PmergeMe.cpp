#include "PmergeMe.hpp"

// Canonical form implementation
PmergeMe::PmergeMe() : vector_time_(0), deque_time_(0) {}

PmergeMe::PmergeMe(const PmergeMe& other) 
    : vector_sequence_(other.vector_sequence_), 
      deque_sequence_(other.deque_sequence_),
      vector_sorted_(other.vector_sorted_), 
      deque_sorted_(other.deque_sorted_),
      vector_time_(other.vector_time_), 
      deque_time_(other.deque_time_) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        vector_sequence_ = other.vector_sequence_;
        deque_sequence_ = other.deque_sequence_;
        vector_sorted_ = other.vector_sorted_;
        deque_sorted_ = other.deque_sorted_;
        vector_time_ = other.vector_time_;
        deque_time_ = other.deque_time_;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

// Private helper methods
std::vector<int> PmergeMe::generateJacobsthalSequence(int n) {
    std::vector<int> jacobsthal;
    
    jacobsthal.push_back(0);
    if (n == 0) return jacobsthal;
    
    jacobsthal.push_back(1);
    if (n <= 3) return jacobsthal;
    
    jacobsthal.push_back(3);
    
    int next;
    while (true) {
        size_t size = jacobsthal.size();
        next = jacobsthal[size - 1] + 2 * jacobsthal[size - 2];
        if (next > n) break;
        jacobsthal.push_back(next);
    }
    
    return jacobsthal;
}

std::vector<int> PmergeMe::getInsertionOrder(const std::vector<int>& jacobsthal_seq, size_t n) const {
    std::vector<int> order;
    
    for (size_t i = 0; i < jacobsthal_seq.size(); ++i) {
        order.push_back(jacobsthal_seq[i]);
        for (int j = jacobsthal_seq[i] - 1; j > jacobsthal_seq[i - 1]; --j) {
            order.push_back(j);
        }
    }
    
    for (size_t i = jacobsthal_seq[jacobsthal_seq.size() - 1] + 1; i < n; ++i) {
        order.push_back(static_cast<int>(i));
    }
    
    return order;
}

long PmergeMe::measureTime(const struct timeval& start, const struct timeval& end) const {
    long seconds = end.tv_sec - start.tv_sec;
    long micros = end.tv_usec - start.tv_usec;
    return seconds * 1000000 + micros;
}

template <typename Container>
void PmergeMe::printSequence(const Container& sequence, const std::string& prefix) const {
    std::cout << prefix << ": ";
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i];
        if (i != sequence.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

// Public methods
bool PmergeMe::parseInput(char** argv) {
    for (int i = 1; argv[i] != NULL; ++i) {
        std::string token(argv[i]);
        
        if (token.size() > 11) {
            return false;
        }
        
        char* end;
        long number = std::strtol(token.c_str(), &end, 10);
        
        if (*end != '\0' || number < 0 || number > INT_MAX) {
            return false;
        }
        
        int value = static_cast<int>(number);
        vector_sequence_.push_back(value);
        deque_sequence_.push_back(value);
    }
    
    return true;
}

void PmergeMe::sortAndBenchmark() {
    struct timeval start, end;
    
    // Vector sorting and benchmarking
    std::cout << "----------vector----------" << std::endl;
    
    gettimeofday(&start, NULL);
    vector_sorted_ = mergeInsertionSort(vector_sequence_);
    gettimeofday(&end, NULL);
    vector_time_ = measureTime(start, end);
    
    printSequence(vector_sequence_, "Before");
    printSequence(vector_sorted_, "After ");
    std::cout << "Time: " << vector_time_ << " µs" << std::endl;
    
    std::cout << "checker: " << (isValidSort(vector_sequence_, vector_sorted_) ? "OK" : "KO") << std::endl;
    
    // Deque sorting and benchmarking
    std::cout << "----------deque----------" << std::endl;
    
    gettimeofday(&start, NULL);
    deque_sorted_ = mergeInsertionSort(deque_sequence_);
    gettimeofday(&end, NULL);
    deque_time_ = measureTime(start, end);
    
    printSequence(deque_sequence_, "Before");
    printSequence(deque_sorted_, "After ");
    std::cout << "Time: " << deque_time_ << " µs" << std::endl;
    
    std::cout << "checker: " << (isValidSort(deque_sequence_, deque_sorted_) ? "OK" : "KO") << std::endl;
}

// Template implementations
template <typename Container>
Container PmergeMe::mergeInsertionSort(Container container) {
    size_t n = container.size();
    
    // Base cases
    if (n <= 1) return container;
    
    if (n == 2) {
        if (container[0] > container[1]) {
            std::swap(container[0], container[1]);
        }
        return container;
    }
    
    // Form pairs: larger - smaller
    std::vector<std::pair<int, int> > pairs;
    bool has_odd = (n & 1);
    int odd_element = 0;
    
    if (has_odd) {
        odd_element = container.back();
        --n;
    }
    
    for (size_t i = 0; i < n; i += 2) {
        if (container[i] > container[i + 1]) {
            pairs.push_back(std::make_pair(container[i], container[i + 1]));
        } else {
            pairs.push_back(std::make_pair(container[i + 1], container[i]));
        }
    }
    
    // Recursively sort larger elements -> main chain
    Container main_chain;
    for (std::vector<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
        main_chain.push_back(it->first);
    }
    
    if (main_chain.size() > 1) {
        main_chain = mergeInsertionSort(main_chain);
    }
    
    // Create pendant chain of smaller elements
    Container pendant_chain;
    for (size_t i = 0; i < pairs.size(); ++i) {
        if (pairs[i].first == main_chain[0]) {
            main_chain.insert(main_chain.begin(), pairs[i].second);
        } else {
            pendant_chain.push_back(pairs[i].second);
        }
    }
    
    // Insert pendant elements using Jacobsthal sequence
    if (pendant_chain.size() >= 1) {
        std::vector<int> jacobsthal_seq = generateJacobsthalSequence(static_cast<int>(pendant_chain.size()));
        std::vector<int> insertion_order = getInsertionOrder(jacobsthal_seq, pendant_chain.size());
        
        for (size_t i = 0; i < pendant_chain.size(); ++i) {
            int index = insertion_order[i];
            typename Container::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), pendant_chain[index]);
            main_chain.insert(pos, pendant_chain[index]);
        }
    }
    
    // Handle odd element
    if (has_odd) {
        typename Container::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), odd_element);
        main_chain.insert(pos, odd_element);
    }
    
    return main_chain;
}

template <typename Container>
bool PmergeMe::isValidSort(const Container& original, const Container& sorted) const {
    if (original.size() != sorted.size()) {
        return false;
    }
    
    Container original_copy = original;
    std::sort(original_copy.begin(), original_copy.end());
    
    return original_copy == sorted;
}

// Explicit template instantiations for C++98 compatibility
template std::vector<int> PmergeMe::mergeInsertionSort<std::vector<int> >(std::vector<int>);
template std::deque<int> PmergeMe::mergeInsertionSort<std::deque<int> >(std::deque<int>);
template bool PmergeMe::isValidSort<std::vector<int> >(const std::vector<int>&, const std::vector<int>&) const;
template bool PmergeMe::isValidSort<std::deque<int> >(const std::deque<int>&, const std::deque<int>&) const;