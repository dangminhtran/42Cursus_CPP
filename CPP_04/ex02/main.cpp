/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 12:01:31 by dangtran          #+#    #+#             */
/*   Updated: 2025/05/17 12:02:05 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int test(void)
{
	Animal *animals[4 ];

	for (int i = 0; i < 4 ; i++)
	{
		if (i % 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();

		animals[i]->makeSound();
		animals[i]->getBrain()->setIdea(0, "Toc toc toc");
		std::cout << "Idea: " << animals[i]->getBrain()->getIdeas()[0] << std::endl << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < 4 ; i++)
		delete animals[i];
	return (0);
}

int main( void ) {

	Animal	*cat = new Cat();
	cat->makeSound();
	delete cat;

	// not possible to create an instance of an abstract class
	// Animal	ko = Animal();
	// ko.makeSound();
	// Animal	dog = Dog();
	// dog.makeSound();

	test();
	return (0);

}