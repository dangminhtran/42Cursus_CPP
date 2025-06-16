/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:35:24 by dangtran          #+#    #+#             */
/*   Updated: 2025/04/13 12:18:39 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _weapon(weapon)
{
	this->_name = name;
	std::cout << this->_name <<" joined the fight and took a " << this->_weapon.getType() << std::endl;
}

HumanA::~HumanA(void)
{
    std::cout << this->_name << " was defeated." << std::endl;
}

void HumanA::attack(void)
{
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << "." << std::endl;
}
