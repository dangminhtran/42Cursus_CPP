#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {
//	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(Ice const &src) : AMateria(src) {
//	std::cout << "Ice copy constructor called" << std::endl;
	*this = src;
}

Ice::~Ice(void) {
//	std::cout << "Ice destructor called" << std::endl;
}

Ice & Ice::operator=(Ice const &src) {
//    std::cout << "Ice assignation operator called" << std::endl;
	if (this != &src)
		AMateria::operator=(src);
	return (*this);
}

Ice * Ice::clone() const {
//	std::cout << "Ice clone called" << std::endl;
	return (new Ice(*this));
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " * " << std::endl;
	return;
}