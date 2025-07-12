/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:55:26 by dangtran          #+#    #+#             */
/*   Updated: 2025/07/01 16:55:27 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>

int	main(void)
{
	std::vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i);
	
	// Test good value
	std::cout << "Test good value: " << std::endl;
	try
	{
		easyfind(vec, 5);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Value not found" << std::endl;
	}
	try
	{
		easyfind(vec, 9);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Value not found" << std::endl;
	}

	// Test wrong value
	std::cout << "Test wrong value: " << std::endl;
	try
	{
		easyfind(vec, 10);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Value not found" << std::endl;
	}
	try
	{
		easyfind(vec, 11);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Value not found" << std::endl;
	}
	return (0);
}