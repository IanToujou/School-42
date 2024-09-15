#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	int x = 2;
	int* p = &x;
	printf("%p\n", p);
	ft_printf("Num1: %d and num2: %d\n", 73, -931);
	ft_printf("Ptr: %p\n", p);
}