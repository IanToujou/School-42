/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abredimu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:39:27 by abredimu          #+#    #+#             */
/*   Updated: 2024/07/23 15:24:22 by abredimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	min(int a, int b)
{
	if (a < b)
	{
		return (a);
	}
	else
	{
		return (b);
	}
}

void	sqrt_segmentation(int nb, int *min, int *max)
{
	int	power_of_ten;

	power_of_ten = 0;
	while (nb > 0)
	{
		nb /= 10;
		power_of_ten++;
	}
	power_of_ten = power_of_ten >> 1;
	nb = 1;
	while (power_of_ten > 0)
	{
		nb *= 10;
		power_of_ten -= 1;
	}
	*min = nb / 10;
	*max = nb;
}

int	binary_search(int nb, int min, int max)
{
	int	middle;
	int	square;

	while (min <= max)
	{
		middle = (min + max) >> 1;
		square = middle * middle;
		if (square == nb)
		{
			return (middle);
		}
		else if (square < nb)
		{
			min = middle + 1;
		}
		else
		{
			max = middle - 1;
		}
	}
	return (0);
}

int	ft_sqrt(int nb)
{
	int	min_segment;
	int	max_segment;

	if (nb <= 0)
	{
		return (0);
	}
	else if (nb == 1)
	{
		return (1);
	}
	sqrt_segmentation(nb, &min_segment, &max_segment);
	max_segment = min(nb / 2, 46340);
	return (binary_search(nb, min_segment, max_segment));
}

int shitty_old_sqrt_for_comparison(int nb)
{
	int i;
	int max_segment;

	if (nb == 0 || nb == 1)
	{
		return (nb);
	}
	i = 2;
	max_segment = min(nb / 2, 46340);
	while (i <= max_segment)
	{
		if (i * i == nb)
		{
			return (nb);
		}
	}
	return (0);
}

#include <stdio.h>
void	test(int nb)
{
	printf("Pure int square root of %i: %i\n", nb, ft_sqrt(nb));
}

int	main(void) {
	int	i;

	i = 0;
	while(i < 10000)
	{
		test(-10);
		test(1);
		test(2);
		test(4);
		test(5);
		test(8);
		test(9);
		test(10);
		test(16);
		test(25);
		test(27);
		test(49);
		test(55);
		test(81);
		test(101);
		test(121);
		test(1000);
		test(10000);
		test(1000000);
		test(10000000);
		test(15438593);
		test(50623225);
		test(85266756);
		test(174292804);
		test(234089140);
		test(373610241);
		test(647232704);
		test(1156767759);
		test(1442259271);
		test(1562779024);
		test(1640045925);
		test(1945143530);
		test(2147395600);
		test(2147483647);
		i++;
	}
	return (0);
}
