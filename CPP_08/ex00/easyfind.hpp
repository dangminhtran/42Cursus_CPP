/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:55:30 by dangtran          #+#    #+#             */
/*   Updated: 2025/07/01 16:55:31 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

template <typename T>

void	easyfind(T &container, int value)
{
	typename T::iterator	iterator;
	
	iterator = std::find(container.begin(), container.end(), value);
	if (iterator == container.end())
		throw std::exception();
	std::cout << "Value found: " << *iterator << std::endl;
}

#endif