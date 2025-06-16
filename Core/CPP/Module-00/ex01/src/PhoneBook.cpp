#include "../include/PhoneBook.h"

#include <iostream>

PhoneBook::PhoneBook() {

	index = 0;
	full = false;

}

PhoneBook::~PhoneBook() = default;

void PhoneBook::createContact() {

	std::string input;

	if (!full) {

		std::cout << "Creating Contact #" << index+1 << std::endl;

		for (int i = 0; i < 5; i++) {

			std::cout << "Enter Name: ";

			std::getline(std::cin, input);

			if (std::cin.eof()) {
				std::cout << "Exiting..." << std::endl;
				exit(0);
			}



		}

	}

}