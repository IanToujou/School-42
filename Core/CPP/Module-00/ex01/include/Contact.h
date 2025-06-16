#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
	public:
		Contact();
		~Contact();
		bool setContact(int index) const;
		void getContact();
private:
	int firstName;
	int lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
};

#endif