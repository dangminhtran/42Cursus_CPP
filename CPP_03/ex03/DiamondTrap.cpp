/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:42:04 by dangtran          #+#    #+#             */
/*   Updated: 2025/05/03 11:40:37 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap Constructor called with no name " << std::endl;
}

DiamondTrap::DiamondTrap( std::string name) : FragTrap(), ScavTrap(), _name(name)
{
	std::cout << "DiamondTrap Constructor called with name " << name << std::endl;
    ClapTrap::_name = name + "_clap_name";

}

DiamondTrap &DiamondTrap::operator=( DiamondTrap const &rhs)
{
    std::cout << "DiamondTrap assignation operator " << std::endl;
    if (this == &rhs)
        return (*this);
    this->_name = rhs.getName();
    return (*this);
}

DiamondTrap::DiamondTrap( DiamondTrap const &src)
{
    std::cout << "DiamondTrap copy constructor with name " << src.getName() << std::endl;
	*this = src;
}

DiamondTrap::~DiamondTrap( void )
{
    std::cout << "DiamondTrap Destructor called" << std::endl;
}

void DiamondTrap::whoAmI( void )
{
    std::cout << "ClapTrap Name " << ClapTrap::_name << std::endl;
    std::cout << "My name is " << this->_name << std::endl;
}
