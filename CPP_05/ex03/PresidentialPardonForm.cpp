/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:18:47 by dangtran          #+#    #+#             */
/*   Updated: 2025/05/30 12:14:03 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Forme canonique
PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm",
	25, 5), _target(target)
{
//	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy)
	: AForm(copy), _target(copy._target)
{
//	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
//	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	if (this == &rhs)
		return (*this);
	(void)rhs;
	return (*this);
}

// Exceptions
const char *PresidentialPardonForm::FileException::what() const throw()
{
	return ("Error message from PresidentialPardonForm exception"); // Utile ?
}

// Fonctions membres
void PresidentialPardonForm::beExecuted(void) const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebox" << std::endl;
}