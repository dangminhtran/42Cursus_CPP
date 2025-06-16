/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:30:08 by dangtran          #+#    #+#             */
/*   Updated: 2025/05/03 12:30:07 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main( void ) {
	ClapTrap	Frankeinstein("Frankeinstein");
	ScavTrap	A("A");

	Frankeinstein.attack(A.getName());
	A.takeDamage(Frankeinstein.getAttackDamage());
	
	A.attack(Frankeinstein.getName());
	Frankeinstein.takeDamage(A.getAttackDamage());
	
	Frankeinstein.attack(A.getName());
	A.takeDamage(Frankeinstein.getAttackDamage());
	
	A.guardGate();
	Frankeinstein.attack(A.getName());
	A.takeDamage(Frankeinstein.getAttackDamage());
	
	A.guardGate();
	return (0);
}