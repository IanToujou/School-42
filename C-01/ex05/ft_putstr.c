#include <unistd.h>
#include <stdbool.h>

void	ft_putstr(char *str)
{
	char	c;

	while (true)
	{
		c = *str;
		if (c == '\0')
		{
			break ;
		}
		write(1, &c, 1);
		str++;
	}
}
