#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog constructor called" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(Dog const &src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_brain = new Brain();
	*this = src;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

Dog &Dog::operator=(Dog const &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << "Dog assignation operator called" << std::endl;
	this->_type = rhs.getType();
	this->_brain->setIdeas(rhs._brain->getIdeas());
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Ouaf ouaf...." << std::endl;
}

Brain	*Dog::getBrain(void) const
{
	return (this->_brain);
}