/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:51:47 by dangtran          #+#    #+#             */
/*   Updated: 2025/05/17 11:51:48 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(Brain const &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(Brain const &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << "Brain assignation operator called" << std::endl;
	*this->_ideas = *rhs._ideas;
	return (*this);
}

const std::string	Brain::getIdea(int index) const
{
	if (index < 0 || index > BRAIN_SIZE - 1)
	{
		std::cout << "Index out of range" << std::endl;
		return ("");
	}
	return (this->_ideas[index]);
}

const std::string	*Brain::getIdeas(void) const
{
	return (this->_ideas);
}

void	Brain::setIdea(int index, std::string idea)
{
	if (index < 0 || index > BRAIN_SIZE - 1)
	{
		std::cout << "Index out of range" << std::endl;
		return ;
	}
	this->_ideas[index] = idea;
}

void	Brain::setIdeas(const std::string *ideas)
{
	for (int i = 0; i < BRAIN_SIZE; i++)
		this->_ideas[i] = ideas[i];
}