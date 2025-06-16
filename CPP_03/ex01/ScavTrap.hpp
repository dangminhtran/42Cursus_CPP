/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:26:28 by dangtran          #+#    #+#             */
/*   Updated: 2025/05/01 14:26:29 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		bool		_isGuardGate;
	public:
		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const &src );
		ScavTrap &operator=( ScavTrap const &rhs );
		~ScavTrap( void );	

		void	guardGate( void );
		void	attack(std::string const &target);
		bool	getIsGuardGate( void ) const;
};

#endif