// TODO Remove test

#include "ft_printf.h"

#include <stdio.h>

int	main()
{
	int x = 1;
	int	*i = &x;

	ft_printf("%p and %s\n", i, "simon is gay");

}