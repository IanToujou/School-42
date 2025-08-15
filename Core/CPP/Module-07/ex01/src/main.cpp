#include <iostream>
#include <ostream>

#include "../include/Iter.h"

void increase(int &num) {
	num++;
}

void decrease(int &num) {
	num--;
}

void printArray(const int *array, const int size) {
	std::cout << "Array: [ ";
	for (int i = 0; i < size; i++)
		std::cout << array[i] << " ";
	std::cout << "]" << std::endl;
}

int main() {

	int array[] = {1, 2, 3, 4, 5};
	printArray(array, 5);

	iter(array, 5, increase);
	printArray(array, 5);

	iter(array, 6, decrease);
	printArray(array, 5);

	return 0;

}