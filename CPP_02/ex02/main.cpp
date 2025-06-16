/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 11:58:24 by dangtran          #+#    #+#             */
/*   Updated: 2025/04/27 13:59:34 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	
	// std::cout << "a: " << a << std::endl;
	// std::cout << "--a: " << --a << std::endl;
	// std::cout << "a: " << a << std::endl;
	// std::cout << "a--: " << a-- << std::endl;
	// std::cout << "a: " << a << std::endl;
	// std::cout << "b: " << b << std::endl;

	// Fixed c(5.05f);
	// Fixed d(5.05f);
	// std::cout << "c: " << c << std::endl;
	// std::cout << "d: " << d << std::endl;
	// std::cout << "c == d: " << (c == d) << std::endl;
	// std::cout << "c != d: " << (c != d) << std::endl;
	// std::cout << "c > d: " << (c > d) << std::endl;
	// std::cout << "c < d: " << (c < d) << std::endl;
	// std::cout << "c >= d: " << (c >= d) << std::endl;
	// std::cout << "c <= d: " << (c <= d) << std::endl;
	
	// Fixed e(5.05f);
	// Fixed f(2.02f);
	// std::cout << "e: " << e << std::endl;
	// std::cout << "f: " << f << std::endl;
	// std::cout << "e + f: " << (e + f) << std::endl;
	// std::cout << "e - f: " << (e - f) << std::endl;
	// std::cout << "e * f: " << (e * f) << std::endl;
	// std::cout << "e / f: " << (e / f) << std::endl;
	
	return 0;
}