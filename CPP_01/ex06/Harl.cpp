#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger!\nIf you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	void    (Harl::*functionptrs[])( void ) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string messages[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i = 0;
	for (; i < 4; i++)
	{
		if (messages[i] == level)
			break ;
	}
	
	switch(i)
	{
		case(0):
			(this->*functionptrs[0])();
			std::cout << std::endl;
		case(1):
			(this->*functionptrs[1])();
			std::cout << std::endl;
		case(2):
			(this->*functionptrs[2])();
			std::cout << std::endl;
		case(3):
			(this->*functionptrs[3])();
			std::cout << std::endl;
		break;
		
		default:
			std::cout << "[ Probably complaining about insignificant problems ] " << std::endl;
		break;
	}
}