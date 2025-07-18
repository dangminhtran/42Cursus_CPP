#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include <string>

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(Ice const &src);
		virtual ~Ice();

		Ice & operator=(Ice const &);

		Ice* clone() const;
		void use(ICharacter& target);
};

#endif