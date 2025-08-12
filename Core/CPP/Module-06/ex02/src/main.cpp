#include "../include/Base.h"
#include "../include/A.h"
#include "../include/B.h"
#include "../include/C.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base *generate() {
	const int i = rand() % 3;
	if (i == 0) return new A();
	if (i == 1) return new B();
	return new C();
}

void identify(Base *p) {
	if (dynamic_cast<A *>(p)) std::cout << "A" << std::endl;
	if (dynamic_cast<B *>(p)) std::cout << "B" << std::endl;
	if (dynamic_cast<C *>(p)) std::cout << "C" << std::endl;
}

void identify(Base &p) {
	try {
		A &a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (std::exception &exception) {}
	try {
		B &b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	} catch (std::exception &exception) {}
	try {
		C &c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	} catch (std::exception &exception) {}
}

int main() {

	srand(time(NULL));
	Base *base = generate();
	Base &reference = *base;

	identify(base);
	identify(reference);

	delete base;

}