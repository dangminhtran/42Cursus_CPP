#include "iter.hpp"
#include <iostream>

template <typename T>
void	printElement(T const &element)
{
	std::cout << element << std::endl;
}

int	main(void)
{
	int 		arrayOfInt[] = {0, 1, 2, 3, 4};
	int			arrayOfIntZBI[] = { 42, 42, 42, 42, 42 };
	std::string arrayOfString[] = {"Hello", "World", "!"};

	iter(arrayOfInt, 5, printElement);
	iter(arrayOfIntZBI, 5, printElement);
	iter(arrayOfString, 3, printElement);
	return (0);
}