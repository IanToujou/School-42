#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "Contact.h"

class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();
	void createContact();
	void listContacts() const;
private:
	int index;
	Contact contacts[8];
};

#endif