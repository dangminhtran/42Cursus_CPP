#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include <string>

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(Cure const &src);
		virtual ~Cure();

		Cure & operator=(Cure const &src);

		Cure * clone() const;
		void use(ICharacter& target);
};

#endif