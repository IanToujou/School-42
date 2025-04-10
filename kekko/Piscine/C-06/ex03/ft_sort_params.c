/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 07:47:38 by ibour             #+#    #+#             */
/*   Updated: 2024/07/18 07:47:39 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
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
	int		index;
	bool	swapped;

	while (true)
	{
		index = offset;
		swapped = false;
		while (index < size)
		{
			if (ft_strcmp(array[index], array[index + 1]) > 0)
			{
				ft_swap(&array[index], &array[index + 1]);
				swapped = true;
			}
			index++;
		}
		if (!swapped)
		{
			break ;
		}
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
