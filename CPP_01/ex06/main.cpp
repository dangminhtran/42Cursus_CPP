/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:35:40 by dangtran          #+#    #+#             */
/*   Updated: 2025/04/20 12:02:29 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;
	if (argc != 2)
		std::cout << ("This is an error, you stupid!") << std::endl;
	else
		harl.complain(argv[1]);
	return (EXIT_SUCCESS);
}