/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:47:28 by ibour             #+#    #+#             */
/*   Updated: 2024/07/30 13:47:29 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

t_bool	ft_parse_header_line(t_grid *grid, char *line, UINT length)
{
	t_bool	result;

	if (length < 4)
		return (false);
	grid->translate[fill] = line[length - 1];
	grid->translate[obstacle] = line[length - 2];
	grid->translate[empty] = line[length - 3];
	result = atoi_n_strict(line, length - 3, &(grid->height));
	return (result);
}

t_bool	ft_parse_normal_line(t_grid *grid, char *line, UINT length)
{
	UINT	index;
	char	current;

	if (length < 1)
		return (false);
	grid->width = length;
	index = 0;
	while (index < length)
	{
		current = line[index];
		if (current != grid->translate[empty]
				&& current != grid->translate[obstacle]
				&& current != grid->translate[fill])
			return (false);
		index++;
	}
	return (true);
}

t_bool	ft_has_width_changed(t_grid *grid, UINT *curr_w)
{
	if (*curr_w == (UINT)-1)
		*curr_w = grid->width;
	return (*curr_w != grid->width);
}

t_bool	ft_process_lines(t_grid *grid, UINT index,
							char *file_content, UINT total)
{
	UINT	jndex;
	UINT	y;
	UINT	curr_w;

	y = 0;
	curr_w = -1;
	while (index < total && y < grid->height)
	{
		jndex = index;
		while (file_content[jndex] != '\n')
			if (jndex++ + 1 >= total)
				return (false);
		if (ft_parse_normal_line(grid, file_content + index, jndex - index))
		{
			grid->map[y++] = (UCHR *)(file_content + index);
			if (ft_has_width_changed(grid, &curr_w))
				return (false);
		}
		else
			return (false);
		index = jndex + 1;
	}
	return (y == grid->height);
}

t_bool parse_grid(int fd, t_grid *grid)
{
    char    *content;
    UINT    total;
    UINT    index;

    grid->map = 0;
    if (!read_full(fd, &content, &total)) {
    	return (false);
    }
	grid->src = content;
	index = 0;
	while (index < total) {
		if (content[index] == '\n')
		{
			if (!ft_parse_header_line(grid, content, index))
				return (false);
			if (!(grid->map = malloc(sizeof(char *) * grid->height)))
				return (false);
			return (ft_process_lines(grid, index + 1, content, total));
		}
		index++;
	}
	return (false);

}