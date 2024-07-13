/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cool guys group <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 09:11:41 by ibour             #+#    #+#             */
/*   Updated: 2024/07/13 09:11:43 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

void	ft_putchar(char c);

void	ft_edge(bool inverse, int x, int x_index)
{
	if (x_index == 0)
	{
		if (inverse)
		{
			ft_putchar('\\');
		}
		else
		{
			ft_putchar('/');
		}
	}
	else if (x_index == x - 1)
	{
		if (inverse)
		{
			ft_putchar('/');
		}
		else
		{
			ft_putchar('\\');
		}
	}
}

void	ft_edgeline(int x, int y, int x_index, int y_index)
{
	while (x_index < x)
	{
		if (x_index == 0)
		{
			ft_edge(false, y, y_index);
		}
		else if (x_index == x - 1)
		{
			ft_edge(true, y, y_index);
		}
		else
		{
			ft_putchar('*');
		}
		x_index++;
	}
}

void	ft_midline(int x, int x_index)
{
	ft_putchar('*');
	while (x_index < x - 2)
	{
		ft_putchar(' ');
		x_index++;
	}
	if (x > 1)
	{
		ft_putchar('*');
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
			ft_edgeline(x, y, x_index, y_index);
		}
		else
		{
			ft_midline(x, x_index);
		}
		ft_putchar('\n');
		y_index++;
	}
}
