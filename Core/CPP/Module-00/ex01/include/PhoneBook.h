#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "Contact.h"

class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();
private:
	int index;
	bool full;
	Contact contacts[8];
	void createContact();
};

#endif