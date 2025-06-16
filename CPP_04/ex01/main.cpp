/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:51:31 by dangtran          #+#    #+#             */
/*   Updated: 2025/05/18 13:35:48 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main( void ) {
	Animal *animals[4];

	for (int i = 0; i < 4; i++)
	{
		if (i % 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();

		animals[i]->makeSound();
		animals[i]->getBrain()->setIdea(0, "Fooooood...");
		animals[i]->getBrain()->setIdea(1, "Play with me!");
		std::cout << "Idea: " << animals[i]->getBrain()->getIdeas()[0] << std::endl;
		std::cout << "Idea: " << animals[i]->getBrain()->getIdeas()[1] << std::endl << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
		delete animals[i];
	return (0);
}