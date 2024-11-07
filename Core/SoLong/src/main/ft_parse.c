/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:53:19 by ibour             #+#    #+#             */
/*   Updated: 2024/11/07 14:02:43 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	ft_throw_error_map(const char *error_msg)
{
	ft_handle_error("Error");
	ft_handle_error(error_msg);
	exit(EXIT_FAILURE);
}

static int	ft_count_c(char *s, const char c)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	if (!s)
		return (-1);
	while (s && s[i])
	{
		if (s[i++] == c)
			x++;
	}
	return (x);
}

static void	ft_check_borders(const t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < (data->size_y / IMG_H))
	{
		if ((int)ft_strlen(data->map->map[y]) != data->size_x / IMG_W)
			ft_throw_error_map("Map has to be rectangular.");
		x = 0;
		while (x < (data->size_x / IMG_W))
		{
			if (data->map->map[y][x] != '0' && data->map->map[y][x] != '1' &&
				data->map->map[y][x] != 'C' && data->map->map[y][x] != 'P' &&
				data->map->map[y][x] != 'E')
				ft_throw_error_map("Only the following characters are valid for a map: 0, 1, C, P, E.");
			else if ((y == 0 || x == 0) && data->map->map[y][x] != '1')
				ft_throw_error_map("The map has to be surrounded by walls.");
			else if ((y == (data->size_y / IMG_H - 1)
					|| x == (data->size_x / IMG_W - 1))
				&& data->map->map[y][x] != '1')
				ft_throw_error_map("The map has to be surrounded by walls.");
			x++;
		}
		y++;
	}
}

static void	ft_check_content(const t_data *data)
{
	int	y;
	int	exit;
	int	player;

	exit = 0;
	player = 0;
	data->map->collectibles = 0;
	y = 0;
	printf("A\n"); fflush(stdout);
	while (data->map->map && data->map->map[y])
	{
		printf("B\n"); fflush(stdout);
		exit += ft_count_c(data->map->map[y], 'E');
		printf("exits: %d\n", exit); fflush(stdout);
		player += ft_count_c(data->map->map[y], 'P');
		data->map->collectibles += ft_count_c(data->map->map[y], 'C');
		y++;
	}
	if (player != 1)
		ft_throw_error_map("Only valid map if one player is contained.");
	if (exit == 0)
		ft_throw_error_map("Only valid map if at least one exit is contained.");
	if (data->map->collectibles == 0)
		ft_throw_error_map("Only valid map if at least one coin is contained.");
}

static void	ft_throw_error_usage(const int argc)
{
	if (argc != 2)
	{
		ft_handle_error("Error");
		ft_handle_error("Usage: ./so_long <map>");
		exit(EXIT_FAILURE);
	}
}

void	ft_parse_map(const t_data *data, char **argv, const int argc)
{
	int		fd;
	int		i;
	int		bytes;
	char	buffer[2];

	ft_throw_error_usage(argc);
	i = 0;
	buffer[1] = '\0';
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		bytes = read(fd, buffer, 1);
		if (bytes != 1)
			break ;
		if (buffer[0] != '\n' && buffer[0] != '\0')
		{
			data->map->map[i] = ft_strjoin(data->map->map[i], buffer);
		}
		else
			i++;
	}
	ft_check_content(data);
	ft_check_borders(data);
}