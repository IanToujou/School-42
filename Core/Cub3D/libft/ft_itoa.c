/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:47:45 by mpoesy            #+#    #+#             */
/*   Updated: 2024/10/23 14:42:01 by mpoesy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>
static int	getlength(int n)
{
	int	length;

	if (n <= 0)
		length = 1;
	else
		length = 0;
	while (n != 0)
	{
		length++;
		n /= 10;
	}
	return (length);
}

static char	*handle_min_int(void)
{
	char	*str;

	str = (char *)malloc(12);
	if (str)
		ft_strlcpy(str, "-2147483648", 12);
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	int		isneg;

	if (n == -2147483648)
		return (handle_min_int());
	isneg = (n < 0);
	if (isneg)
		n = -n;
	len = getlength(n);
	str = malloc(len + 1 + isneg);
	if (str == NULL)
		return (NULL);
	if (isneg)
		str[0] = '-';
	str[len + isneg] = '\0';
	while (len--)
	{
		str[len + isneg] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
/*
int	main(void)
{
	int test_cases[] = {200, -47, 22220, -0, 0, 2147483647, -2147483648};
	int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
	char *result;

	for (int i = 0; i < num_tests; i++)
	{
		result = ft_itoa(test_cases[i]);
		if (result)
		{
			printf("ft_itoa(%d) = %s\n", test_cases[i], result);
			free(result);
		}
		else
		{
			printf("ft_itoa(%d) failed to allocate memory.\n", test_cases[i]);
		}
	}

	return (0);
}*/
