/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:35:28 by dangtran          #+#    #+#             */
/*   Updated: 2025/04/20 11:41:11 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
//	this->_has_a_weapon = false;
	std::cout << this->_name <<" joined the fight." << std::endl;
}

HumanB::~HumanB(void)
{
    std::cout << this->_name << " was defeated." << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
//	this->_has_a_weapon = true;
	std::cout << this->_name << " took a " << this->_weapon->getType() << " to fight with." << std::endl;
}

// void HumanB::attack(void)
// {
//     if (this->_has_a_weapon)
//     {
//         std::cout << this->_name << " attacks with their " << this->_weapon->getType() << "." << std::endl;
//     }
//     else
//     {
//         std::cout << this->_name << " attacks with his fists." << std::endl;
//     }
// }

void HumanB::attack(void)
{
    if (this->_weapon)
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << "." << std::endl;
    else
        std::cout << this->_name << " attacks with his fists." << std::endl;
}