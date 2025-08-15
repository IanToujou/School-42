#include <string>
#include <ctime>
#include <iostream>

#include "../include/Array.h"

int main() {

    Array<int> array(5);
    Array<int> mirror(5);

    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        array[i] = rand();
        mirror[i] = rand();
    }

    std::cout << "Array: " << std::endl;

    return 0;

}