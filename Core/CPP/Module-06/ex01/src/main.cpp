#include <iostream>
#include <ostream>

#include "../include/Serializer.h"

int main() {

	Data *data = new Data();
	data->account = "3842-3951-0380";
	data->amount = 2000;
	data->holder = "Max Mustermann";

	const uintptr_t raw = Serializer::serialize(data);
	const Data *serialized = Serializer::deserialize(raw);

	std::cout << "Account: " << serialized->account << std::endl;
	std::cout << "Amount: " << serialized->amount << std::endl;
	std::cout << "Holder: " << serialized->holder << std::endl;

	delete data;

	return 0;

}
