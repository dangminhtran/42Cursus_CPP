#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>
# include "Data.hpp"

class Serializer
{
	private:
		Serializer(void);
		Serializer(Serializer const &src);
		~Serializer(void);
		Serializer &operator=(Serializer const &src);

	public:
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);

};

#endif