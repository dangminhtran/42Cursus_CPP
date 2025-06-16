/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:24:56 by dangtran          #+#    #+#             */
/*   Updated: 2025/05/01 17:39:14 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void ) {
	ClapTrap	Frankeinstein("Frankeinstein");
	ScavTrap	A("A");
	FragTrap	B("B");
	DiamondTrap C("C");
	
	C.attack(A.getName());
	Frankeinstein.attack(C.getName());
	A.takeDamage(A.getAttackDamage());
	B.attack(C.getName());
	C.takeDamage(B.getAttackDamage());
	C.whoAmI();
	
	return (0);
}