/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:57:45 by dangtran          #+#    #+#             */
/*   Updated: 2025/04/19 12:02:02 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
    if (N < 1) 
    {
        std::cerr << "Error: Number of zombies must be greater than 0." << std::endl;
        return NULL;
    }

    Zombie* horde = new Zombie[N];
    if (!horde) 
    {
        std::cerr << "Error: Memory allocation failed." << std::endl;
        return NULL;
    }
    for (int i = 0; i < N; ++i) {
        horde[i].setName(name);
    }
    return horde;
}

