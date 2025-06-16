#ifndef PHONEBOOK_H
#define PHONEBOOK_H

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();
	private:
		int _index;
		bool _full;
};

#endif