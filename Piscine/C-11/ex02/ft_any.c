/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:56:05 by ibour             #+#    #+#             */
/*   Updated: 2024/07/29 18:56:06 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_any(char **tab, int (*f)(char*))
{
	int	index;
	int	result;

	index = 0;
	result = 0;
	while (tab[index])
	{
		if ((*f)(tab[index]) != 0)
		{
			result = 1;
			break ;
		}
		index++;
	}
	return (result);
}
