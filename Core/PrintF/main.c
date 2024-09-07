// TODO Remove test

#include "ft_printf.h"

#include <stdio.h>

int	main()
{
	int i = 5;
	int *ptr = &i;

	printf("addr: %p\n", ptr);
	ft_printf("Hello %c\n", 'a');
	ft_printf("Pointer addr is: %p\n", ptr);

}