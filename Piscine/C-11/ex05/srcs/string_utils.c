/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:48:28 by ibour             #+#    #+#             */
/*   Updated: 2024/07/29 19:48:29 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/do_op.h"

/**
 * Writes a character into an output stream. It will NOT add
 * new lines automatically.
 *
 * @param fd The destination to write to. 0 is the input,
 * 1 the default out, and 2 the error output.
 * @param c The character that you want to write.
 */
void	ft_putchar(const int fd, const char c)
{
	write(fd, &c, 1);
}

void	ft_putstr(const int fd, const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(fd, str[i]);
		i++;
	}
}

int	ft_putnbr(const int fd, const int nb)
{
	if (nb == -2147483648)
	{
		ft_putnbr(fd, nb / 10);
		ft_putchar(fd, '8');
	}
	else if (nb < 0)
	{
		ft_putchar(fd, '-');
		ft_putnbr(fd, -nb);
	}
	else
	{
		if (nb > 9)
			ft_putnbr(fd, nb / 10);
		ft_putchar(fd, 48 + nb % 10);
	}
	return (0);
}
