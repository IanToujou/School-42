/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:15:20 by ibour             #+#    #+#             */
/*   Updated: 2024/11/07 13:18:40 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	ft_line_length(const int fd)
{
	char	buffer[1];
	int		length;
	int		bytes;

	buffer[0] = '\0';
	bytes = 1;
	length = 0;
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (buffer[0] != '\n')
			length++;
		else
			break ;
	}
	return (length);
}

static int	ft_count_lines(const int fd, const int x, const int width)
{
	char	*line;
	int		lines;

	lines = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if ((int)ft_strlen(line) < x / width
			|| (ft_strlen(line) == 1 && *line != '\n'))
		{
			free(line);
			ft_handle_error("Error");
			ft_handle_error("Invalid map dimensions.");
			exit(EXIT_FAILURE);
		}
		free(line);
		lines++;
	}
	return (lines);
}

void	ft_render_window(t_data *data, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_handle_error("Error");
		ft_handle_error("Invalid map.");
		exit(EXIT_FAILURE);
	}
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
	{
		ft_handle_error("Error");
		ft_handle_error("Invalid map format.");
		exit(EXIT_FAILURE);
	}
	data->size_x = (ft_line_length(fd) * IMG_W);
	data->size_y = (ft_count_lines(fd, data->size_x, IMG_W) * IMG_H);
}

void	ft_render_map(t_data *data)
{
	data->map->x = 0;
	data->map->y = 0;
	while (data->map->y < (data->size_y / IMG_H))
	{
		if (data->map->map[data->map->y][data->map->x] == 'P')
			ft_render_player(data);
		else if (data->map->map[data->map->y][data->map->x] == '1')
			ft_render_object(data, "./textures/wall.xpm");
		else if (data->map->map[data->map->y][data->map->x] == 'C')
			ft_render_object(data, "./textures/collectable.xpm");
		else if (data->map->map[data->map->y][data->map->x] == 'E')
			ft_render_object(data, "./textures/exit.xpm");
		if (data->map->x < (data->size_x / IMG_W))
			data->map->x++;
		else
		{
			data->map->y++;
			data->map->x = 0;
		}
	}
}

void	ft_render_background(const t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			mlx_put_image_to_window(data->mlx, data->window,
				data->image->background, x, y);
			x += IMG_W;
		}
		y += IMG_H;
	}
}

void	ft_render_object(const t_data *data, char *path)
{
	int		width;
	int		height;

	data->map->object = mlx_xpm_file_to_image(data->mlx, path,
			&width, &height);
	mlx_put_image_to_window(data->mlx, data->window, data->map->object,
		(data->map->x * IMG_W), (data->map->y * IMG_H));
}

void	ft_render_player(t_data *data)
{
	data->p_x = data->map->x;
	data->p_y = data->map->y;
	mlx_put_image_to_window(data->mlx, data->window, data->image->player_up,
		(data->p_x * IMG_W), (data->p_y * IMG_H));
}