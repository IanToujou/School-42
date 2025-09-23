/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 07:56:00 by ibour             #+#    #+#             */
/*   Updated: 2025/09/23 10:47:39 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static int	count_width_line(const char *line)
{
	int	i;
	int	width;
	int	in_number;

	i = 0;
	width = 0;
	in_number = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == ' ' || line[i] == '\t')
		{
			if (in_number)
			{
				width++;
				in_number = 0;
			}
		}
		else
			in_number = 1;
		i++;
	}
	if (in_number)
		width++;
	return (width);
}

static ssize_t	read_first_line(const char *filename, char *buffer, size_t size)
{
	int		fd;
	ssize_t	bytes;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	bytes = read(fd, buffer, size - 1);
	close(fd);
	if (bytes > 0)
		buffer[bytes] = '\0';
	return (bytes);
}

int	util_map_parse_width(const char *filename)
{
	char	buffer[4097];
	ssize_t	len;

	len = read_first_line(filename, buffer, sizeof(buffer));
	if (len <= 0)
		return (0);
	return (count_width_line(buffer));
}

int	util_map_parse_depth(const int fd)
{
	char		buffer[4097];
	int			lines;
	int			i;
	ssize_t		j;

	j = read(fd, buffer, 4096);
	if (j <= 0)
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
