/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:12:02 by ibour             #+#    #+#             */
/*   Updated: 2024/07/29 19:12:02 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		index;
	int		sorted;

	sorted = 1;
	index = 0;
	while (index < length - 1 && sorted)
	{
		if ((*f)(tab[index], tab[index + 1]) < 0)
			sorted = 0;
		index++;
	}
	if (sorted != 1)
	{
		index = 0;
		while (index < length - 1)
		{
			if ((*f)(tab[index], tab[index + 1]) > 0)
				return (0);
			index++;
		}
	}
	return (1);
}
