/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:37:41 by dangtran          #+#    #+#             */
/*   Updated: 2025/06/16 13:17:22 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Forme canonique
ScalarConverter::ScalarConverter(void) {}
ScalarConverter::~ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

// Functions for check
bool ScalarConverter::_isChar(std::string &input)
{
	if (input.length() == 1 && !std::isdigit(input[0]))
		return (true);
	return (false);
}

bool ScalarConverter::_isInt(std::string &input)
{
	char	*end;
	long	nb;

	nb = std::strtol(input.c_str(), &end, 10);
	if (end == input.c_str() || *end != '\0')
		return (false);
	if (nb > 2147483647 || nb < -2147483648)
		return (false);
	return (true);
}

bool ScalarConverter::_isFloat(std::string &input)
{
	char	*end;
	float	nb;

	nb = std::strtof(input.c_str(), &end);
	(void)nb;
	if (end == input.c_str() || *end != 'f' || *(end + 1) != '\0')
		return (false);
	return (true);
}

bool ScalarConverter::_isDouble(std::string &input)
{
	char	*end;
	double	nb;

	nb = std::strtod(input.c_str(), &end);
	(void)nb;
	if (end == input.c_str() || *(end) != '\0')
		return (false);
	return (true);
}

bool ScalarConverter::_isLiteral(std::string &input)
{
	if (input == "-inff" || input == "+inff" || input == "nanf"
		|| input == "-inf" || input == "+inf" || input == "nan")
		return (true);
	return (false);
}

// Getters
type ScalarConverter::_getType(std::string &input)
{
	if (_isChar(input))
		return (CHAR);
	if (_isInt(input))
		return (INT);
	if (_isFloat(input))
		return (FLOAT);
	if (_isDouble(input))
		return (DOUBLE);
	if (_isLiteral(input))
		return (LITERAL);
	return (OTHER);
}

int ScalarConverter::getPrecision(const std::string &input)
{
    int	i;
    int	count;

    i = 0;
    while (input[i] && input[i] != '.')
        i++;
    if (input[i] == '\0')
        return (1);
    i++;
    count = 0;
    while (input[i + count] && input[i + count] != 'f' && count < 6)
        count++;
    return (count);
}

// Print functions
void ScalarConverter::_printChar(std::string &input)
{
	char	c;

	c = input[0];
	std::cout << "char: "
				<< "\'" << c << "\'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << 'f' << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void ScalarConverter::_printInt(std::string &input)
{
	int	nb;

	nb = atoi(input.c_str());
	if (nb >= 32 && nb <= 126)
	std::cout << "char: "
	<< "\'" << static_cast<char>(nb) << "\'" << std::endl;
	else
		std::cout << "char: "
					<< "Non displayable" << std::endl;
	std::cout << "int: " << nb << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(nb) << 'f' << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(nb) << std::endl;
}


void ScalarConverter::_printFloat(std::string &input)
{
	float	nb;
	int		precision;

	nb = std::strtof(input.c_str(), NULL);
	if (nb >= 32 && nb <= 126)
		std::cout << "char: "
					<< "\'" << static_cast<char>(nb) << "\'" << std::endl;
	else
		std::cout << "char: "
					<< "Non displayable" << std::endl;
	if (static_cast<float>(-2147483648) <= nb
		&& nb <= static_cast<float>(2147483647))
		std::cout << "int: " << static_cast<int>(nb) << std::endl;
	else
		std::cout << "int: "
					<< "Non displayable" << std::endl;
	precision = ScalarConverter::getPrecision(input);
	std::cout << "float: " << std::fixed << std::setprecision(precision) << nb << 'f' << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(precision) << static_cast<double>(nb) << std::endl;
}

void ScalarConverter::_printDouble(std::string &input)
{
	double	nb;
	int		precision;

	nb = std::strtod(input.c_str(), NULL);
	if (nb >= 32 && nb <= 126)
		std::cout << "char: "
					<< "\'" << static_cast<char>(nb) << "\'" << std::endl;
	else
		std::cout << "char: "
					<< "Non displayable" << std::endl;
	if (static_cast<double>(-2147483648) <= nb && nb <= static_cast<double>(2147483647))
		std::cout << "int: " << static_cast<int>(nb) << std::endl;
	else
		std::cout << "int: " << "Non displayable" << std::endl;
	precision = ScalarConverter::getPrecision(input);
	if (-FLT_MAX <= nb && nb <= FLT_MAX)
		std::cout << "float: " << std::fixed << std::setprecision(precision) << static_cast<float>(nb) << 'f' << std::endl;
	else
		std::cout << "float: "
					<< "Non displayable" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(precision) << nb << std::endl;
}

void ScalarConverter::_printOther(void)
{
	std::cout << "char: "
				<< "Non displayable" << std::endl;
	std::cout << "int: "
				<< "Non displayable" << std::endl;
	std::cout << "float: "
				<< "Non displayable" << std::endl;
	std::cout << "double: "
				<< "Non displayable" << std::endl;
}

void ScalarConverter::_printLiteral(const std::string &input)
{
	std::cout << "char: "
				<< "Impossible" << std::endl;
	std::cout << "int: "
				<< "Impossible" << std::endl;
	if (input == "-inff")
	{
		std::cout << "float: "
					<< "-inff" << std::endl;
		std::cout << "double: "
					<< "-inf" << std::endl;
	}
	else if (input == "+inff")
	{
		std::cout << "float: "
					<< "+inff" << std::endl;
		std::cout << "double: "
					<< "+inf" << std::endl;
	}
	else if (input == "nanf")
	{
		std::cout << "float: "
					<< "nanf" << std::endl;
		std::cout << "double: "
					<< "nan" << std::endl;
	}
	else
	{
		std::cout << "float: "
					<< "Impossible" << std::endl;
		std::cout << "double: " << input << std::endl;
	}
}

// Main convert function
void ScalarConverter::convert(std::string &input)
{
	type	type;

	if (input.size() == 0)
		throw ScalarConverter::InputTypeException();
	type = _getType(input);
	switch (type)
	{
	case LITERAL:
		ScalarConverter::_printLiteral(input);
		break ;
	case CHAR:
		ScalarConverter::_printChar(input);
		break ;
	case INT:
		ScalarConverter::_printInt(input);
		break ;
	case FLOAT:
		ScalarConverter::_printFloat(input);
		break ;
	case DOUBLE:
		ScalarConverter::_printDouble(input);
		break ;
	case OTHER:
		throw ScalarConverter::InputTypeException();
		break ;
	}
}

// Exceptions
const char * ScalarConverter::InputTypeException::what() const throw()
{
	return ("Input type is unknown");
}
