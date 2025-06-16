/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 13:44:42 by dangtran          #+#    #+#             */
/*   Updated: 2025/05/17 16:00:18 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Character.hpp"

Character::Character(void) : _name("unknown") {
//	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < this->_inventorySize; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string const &name) : _name(name) {
//	std::cout << "Character constructor called with the name: " << this->_name << std::endl;
	for (int i = 0; i < this->_inventorySize; i++)
		this->_inventory[i] = NULL;
}

Character::Character(Character const &src) {
//	std::cout << "Character copy constructor called" << std::endl;
	*this = src;
}

Character::~Character(void) {
//	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < this->_inventorySize; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
}

Character & Character::operator=(Character const &src) {
//	std::cout << "Character assignation operator called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		for (int i = 0; i < this->_inventorySize; i++)
		{
			if (this->_inventory[i] != NULL)
				delete this->_inventory[i];
			if (src._inventory[i] != NULL)
				this->_inventory[i] = src._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return (*this);
}

std::string const & Character::getName() const {
//	std::cout << "Character getName called" << std::endl;
//	std::cout << this->_name << std::endl;
	return (this->_name);
}

void Character::equip(AMateria* m) {
//	std::cout << "Character equip called" << std::endl;
	for (int i = 0; i < this->_inventorySize; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
		//	std::cout << "Equiped " << m->getType() << std::endl;
			return;
		}
	}
	std::cout << "Inventory is full" << std::endl;
	delete m;
    return;
}

void Character::unequip(int idx) {
//	std::cout << "Character unequip called" << std::endl;
	if (idx < 0 || idx >= this->_inventorySize)
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	if (this->_inventory[idx] == NULL)
	{
		std::cout << "Nothing to unequip" << std::endl;
		return;
	}
//	std::cout << "Unequiped " << this->_inventory[idx]->getType() << std::endl;
	delete this->_inventory[idx];
	this->_inventory[idx] = NULL;
	return;
}

void Character::use(int idx, ICharacter& target) {
//	std::cout << "Character use called for the name: " << this->_name << std::endl;
	if (idx < 0 || idx >= this->_inventorySize)
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	if (this->_inventory[idx] == NULL)
	{
//		std::cout << "Nothing to use" << std::endl;
		return;
	}
	this->_inventory[idx]->use(target);
	return;
}