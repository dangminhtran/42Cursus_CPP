/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 12:18:06 by dangtran          #+#    #+#             */
/*   Updated: 2025/05/17 15:57:54 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {
//	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(Cure const &src) : AMateria(src) {
//	std::cout << "Cure copy constructor called" << std::endl;
	*this = src;
}

Cure::~Cure(void) {
//	std::cout << "Cure destructor called" << std::endl;
}

Cure & Cure::operator=(Cure const &src) {
	// std::cout << "Cure assignation operator called" << std::endl;
	if (this != &src)
		AMateria::operator=(src);
	return (*this);
}

Cure * Cure::clone() const {
	// std::cout << "Cure clone called" << std::endl;
	return (new Cure(*this));
}

void Cure::use(ICharacter& target) {
    // std::cout << "Cure use called" << std::endl;
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	return;
}