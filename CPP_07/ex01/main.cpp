/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:35:40 by dangtran          #+#    #+#             */
/*   Updated: 2025/06/16 16:39:50 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

template <typename T>
void	print(T const &element)
{
	std::cout << element << std::endl;
}

int	main(void)
{
	int 		arrayOfInt[] = {0, 1, 2, 3, 4};
	int			arrayOfSameInt[] = { 42, 42, 42, 42, 42 };
	std::string arrayOfString[] = {"Hello", "World", "!"};

	iter(arrayOfInt, 5, print);
	iter(arrayOfSameInt, 5, print);
	iter(arrayOfString, 3, print);
	return (0);
}