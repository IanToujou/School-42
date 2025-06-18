#include <iostream>
#include "../include/PhoneBook.h"
#include "../include/Contact.h"

int main() {

	PhoneBook book;
	std::string input;

	std::cout << "Enter your command [ADD, SEARCH, EXIT]: ";

	while (std::getline(std::cin, input)) {

		std::cout << std::endl;

		if (std::cin.eof()) {
			std::cout << "Exiting..." << std::endl;
			break;
		}

		if (input == "ADD") {
			book.createContact();
		} else if (input == "SEARCH") {
			book.listContacts();
		} else if (input == "EXIT") {
			std::cout << "Bye Bye!" << std::endl;
			break;
		} else {
			std::cout << "Invalid command." << std::endl;
		}

		input.clear();
		std::cout << "Enter your command [ADD, SEARCH, EXIT]: ";

	}

	return 0;

}