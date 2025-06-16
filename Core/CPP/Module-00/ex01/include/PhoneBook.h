#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "Contact.h"

class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();
private:
	int index;
	Contact contacts[8];
};

#endif