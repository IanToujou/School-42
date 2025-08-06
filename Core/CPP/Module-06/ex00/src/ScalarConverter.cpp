#include "../include/ScalarConverter.h"

#include <iostream>
#include <ostream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
	if (&src == this)
		return *this;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &str) {
	const size_t length = str.length();
	switch (getType(str, length)) {
		case CHAR:
			printCharacter(str, length);
		case INT:
			printInteger(str, length);
		case FLOAT:
			printFloat(str, length);
		case DOUBLE:
			printDouble(str, length);
		case OTHER:
			printOther(str);
		default:
			std::cout << "Invalid type" << std::endl;
	}
}

type getType(const std::string &str, const size_t &length) {

	const size_t dot = str.find('.');
	const size_t f = str.find('f');

	if (str.find('.') == std::string::npos) {
		if (isOther(str)) return OTHER;
		if (isCharacter(str, length)) return CHAR;
		if (isInteger(str, length)) return INT;
	}

	if (f != std::string::npos && dot != std::string::npos) {
		if (isFloat(str, length, dot)) return FLOAT;
	}

	if (f == std::string::npos && dot != std::string::npos) {
		return DOUBLE;
	}

	return NONE;

}

bool isOther(const std::string &str) {
	return (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff");
}

void printInteger(const std::string &str, const size_t &length) {

	const long num = std::atol(str.c_str());

	std::cout << "char: ";
	if (length < 0 || length > 127) {
		std::cout << "Impossible" << std::endl;
	} else if (!isprint(num)) {
		std::cout << "Non displayable" << std::endl;
	} else std::cout << "'" << static_cast<char>(num) << "'" << std::endl;

	std::cout << "int: ";
	if (num < MIN_INT || num > MAX_INT) std::cout << "Impossible" << std::endl;
	else std::cout << static_cast<int>(num) << std::endl;

	std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;

}

void printCharacter(const std::string &str, const size_t &length) {

	char c = str[0];
	if (length != 1) c = str[1];

	std::cout << "char: ";
	if (!isprint(c)) {
		std::cout << "Non displayable" << std::endl;
	} else std::cout << c << std::endl;

	std::cout << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;

}

void printFloat(const std::string &str, const size_t &length) {

}

void printDouble(const std::string &str, const size_t &length) {

}

void printOther(const std::string &str) {

	if (str == "nan" || str == "nanf") {
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	} else if (str == "+inf" || str == "+inff") {
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	} else if (str == "-inf" || str == "-inff") {
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;

	}
}