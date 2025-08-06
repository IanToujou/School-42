#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H
#include <string>
#include <limits>

# define MIN_INT std::numeric_limits<int>::min()
# define MAX_INT std::numeric_limits<int>::max()
# define MIN_FLOAT std::numeric_limits<float>::min()
# define MAX_FLOAT std::numeric_limits<float>::max()
# define MIN_DOUBLE std::numeric_limits<double>::min()
# define MAX_DOUBLE std::numeric_limits<double>::max()

enum type {
	NONE,
	CHAR,
	INT,
	DOUBLE,
	FLOAT,
	OTHER
};

class ScalarConverter {
	ScalarConverter();
	ScalarConverter(const ScalarConverter &src);
	ScalarConverter &operator=(const ScalarConverter &src);
	~ScalarConverter();
public:
	static void convert(const std::string &str);
};

type getType(const std::string &str, const size_t &length);
void printInteger(const std::string &str, const size_t &length);
void printCharacter(const std::string &str, const size_t &length);
void printFloat(const std::string &str, const size_t &length);
void printDouble(const std::string &str, const size_t &length);
void printOther(const std::string &str);

bool isOther(const std::string &str);
bool isInteger(const std::string &str, const size_t &length);
bool isCharacter(const std::string &str, const size_t &length);
bool isFloat(const std::string &str, const size_t &length, const size_t &dot);

#endif