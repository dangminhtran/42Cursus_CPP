/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 12:18:08 by dangtran          #+#    #+#             */
/*   Updated: 2025/05/17 12:18:32 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <string>

#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		static const int _inventorySize = 4;
		std::string	_name;
		AMateria	*_inventory[_inventorySize];

	public:
		Character(void);
		Character(std::string const &name);
		Character(Character const &src);
		virtual ~Character();

		Character & operator=(Character const &src);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif