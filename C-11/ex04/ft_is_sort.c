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

/**
 *
 *
 * @param tab AN array of integers that will be checked if it is sorted.
 * @param length The length of the provided array.
 * @param f A function to sort the array.
 * @return
 */
int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	index;

	if(length <= 1)
		return (0);

	index = 0;
	while (index < length - 1) {
		if (f(tab[index], tab[index + 1]) > 0)
			return (0);
		index++;
	}
	return (1);
}