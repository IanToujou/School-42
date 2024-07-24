/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:06:50 by ibour             #+#    #+#             */
/*   Updated: 2024/07/24 14:06:51 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>

void	ft_write_io(const int n, const char *str)
{
	while (*str != '\0')
	{
		write(n, str, 1);
		str++;
	}
}

bool	read_file(char *path)
{
	int				file;
	unsigned int	byte_read;
	char			buffer[4097];

	file = open(path, O_RDONLY);
	if (file < 0)
		return (false);
	byte_read = read(file, buffer, 4096);
	while (byte_read != 0)
	{
		byte_read = read(file, buffer, 4096);
		if (byte_read == (unsigned int) -1)
			break ;
		ft_write_io(STDOUT_FILENO, buffer);
	}
	close(file);
	return (true);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		ft_write_io(STDERR_FILENO, "Not enough arguments.\n");
	else if (argc > 2)
		ft_write_io(STDERR_FILENO, "Too many arguments.\n");
	else
	{
		if (!read_file(argv[1]))
			ft_write_io(STDERR_FILENO, "File could not be read.\n");
		else
			return (0);
	}
	return (1);
}
