/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:24:56 by dangtran          #+#    #+#             */
/*   Updated: 2025/05/01 14:25:28 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void ) {
	ClapTrap	Frankeinstein("Frankeinstein");
	ScavTrap	A("A");
	FragTrap	B("B");

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
	B.attack(A.getName());
	A.takeDamage(B.getAttackDamage());
	B.highFivesGuys();
	return (0);
}