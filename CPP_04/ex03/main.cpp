/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 12:18:11 by dangtran          #+#    #+#             */
/*   Updated: 2025/05/17 12:19:37 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int	main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter *me = new Character("Minh");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter *mimi = new Character("Mimi");
	me->use(0, *mimi);
	me->use(1, *mimi);
	delete mimi;
	delete me;
	delete src;
	return (0);
}

// int	test2(void)
// {
// 	std::cout << "Custom test" << std::endl;
	
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	src->learnMateria(new Ice()); // This one should not be learned

// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");

// 	ICharacter* zbi = new Character("zbi");
// 	zbi->equip(tmp);
// 	zbi->use(0, *zbi);
// 	zbi->use(249844846, *zbi); // This one should not work
// 	zbi->use(-454654, *zbi); // This one should not work
// 	zbi->use(2, *zbi); // This one should not work
// 	zbi->unequip(0);
// 	zbi->use(0, *zbi); // This one should not work
// 	zbi->unequip(57527057); // This one should not work
// 	delete src;
// 	delete zbi;
// 	delete tmp;
// 	return (0);
// }

// int main(void)
// {
// 	test();
// 	test2();
// 	return (0);
// }