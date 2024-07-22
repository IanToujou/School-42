/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:41:00 by ibour             #+#    #+#             */
/*   Updated: 2024/07/18 09:41:01 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	index;
	int	*buffer;

	if (min >= max)
		return (NULL);
	buffer = (int *) malloc((max - min) * sizeof(*buffer));
	if (buffer == NULL)
		return (NULL);
	index = 0;
	while (index <= max - min)
	{
		buffer[index] = min + index;
		index++;
	}
	return (buffer);
}

/*#include <stdio.h>
void	debug_dump_array(int numbers[], int size)
{
	int index;

	printf("[ ");
	index = 0;
	while (index < size)
	{
		printf("%d", numbers[index]);
		if (index != size - 1)
		{
			printf(", ");
		}
		index++;
	}
	printf(" ]");
}

int	main(void)
{
	int	min;
	int	max;

	min = -10;
	max = -4;
	printf("min = %d, max = %d -> ", min, max);
	debug_dump_array(ft_range(min, max), max - min);
}*/