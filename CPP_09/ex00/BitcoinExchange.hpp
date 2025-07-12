#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include <sstream>
#include <cstdlib>

struct Date {
    unsigned short year;
    unsigned char month;
    unsigned char day;
};

class BitcoinExchange {
private:
    std::string _date;
    float _value;
    float _rate;
    bool _isPrintable;
    std::string _errorMessage;

public:
    // Canonical form
    BitcoinExchange();
    ~BitcoinExchange();
	BitcoinExchange( const BitcoinExchange &other );
	BitcoinExchange &operator=( const BitcoinExchange &other );

    // Getters
    const std::string& getDate() const { return _date; }
    float getValue() const { return _value; }
    float getRate() const { return _rate; }
    bool isPrintable() const { return _isPrintable; }
    const std::string& getErrorMessage() const { return _errorMessage; }

    // Static validation functions
    static bool isLeapYear(unsigned short year);
    static bool isValidDate(const Date& date);
    static bool isValidDateFormat(const std::string& line, unsigned char& index);
    static bool validateDataFile(std::ifstream& data_file);
    
    // Instance methods
    bool validateInputLine(const std::string& line);
    void extractRateFromData(std::ifstream& data_file);
    void createFromInput(std::ifstream& input_file, std::ifstream& data_file);
    
    // Static factory and utility methods
    static std::list<BitcoinExchange> createExchanges(std::ifstream& input_file, std::ifstream& data_file);
    static void printExchanges(const std::list<BitcoinExchange>& exchanges);
};

#endif