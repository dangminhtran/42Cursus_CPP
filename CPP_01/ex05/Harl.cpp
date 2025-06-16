/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:35:43 by dangtran          #+#    #+#             */
/*   Updated: 2025/04/20 11:42:26 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl is ready to complain." << std::endl;
	std::cout << "-------------------------" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl is done complaining." << std::endl;
	std::cout << "Bye!" << std::endl;
	std::cout << "-------------------------" << std::endl;
}

void	Harl::debug(void)
{
	std::cout << "-- DEBUG --\n I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\n I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "-- INFO --\n I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger!\nIf you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "-- WARNING --\n I think I deserve to have some extra bacon for free.\n I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "-- ERROR --\n This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	void    (Harl::*functionptrs[])( void ) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string messages[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	bool valid_input = false;

	for (int i = 0; i < 4; i++)
	{
		if (messages[i] == level)
		{
			(this->*functionptrs[i])();
			valid_input = true;
			break;
		}
	}

	if (!valid_input)
	{
		std::cout << "Error: Invalid level of complaint. Valid levels are: DEBUG, INFO, WARNING, ERROR." << std::endl;
	}
}