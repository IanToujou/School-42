#include "../include/Harl.h"

int main(int argc, char **argv)
{
	Harl harl;
	if (argc == 2)
		harl.complain(argv[1]);
	else
		harl.complain("Invalid level.");
	return 0;
}