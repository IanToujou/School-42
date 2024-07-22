/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:57:23 by ibour             #+#    #+#             */
/*   Updated: 2024/07/21 15:57:24 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*buffer;
	int	i;
	int	bound;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	bound = max - min;
	buffer = (int *) malloc(bound * sizeof(*buffer));
	if (buffer == NULL)
	{
		return (-1);
	}
	i = 0;
	while (i < bound)
	{
		buffer[i] = min + i;
		i++;
	}
	*range = buffer;
	return (i);
}

/*int		main(void)
{
	int	min;
	int	max;
	int	*range;
	int	bound;

	min = 5;
	max = 10;
	bound = ft_ultimate_range(&range, min, max);
	printf("min = %d, max = %d -> (bound = %d) ", min, max, bound);
}
*/