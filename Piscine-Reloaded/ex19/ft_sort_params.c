/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:15:07 by ibour             #+#    #+#             */
/*   Updated: 2024/07/17 14:15:07 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_swap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_sort(char **array, int size, int offset)
{
	int		i;
	bool	swapped;

	while (true)
	{
		i = offset;
		swapped = false;
		while (i < size)
		{
			if (ft_strcmp(array[i], array[i + 1]) > 0)
			{
				ft_swap(&array[i], &array[i + 1]);
				swapped = true;
			}
			i++;
		}
		if (!swapped)
			break ;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc > 2)
		ft_sort(argv, argc - 1, 1);
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putstr("\n");
		i++;
	}
}
