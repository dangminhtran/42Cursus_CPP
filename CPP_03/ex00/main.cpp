/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:27:45 by dangtran          #+#    #+#             */
/*   Updated: 2025/05/01 11:27:46 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap	Frankeinstein("Frankeinstein");
	ClapTrap	FKClone = Frankeinstein;
	ClapTrap	Attackers[5];

	Frankeinstein.attack("Police officer"); // 1
	Frankeinstein.attack(Attackers[0].getName()); // 2
	Frankeinstein.attack(Attackers[1].getName()); // 3
	Frankeinstein.attack(Attackers[2].getName()); // 4
	Frankeinstein.attack(Attackers[3].getName()); // 5
	Frankeinstein.attack(Attackers[4].getName()); // 6
	Frankeinstein.attack("Police officer"); // 7
	Frankeinstein.attack("Police officer"); // 8
	Frankeinstein.attack("Police officer"); // 9
	Frankeinstein.attack("Police officer"); // 10
	Frankeinstein.attack("Police officer"); // no energy
	Frankeinstein.takeDamage(9); // 1 hitPoints 
	Frankeinstein.attack("Police officer"); // no energy
	Frankeinstein.takeDamage(1); // 0 hitPoints
	Frankeinstein.attack("Police officer"); // dead

	FKClone.attack("Police officer"); // 1
	FKClone.beRepaired(1); // 1 hitPoints

	Frankeinstein.beRepaired(10); // dead
	return (0);
}