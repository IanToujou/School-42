#include "../include/Harl.h"

#include <iostream>
#include <ostream>

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug() {
	std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!" << std::endl;
}

void	Harl::info() {
	std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger!\nIf you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning() {
	std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error() {
	std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(const std::string& level)
{

	const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*pointers[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	int i = 0;
	for (; i < static_cast<int>(levels->size()); i++)
		if (level == levels[i])
			break;

	switch (i)
	{
		case 0:
			(this->*pointers[0])();
		case 1:
			(this->*pointers[1])();
		case 2:
			(this->*pointers[2])();
		case 3:
			(this->*pointers[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}

}
