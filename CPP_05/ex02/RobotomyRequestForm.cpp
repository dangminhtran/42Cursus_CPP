/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:09:36 by dangtran          #+#    #+#             */
/*   Updated: 2025/05/30 12:12:47 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Forme canonique
RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm",
	72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy)
	: AForm(copy), _target(copy._target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this == &rhs)
		return (*this);
	(void)rhs;
	return (*this);
}

// Exceptions
const char *RobotomyRequestForm::FileException::what() const throw()
{
	return ("Error message from RobotomyRequestForm exception"); // Utile ?
}

// Fonctions membres
void RobotomyRequestForm::beExecuted(void) const
{
	std::srand(std::time(0));
    
	if (std::rand() % 2)
		std::cout << this->_target << " has been robotomized." << std::endl;
	else
		std::cout << this->_target << " robotomization failed." << std::endl;
}