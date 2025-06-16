#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <iostream>
#include <string>

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		static int const _materiaSize = 4;
		AMateria *_materia[_materiaSize];
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const &src);
		virtual ~MateriaSource();

		MateriaSource & operator=(MateriaSource const &src);

		void learnMateria(AMateria * materia);
		AMateria* createMateria(std::string const & type);
};

#endif