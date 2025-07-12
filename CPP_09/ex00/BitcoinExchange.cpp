#include "BitcoinExchange.hpp"

// Forme canonique
BitcoinExchange::BitcoinExchange() 
    : _date("0000-00-00"), _value(0), _rate(0), _isPrintable(false), _errorMessage("None") {}

BitcoinExchange::~BitcoinExchange( void ) {}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &other ) : _date( other._date ), _value( other._value ), _rate( other._rate ), _isPrintable( other._isPrintable ), _errorMessage( other._errorMessage ) {}

BitcoinExchange &BitcoinExchange::operator=( const BitcoinExchange &other )
{
	if ( this != &other )
	{
		_date = other._date;
		_value = other._value;
		_rate = other._rate;
		_isPrintable = other._isPrintable;
		_errorMessage = other._errorMessage;
	}
	return ( *this );
}

// Static validation functions
bool BitcoinExchange::isLeapYear(unsigned short year) {
    return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

bool BitcoinExchange::isValidDate(const Date& date) {
    if (date.year <= 0 || date.month <= 0 || date.day <= 0) {
        return false;
    }
    if (date.month > 12 || date.day > 31) {
        return false;
    }
    
    // Check days in months with 30 days
    if (date.day == 31 && (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11)) {
        return false;
    }
    
    // Check February
    if (date.month == 2) {
        if (date.day > 29) return false;
        if (date.day == 29 && !isLeapYear(date.year)) return false;
    }
    
    return true;
}

bool BitcoinExchange::isValidDateFormat(const std::string& line, unsigned char& index) {
    Date date = {0, 0, 0};
    
    // Parse year (4 digits)
    for (; index < 4; ++index) {
        if (!std::isdigit(line[index])) {
            return false;
        }
        date.year = 10 * date.year + (line[index] - '0');
    }
    
    // Check first dash
    if (line[index++] != '-') {
        return false;
    }
    
    // Parse month (2 digits)
    for (; index < 7; ++index) {
        if (!std::isdigit(line[index])) {
            return false;
        }
        date.month = 10 * date.month + (line[index] - '0');
    }
    
    // Check second dash
    if (line[index++] != '-') {
        return false;
    }
    
    // Parse day (2 digits)
    for (; index < 10; ++index) {
        if (!std::isdigit(line[index])) {
            return false;
        }
        date.day = 10 * date.day + (line[index] - '0');
    }
    
    return isValidDate(date);
}

bool BitcoinExchange::validateDataFile(std::ifstream& data_file) {
    std::string line;
    
    // Check header
    std::getline(data_file, line);
    if (line != "date,exchange_rate") {
        return false;
    }
    
    // Validate each data line
    while (std::getline(data_file, line)) {
        unsigned char index = 0;
        
        // Check date format
        if (!isValidDateFormat(line, index)) {
            return false;
        }
        
        // Check comma separator
        if (line[index++] != ',') {
            return false;
        }
        
        // Validate rate value
        char* end;
        std::strtof(line.c_str() + index, &end);
        if (end == line.c_str() + index || *end != '\0') {
            return false;
        }
    }
    
    return true;
}

bool BitcoinExchange::validateInputLine(const std::string& line) {
    unsigned char index = 0;
    
    // Validate date format
    if (!isValidDateFormat(line, index)) {
        return false;
    }
    
    // Check separator " | "
    if (line[index++] != ' ' || line[index++] != '|' || line[index++] != ' ') {
        return false;
    }
    
    // Parse and validate value
    char* end;
    const char* value_str = line.c_str() + index;
    float value = std::strtof(value_str, &end);
    
    if (end == value_str || *end != '\0') {
        return false;
    }
    
    if (value < 0) {
        _errorMessage = "Error: not a positive number.";
        return false;
    }
    
    if (value > 1000) {
        _errorMessage = "Error: number too large.";
        return false;
    }
    
    // Extract date and store value
    std::istringstream ss(line);
    std::getline(ss, _date, ' ');
    _value = value;
    
    return true;
}

void BitcoinExchange::extractRateFromData(std::ifstream& data_file) {
    std::string line, date_str, rate_str;
    
    // Reset file pointer
    data_file.clear();
    data_file.seekg(0, std::ios::beg);
    std::getline(data_file, line); // Skip header
    
    // Get first data line
    std::getline(data_file, line);
    std::istringstream ss(line);
    std::getline(ss, date_str, ',');
    
    // Check if requested date is before first available date
    if (_date < date_str) {
        _errorMessage = "No exchange was made that day or before";
        return;
    }
    
    // Find appropriate rate
    while (std::getline(data_file, line)) {
        std::istringstream line_ss(line);
        std::getline(line_ss, date_str, ',');
        
        if (_date < date_str) {
            _isPrintable = true;
            return;
        }
        
        std::getline(line_ss, rate_str);
        _rate = std::strtof(rate_str.c_str(), NULL);
    }
    
    _isPrintable = true;
}

void BitcoinExchange::createFromInput(std::ifstream& input_file, std::ifstream& data_file) {
    std::string line;
    
    std::getline(input_file, line);
    if (!validateInputLine(line)) {
        if (_errorMessage == "None") {
            _errorMessage = "Error: bad input => " + line;
        }
        return;
    }
    
    extractRateFromData(data_file);
}

std::list<BitcoinExchange> BitcoinExchange::createExchanges(std::ifstream& input_file, std::ifstream& data_file) {
    std::list<BitcoinExchange> exchanges;
    
    while (!input_file.eof()) {
        BitcoinExchange exchange;
        exchange.createFromInput(input_file, data_file);
        exchanges.push_back(exchange);
    }
    
    return exchanges;
}

void BitcoinExchange::printExchanges(const std::list<BitcoinExchange>& exchanges) {
    for (std::list<BitcoinExchange>::const_iterator it = exchanges.begin(); it != exchanges.end(); ++it) {
        if (it->isPrintable()) {
            std::cout << it->getDate() << " => " << it->getValue() << " = " << it->getRate() * it->getValue() << std::endl;
        } else {
            std::cerr << it->getErrorMessage() << std::endl;
        }
    }
}