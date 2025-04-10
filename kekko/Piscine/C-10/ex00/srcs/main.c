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

#include "../includes/display_file.h"

bool	read_file(const char *path)
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
		ft_putstr(OUT, buffer);
	}
	close(file);
	return (true);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		ft_putstr(ERR, MSG_ERR_NAME_MISSING);
	else if (argc > 2)
		ft_putstr(ERR, MSG_ERR_TOO_MANY_ARGS);
	else
	{
		if (!read_file(argv[1]))
			ft_putstr(ERR, MSG_ERR_CANNOT_READ);
		else
			return (0);
	}
	return (1);
}
