#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
//	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < this->_materiaSize; i++)
		this->_materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &src) {
//	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = src;
}

MateriaSource::~MateriaSource(void) {
//	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < this->_materiaSize; i++)
	{
		if (this->_materia[i] != NULL)
			delete this->_materia[i];
	}
}

MateriaSource & MateriaSource::operator=(MateriaSource const &src) {
//	std::cout << "MateriaSource assignation operator called" << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < this->_materiaSize; i++)
		{
			if (this->_materia[i] != NULL)
				delete this->_materia[i];
			if (src._materia[i] != NULL)
				this->_materia[i] = src._materia[i]->clone();
			else
				this->_materia[i] = NULL;
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria * materia) {
	// std::cout << "MateriaSource learnMateria called" << std::endl;
	for (int i = 0; i < this->_materiaSize; i++)
	{
		if (this->_materia[i] == NULL)
		{
			this->_materia[i] = materia;
		//	std::cout << "Materia " << materia->getType() << " learned." << std::endl;
			return;
		}
	}
	std::cout << "Materia source is full." << std::endl;
	delete materia;
	return;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	// std::cout << "MateriaSource createMateria called" << std::endl;
	for (int i = 0; i < this->_materiaSize; i++)
	{
		if (this->_materia[i] != NULL && this->_materia[i]->getType() == type)
		{
		//	std::cout << "Materia " << type << " created." << std::endl;
			return (this->_materia[i]->clone());
		}
	}
	std::cout << "Materia " << type << " not learned." << std::endl;
	return (NULL);
}