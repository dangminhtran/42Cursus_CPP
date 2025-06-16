#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <limits.h>
#include <cfloat>
#include <cstdlib>
#include <iomanip>
#include <sstream>

# define CHAR_MIN_STR "-128"
# define CHAR_MAX_STR "127"
# define INT_MIN_STR "-2147483648"
# define INT_MAX_STR "2147483647"

enum type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
  LITERAL,
  OTHER
};

class ScalarConverter {
  public:
    static void		convert(std::string &input);

  class	InputTypeException : public std::exception
  {
    public:
      virtual const char* what() const throw();
  };
      
  private:
    ScalarConverter();
    ScalarConverter(const std::string &input);
    ScalarConverter(const ScalarConverter &other);
    ~ScalarConverter();
    ScalarConverter &operator=(const ScalarConverter &other);

    static type		_getType(std::string &input);
    static int getPrecision(std::string const &input);

    static bool		_isChar(std::string &input);
    static bool		_isInt(std::string &input);
    static bool		_isFloat(std::string &input);
    static bool		_isDouble(std::string &input);
    static bool		_isLiteral(std::string &input);

    static void		_printChar(std::string &input);
    static void		_printInt(std::string &input);
    static void		_printFloat(std::string &input);
    static void		_printDouble(std::string &input);
    static void   _printLiteral(std::string const &input);
    static void   _printOther( void );

};

#endif