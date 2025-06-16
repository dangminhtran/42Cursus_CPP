/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:57:36 by dangtran          #+#    #+#             */
/*   Updated: 2025/04/12 18:46:52 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int N = 5;
    Zombie* horde = zombieHorde(N, "New Zombie");
    if (horde == NULL) {
        std::cout << "Failed to create zombie horde." << std::endl;
        return 1;
    }
    
    for (int i = 0; i < N; ++i) {
        horde[i].announce();
    }
    
    delete[] horde;
    return 0;
}