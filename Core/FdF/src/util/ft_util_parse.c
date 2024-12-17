/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 07:56:24 by ibour             #+#    #+#             */
/*   Updated: 2024/12/17 08:17:15 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static int	ft_util_parse_cols(int fd, t_map *map, char *line)
{
	char	**tab;
	char	*temp;
	int		i;

	temp = ft_strdup(line);
	free(line);
	if (!temp)
		ft_throw_error(ERROR_MALLOC); // todo add free
	tab = ft_split(temp, ' ');
	free(temp);
	if (!tab)
		ft_throw_error(ERROR_MALLOC); // todo add free
	i = 0;
	while (tab[i]) {
		map->high = ft_max(map->high, ft_atoi(tab[i]));
		map->low = ft_min(map->low, ft_atoi(tab[i]));
		i++;
	}
	ft_free_tab((void **) tab, i);
	return (i);
}

void	ft_util_parse_dimensions(int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		ft_throw_error(ERROR_INIT_MAP); // todo add free
	map->cols = ft_util_parse_cols(fd, map, line);
	if(map->cols == 0)
		ft_throw_error(ERROR_INIT_MAP); // todo add free
	map->rows = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->rows++;
		if (map->cols != ft_util_parse_cols(fd, map, line))
			ft_throw_error(ERROR_INIT_MAP); // todo add free
	}
}
