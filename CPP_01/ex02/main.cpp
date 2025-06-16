/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:35:49 by dangtran          #+#    #+#             */
/*   Updated: 2025/04/13 14:34:42 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "Address of string: " << &string << std::endl;
	std::cout << "Address of stringPTR: " << &stringPTR << std::endl;
	std::cout << "Address of stringREF: " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "Value of string: " << string <<std::endl;
	std::cout << "Value pointed to by stringPTR: " << stringPTR <<std::endl;
	std::cout << "Value of stringREF: " << stringREF <<std::endl;

	return (EXIT_SUCCESS);
}