#include <iostream>
#include <ostream>

#include "../include/whatever.h"

int main() {

	std::cout << min(3, 2) << std::endl;
	std::cout << max(3, 2) << std::endl;

	int a = 10;
	int b = 5;
	swap(a, b);

	std::cout << a << std::endl;

	return 0;

}