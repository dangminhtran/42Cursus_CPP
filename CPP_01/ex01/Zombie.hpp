/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:57:42 by dangtran          #+#    #+#             */
/*   Updated: 2025/04/20 11:34:47 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    public: 
        Zombie( void );
        ~Zombie( void );
        void announce( void );
        void setName(std::string name);
        
    private:
        std::string _name;
};
    
Zombie* zombieHorde(int N, std::string name);

    
#endif