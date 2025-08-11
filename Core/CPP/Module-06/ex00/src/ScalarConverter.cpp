#include "../include/ScalarConverter.h"

#include <cmath>
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

bool isCharacter(const std::string &str, const size_t &length) {
	if (length == 1 && !isdigit(str[0]))
		return true;
	if (length == 3 && str[0] == '\'' && str[2] == '\'')
		return true;
	return false;
}

bool isInteger(const std::string &str, const size_t &length) {
	if (length == 0 || length > 11) return false;
	size_t i = 0;
	if (str[0] == '+' || str[0] == '-') {
		i++;
		if (length == 1) return false;
	} else if (length > 10) return false;
	for (; i < length; i++) {
		if (!std::isdigit(str[i])) return false;
	}
	return true;
}

bool isFloat(const std::string &str, const size_t &length, const size_t &dot) {
	if (dot == 0 || dot >= length - 1) return false;
	for (size_t j = 0; j < dot; j++) {
		if (j == 0) {
			if (!std::isdigit(str[j]) && str[j] != '+' && str[j] != '-') return false;
			if ((str[j] == '+' || str[j] == '-') && dot == 1) return false;
		} else if (!std::isdigit(str[j])) return false;
	}
	bool hasF = false;
	for (size_t i = dot + 1; i < length; i++) {
		if (str[i] == 'f') {
			if (i != length - 1) return false;
			hasF = true;
		} else if (!std::isdigit(str[i])) {
			return false;
		}
	}
	const size_t digitsAfterDot = hasF ? length - dot - 2 : length - dot - 1;
	if (digitsAfterDot == 0) return false;
	return true;
}

bool isOther(const std::string &str) {
	return (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff");
}

void printInteger(const std::string &str, const size_t &length) {

	const long num = std::atol(str.c_str());

	std::cout << "char: ";
	if (length > 127) {
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

	const char c = str[0];

	std::cout << "char: ";
	if (!isprint(c)) {
		std::cout << "Non displayable" << std::endl;
	} else std::cout << "'" << c << "'" << std::endl;

	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;

}

void printFloat(const std::string &str, const size_t &length) {

	const float num = std::atof(str.c_str());
	const bool tolerance = std::fabs(num - static_cast<int>(num)) < 0.0000000000001;

	std::cout << "char: ";
	if (length > 127) {
		std::cout << "Impossible" << std::endl;
	} else if (!isprint(static_cast<int>(num))) {
		std::cout << "Non displayable" << std::endl;
	} else std::cout << "'" << static_cast<char>(num) << "'" << std::endl;

	std::cout << "int: ";
	if (static_cast<int>(num) < INT_MIN || static_cast<int>(num) > INT_MAX) std::cout << "Impossible" << std::endl;
	else std::cout << static_cast<int>(num) << std::endl;

	std::cout << "float: ";
	if (num < MIN_FLOAT || num > MAX_FLOAT) std::cout << "Impossible" << std::endl;
	else std::cout << num << (tolerance ? ".0f" : "f") << std::endl;

	std::cout << "double: " << static_cast<double>(num) << (tolerance ? ".0" : "") << std::endl;

}

void printDouble(const std::string &str, const size_t &length) {

	const double num = std::atof(str.c_str());
	const bool tolerance = std::fabs(num - static_cast<int>(num)) < 0.0000000000001;

	std::cout << "char: ";
	if (length > 127) {
		std::cout << "Impossible" << std::endl;
	} else if (!isprint(static_cast<int>(num))) {
		std::cout << "Non displayable" << std::endl;
	} else std::cout << "'" << static_cast<char>(num) << "'" << std::endl;

	std::cout << "int: ";
	if (static_cast<long>(num) < INT_MIN || static_cast<long>(num) > INT_MAX) std::cout << "Impossible" << std::endl;
	else std::cout << static_cast<int>(num) << std::endl;

	std::cout << "float: ";
	if (num < MIN_FLOAT || num > MAX_FLOAT) std::cout << "Impossible" << std::endl;
	else std::cout << num << (tolerance ? ".0f" : "f") << std::endl;

	std::cout << "double: ";
	if (num < MIN_DOUBLE || num > MAX_DOUBLE) std::cout << "Impossible" << std::endl;
	else std::cout << num << std::endl;

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