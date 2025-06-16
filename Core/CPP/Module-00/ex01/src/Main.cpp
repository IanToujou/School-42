#include <iostream>

#include "../include/PhoneBook.h"
#include "../include/Contact.h"

int main() {

	std::string cmd;
	std::cout << "Enter your command [ADD, SEARCH, EXIT]:" << std::endl;

	while (std::getline(std::cin, cmd)) {

		if (std::cin.eof()) {
			std::cout << "Exiting..." << std::endl;
			break;
		}

		if (cmd == "EXIT") {
			std::cout << "Bye Bye!" << std::endl;
			break;
		}

		cmd.clear();

	}

	return 0;

}