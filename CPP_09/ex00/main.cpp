#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Hint: ./btc <file>." << std::endl;
        return 1;
    }
    
    std::ifstream input_file(argv[1]);
    if (!input_file.is_open()) {
        std::cerr << "Error: " << argv[1] << " does not exist." << std::endl;
        return 1;
    }
    
    std::ifstream data_file("data.csv");
    if (!data_file.is_open()) {
        std::cerr << "Error: data.csv does not exist." << std::endl;
        input_file.close();
        return 1;
    }
    
    if (!BitcoinExchange::validateDataFile(data_file)) {
        std::cerr << "Error: the data is incorrectly formatted" << std::endl;
        input_file.close();
        data_file.close();
        return 1;
    }
    
    std::list<BitcoinExchange> exchanges = BitcoinExchange::createExchanges(input_file, data_file);
    BitcoinExchange::printExchanges(exchanges);
    
    input_file.close();
    data_file.close();
    return 0;
}