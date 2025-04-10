/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:06:50 by ibour             #+#    #+#             */
/*   Updated: 2024/07/24 14:06:51 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Applies a given function on every single element of a given array.
 *
 * @param tab The integer array.
 * @param length The length of the array.
 * @param f The function that will be called for every element on the array.
 */
void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	index;

	index = 0;
	while (index < length)
	{
		f(tab[index]);
		index++;
	}
}

/*#include <stdio.h>
void prnt(int i)
{
	printf("%d", i);
}

int	main(void)
{
	int tab[] = {1,2,3,4,5};
	ft_foreach(tab, 5, &prnt);
}*/