/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:26:42 by dangtran          #+#    #+#             */
/*   Updated: 2025/05/03 14:16:34 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	private:
		bool		_isGuardGate;
	public:
		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const &src );
		~ScavTrap( void );
		
		ScavTrap &operator=( ScavTrap const &rhs );

		void	guardGate( void );
		void	attack(std::string const &target);
		bool	getIsGuardGate( void ) const;
};

#endif