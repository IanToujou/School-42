/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:47:28 by ibour             #+#    #+#             */
/*   Updated: 2024/07/30 13:47:29 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

t_bool  load_grid(char *path, t_grid *grid)
{
    int		fd;
    t_bool	result;

    fd = open(path, O_RDONLY);
    if (fd < 0)
        return (false);
    result = parse_grid(fd, grid);
    close(fd);
    return (result);
}

void    free_grid(t_grid *grid)
{
    free(grid->map);
    free(grid->src);
}

void    process_grid(t_grid *grid, t_solution *solution)
{
    UINT    x;
    UINT    y;

    if (find_solution(grid, solution))
    {
        x = solution->x;
        while (x < solution->x + solution->size)
        {
            y = solution->y;
            while (y < solution->y + solution->size)
            {
                grid->map[y][x] = grid->translate[fill];
                y++;
            }
            x++;
        }
        y = 0;
        while (y < grid->height)
        {
            write(OUT, grid->map[y], grid->width);
            write(OUT, "\n", 1);
            y++;
        }
    }

}