/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 11:59:02 by dangtran          #+#    #+#             */
/*   Updated: 2025/04/27 15:44:21 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _raw(0) {}

Fixed::Fixed(int const raw) : _raw(raw << _bits) {}

Fixed::Fixed( float const raw )
{
	this->_raw = roundf(raw * (1 << this->_bits));
}

Fixed::Fixed( Fixed const &src )
{
	*this = src;

}

Fixed::~Fixed( void ) {}

Fixed &	Fixed::operator=( Fixed const &rhs )
{
	if (this != &rhs)
		this->setRawBits(rhs.getRawBits());
	return *this;
}

int	Fixed::getRawBits( void ) const
{
	return _raw;
}

void	Fixed::setRawBits( int const raw )
{
	_raw = raw; 
}

float	Fixed::toFloat( void ) const
{
	return (float)this->_raw / (1 << this->_bits);
}

int		Fixed::toInt( void ) const
{
	return _raw >> _bits;
}

std::ostream & operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return o;
}

// Comparison operators
bool	Fixed::operator>(Fixed const &rhs) const
{
	return this->_raw > rhs.getRawBits();
}

bool	Fixed::operator<(Fixed const &rhs) const
{
	return this->_raw < rhs.getRawBits();
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	return this->_raw >= rhs.getRawBits();
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	return this->_raw <= rhs.getRawBits();
}

bool	Fixed::operator==(Fixed const &rhs) const
{
	return this->_raw == rhs.getRawBits();
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
	return this->_raw != rhs.getRawBits();
}

// Arithmetic operators
Fixed	Fixed::operator+(Fixed const &rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(Fixed const &rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(Fixed const &rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(Fixed const &rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

// Increment and decrement operators
Fixed &	Fixed::operator++(void)
{
	this->_raw++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	_raw +=1 ;
	return tmp;
}

Fixed &	Fixed::operator--(void)
{
	this->_raw--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

// Min and Max functions
Fixed &	Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed &	Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	return (a < b) ? a : b;
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	return (a > b) ? a : b;
}