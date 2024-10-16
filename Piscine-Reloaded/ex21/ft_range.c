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
	int	*result;
	int	i;

	if (min >= max)
		return (NULL);
	result = (int *) malloc(sizeof(int) * (max - min - 1));
	if (!result)
		return (NULL);
	i = 0;
	while (min + i < max)
	{
		result[i] = min + i;
		i++;
	}
	return (result);
}
