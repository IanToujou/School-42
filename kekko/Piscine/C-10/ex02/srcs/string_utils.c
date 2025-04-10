/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:46:34 by ibour             #+#    #+#             */
/*   Updated: 2024/07/25 13:46:36 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "../includes/ft_tail.h"

/**
 * Writes a character into an output stream. It will NOT add new lines automatically.
 *
 * @param fd The destination to write to. 0 is the input, 1 the default out, and 2 the error output.
 * @param c The character that you want to write.
 */
void	ft_putchar(int fd, char c)
{
	write(fd, &c, 1);
}

void	ft_putstr(int fd, char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0') {
		ft_putchar(fd, str[i]);
		i++;
	}
}

void	ft_putstr_buffer(int fd, char *str, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		ft_putchar(fd, str[i]);
}

void	handle_error(char **argv)
{
	ft_putstr(ERR, basename(argv[0]));
	ft_putstr(ERR, ": cannot open '");
	ft_putstr(ERR, basename(argv[1]));
	ft_putstr(ERR, "' for reading: ");
	ft_putstr(ERR, strerror(errno));
	ft_putchar(ERR, '\n');
}