/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cool guys group <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 09:11:41 by ibour             #+#    #+#             */
/*   Updated: 2024/07/13 09:11:43 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

void	ft_putchar(char c);

void	ft_top_edgeline(bool invert)
{
	if (invert)
	{
		ft_putchar('C');
	}
	else
	{
		ft_putchar('A');
	}
}

void	ft_bottom_edgeline(bool invert)
{
	if (invert)
	{
		ft_putchar('A');
	}
	else
	{
		ft_putchar('C');
	}
}

void	ft_edgeline(int x, int x_index, bool invert)
{
	while (x_index < x)
	{
		if (x_index == 0)
		{
			ft_top_edgeline(invert);
		}
		else if (x_index == x - 1)
		{
			ft_bottom_edgeline(invert);
		}
		else
		{
			ft_putchar('B');
		}
		x_index++;
	}
}

void	ft_midline(int x, int x_index)
{
	ft_putchar('B');
	while (x_index < x - 2)
	{
		ft_putchar(' ');
		x_index++;
	}
	if (x > 1)
	{
		ft_putchar('B');
	}
}

void	rush(int x, int y)
{
	int	x_index;
	int	y_index;

	y_index = 0;
	if (x < 1 || y < 1)
	{
		return ;
	}
	while (y_index < y)
	{
		x_index = 0;
		if (y_index == 0 || y_index == y - 1)
		{
			ft_edgeline(x, x_index, y_index == y - 1);
		}
		else
		{
			ft_midline(x, x_index);
		}
		ft_putchar('\n');
		y_index++;
	}
}
