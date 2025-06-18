#include "../include/PhoneBook.h"

#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() {
	index = 0;
}

PhoneBook::~PhoneBook() = default;

const std::string fields[] = {
	"First Name",
	"Last Name",
	"Nickname",
	"Phone Number",
	"Darkest Secret"
};

void PhoneBook::createContact() {

	Contact contact;
	std::string input;

	if (index > 7) {
		std::cout << "Contact book is full. The oldest contact will be overwritten." << std::endl << "Continue? (y/n) ";
		while (std::getline(std::cin, input)) {
			if (input == "y" || input == "Y") {
				index = 0;
			} else {
				std::cout << "Aborting." << std::endl;
				return;
			}
		}
	}

	std::cout << "Creating Contact #" << index+1 << std::endl;

	for (int i = 0; i < 5; i++) {
		std::cout << "Enter " << fields[i] << ": ";
		std::getline(std::cin, input);

		if (std::cin.eof()) {
			std::cout << "Exiting..." << std::endl;
			exit(0);
		}

		if (i == 0) contact.setFirstName(input);
		else if (i == 1) contact.setLastName(input);
		else if (i == 2) contact.setNickname(input);
		else if (i == 3) contact.setPhoneNumber(input);
		else if (i == 4) contact.setDarkestSecret(input);

	}

	contacts[index] = contact;
	index++;

	std::cout << "Successfully created contact." << std::endl;

}

void PhoneBook::listContacts() const
{

	std::cout << "Fetching contacts..." << std::endl;

	if (index == 0) {
		std::cout << "No contacts were found." << std::endl;
		return;
	}

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;

	for (int i = 0; i < index; i++) {

		std::cout << "|" << std::setw(10) << i+1 << "|";

		if (contacts[i].getFirstName().length() > 10) {
			std::cout << std::setw(10) << contacts[i].getFirstName().substr(0,9) << ".|";
		} else std::cout << std::setw(10) << contacts[i].getFirstName() << "|";

		if (contacts[i].getLastName().length() > 10) {
			std::cout << std::setw(10) << contacts[i].getLastName().substr(0,9) << ".|";
		} else std::cout << std::setw(10) << contacts[i].getLastName() << "|";

		if (contacts[i].getNickname().length() > 10) {
			std::cout << std::setw(10) << contacts[i].getNickname().substr(0,9) << ".|";
		} else std::cout << std::setw(10) << contacts[i].getNickname() << "|";

		std::cout << std::endl;

	}

	std::cout << "---------------------------------------------" << std::endl;

}
