/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 07:56:00 by ibour             #+#    #+#             */
/*   Updated: 2025/09/23 10:11:06 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	util_map_parse_width(const char *filename)
{
	int			fd;
	char		buffer[4097];
	int			width;
	int			i;
	ssize_t		j;
	int			in_number;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	if ((j = read(fd, buffer, 4096)) <= 0)
	{
		close(fd);
		return (0);
	}
	buffer[j] = '\0';
	width = 0;
	i = 0;
	in_number = 0;

	while (buffer[i] && buffer[i] != '\n')
	{
		if (buffer[i] == ' ' || buffer[i] == '\t')
		{
			if (in_number)
			{
				width++;
				in_number = 0;
			}
		}
		else
		{
			in_number = 1;
		}
		i++;
	}
	if (in_number)
		width++;
	close(fd);
	return (width);
}

int	util_map_parse_depth(const int fd)
{
	char		buffer[4097];
	int			lines;
	int			i;
	ssize_t		j;

	if ((j = read(fd, buffer, 4096)) <= 0)
		return (0);
	buffer[j] = 0;
	lines = 1;
	while (j > 0)
	{
		i = -1;
		while (buffer[++i])
			lines += (buffer[i] == '\n');
		j = read(fd, buffer, 4096);
	}
	return (lines);
}
