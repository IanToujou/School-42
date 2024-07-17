#include <unistd.h>

int main(int argc, char** argv)
{
	char	c;

	c = *argv[0];
	while(c != '\0')
	{
		c = *argv[0];
		write(1, &c, 1);
		argv[0]++;
	}
	write(1, "\n", 1);
}