#include "Harl.hpp"

int main()
{
	Harl	harl;

	std::cout << "Harl's favorite sentences." << std::endl << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;
	// harl.complain("something else");
	// std::cout << std::endl;
	std::cout << "Now you have 4 chances to make harl say something." << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << "Your turn: ";
		std::string input;
		getline(std::cin, input);
		if (std::cin.eof() == true)
		{
			std::cerr << "^D" << std::endl;
			exit(EXIT_FAILURE);
		}
		harl.complain(input);
		std::cout << std::endl;
	}
	return (EXIT_SUCCESS);
}