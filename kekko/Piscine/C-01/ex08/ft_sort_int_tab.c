/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_sort_int_tab.c >                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 07:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/07/11 07:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	swap;
	int	j;
	int	k;

	k = size - 1;
	i = k;
	j = k;
	while (i >= 0)
	{
		while (j >= 0)
		{
			if (tab[i] > tab[j])
			{
				swap = tab[j];
				tab[j] = tab[i];
				tab[i] = swap;
			}
			j--;
		}
		j = k;
		i--;
	}
}
