#include "Array.hpp"

int	main(void)
{
	Array<int> arrayInt(5);
	int *cpy = new int[5];

	// Assing values to arrayInt
	srand(time(NULL));
	for (size_t i = 0; i < arrayInt.size(); i++)
	{
		arrayInt[i] = rand() % 100;
		cpy[i] = arrayInt[i];
	}

	// Print arrayInt
	std::cout << "arrayInt: " << std::endl;
	for (size_t i = 0; i < arrayInt.size(); i++)
	{
		std::cout << "-> array: " << arrayInt[i] << ", cpy: " << cpy[i] << std::endl;
		if (i == arrayInt.size() - 1)
			std::cout << std::endl;
	}

	// Test good index
	std::cout << "Test good index: " << std::endl;
	try
	{
		std::cout << "arrayInt[0]: " << arrayInt[0] << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "arrayInt[4]: " << arrayInt[4] << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Test wrong index
	std::cout << "Test wrong index: " << std::endl;
	try
	{
		std::cout << "arrayInt[5]: " << arrayInt[5] << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "arrayInt[-1]: " << arrayInt[-1] << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Test empty array
	std::cout << "Test empty array: " << std::endl;
	Array<int> emptyArray;
	std::cout << "Empty array size: " << emptyArray.size() << std::endl;
	try
	{
		std::cout << "emptyArray[0]: " << emptyArray[0] << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Clear memory
	delete[] cpy;

	return (0);
}