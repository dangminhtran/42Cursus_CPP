#include "Serializer.hpp"

Serializer::Serializer(void) {}

Serializer::Serializer(Serializer const &src) { (void)src; }

Serializer::~Serializer(void) {}

Serializer &Serializer::operator=(Serializer const &src)
{
	(void)src;
	return (*this);
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	uintptr_t	raw;

	raw = reinterpret_cast<uintptr_t>(ptr);
	return (raw);
}

Data		*Serializer::deserialize(uintptr_t raw)
{
	Data		*ptr;

	ptr = reinterpret_cast<Data *>(raw);
	return (ptr);
}