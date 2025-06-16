/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:56:13 by dangtran          #+#    #+#             */
/*   Updated: 2025/04/12 17:56:14 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
class Zombie
{
    public: 
        Zombie(std::string name);
        ~Zombie( void );
        void announce( void );
        
    private:
        std::string name;
};

#endif