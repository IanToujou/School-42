/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:15:07 by ibour             #+#    #+#             */
/*   Updated: 2024/07/17 14:15:07 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*result;

	if (min >= max)
		return (0);
	i = max - min;
	result = (int *) malloc(sizeof(int) * (i));
	if (!result)
		return (NULL);
	i = 0;
	while (min < max)
	{
		result[i] = min;
		min++;
		i++;
	}
	return (result);
}
