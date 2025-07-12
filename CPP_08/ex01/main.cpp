/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:01:59 by dangtran          #+#    #+#             */
/*   Updated: 2025/07/06 10:36:20 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>

int	main(void)
{
	/* Test with span of 100 */
	std::cout << "Test with 100 random numbers" << std::endl;
	try {
		Span sp2 = Span(100);
		srand(time(NULL));
		std::vector<int> tmp;
		for (int i = 0; i < 100; i++)
			tmp.push_back(rand() % 1000);
		sp2.addNumbers(tmp.begin(), tmp.end());
		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "Test with 101 numbers (should throw an exception)" << std::endl;
	try {
		Span sp2 = Span(100);
		srand(time(NULL));
		std::vector<int> tmp;
		for (int i = 0; i < 101; i++)
			tmp.push_back(rand() % 1000);
		sp2.addNumbers(tmp.begin(), tmp.end());
		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	/* Test from subject */
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return (0);
}