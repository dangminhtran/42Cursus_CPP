/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:26:20 by dangtran          #+#    #+#             */
/*   Updated: 2025/05/01 14:27:14 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void )
{
	std::cout << "FragTrap default constructor" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap( std::string name )
{
	std::cout << "FragTrap constructor with name " << name << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap( FragTrap const &src )
{
	std::cout << "FragTrap copy constructor with name " << src.getName() << std::endl;
	*this = src;
}

FragTrap &FragTrap::operator=( FragTrap const &rhs )
{
	if (this == &rhs)
		return (*this);
	std::cout << "FragTrap assignation operator with name " << rhs.getName() << std::endl;
	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_attackDamage = rhs.getAttackDamage();
	return (*this);
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap destructor with name " << this->_name << std::endl;
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap " << this->_name << " is doing a high five" << std::endl;
}