#include <iostream>
#include <ostream>

#include "../include/ScalarConverter.h"

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << "Usage: ./ScalarConverter <number>" << std::endl;
		std::cout << "Valid types are: int, double, float, char" << std::endl;
		return 1;
	}

	ScalarConverter::convert(argv[1]);
	return 0;

}
