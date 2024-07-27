//
// Created by ibour on 7/27/24.
//

#include "../includes/ft_string_utils.h"
#include "../includes/ft_convert.h"

unsigned long	ft_atoi_strict(char *str)
{
	unsigned long	result;

	while (ft_is_whitespace(*str))
		str++;
	result = 0;
	while (ft_is_number(*str))
	{
		result *= 10;
		result += (*str) - '0';
		str++;
	}
	if (*str == '\0')
		return (result);
	return (-1);
}