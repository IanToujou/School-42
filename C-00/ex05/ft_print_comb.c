/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <ianbour2016@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:03:12 by ibour             #+#    #+#             */
/*   Updated: 2024/07/10 12:22:30 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

void	ft_print_comb(void);
void	ft_putchar(char c);
void	ft_out(char c1, char c2, char c3);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_out(char c1, char c2, char c3)
{
	ft_putchar(c1);
	ft_putchar(c2);
	ft_putchar(c3);
	if (c1 != '7' || c2 != '8' || c3 != '9')
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	char	c1;
	char	c2;
	char	c3;

	c1 = '0';
	while (c1 <= '7')
	{
		c2 = c1 + 1;
		while (c2 <= '8')
		{
			c3 = c2 + 1;
			while (c3 <= '9')
			{
				ft_out(c1, c2, c3);
				c3++;
			}
			c2++;
		}
		c1++;
	}
}
