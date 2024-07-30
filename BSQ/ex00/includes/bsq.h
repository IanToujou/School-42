/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:47:28 by ibour             #+#    #+#             */
/*   Updated: 2024/07/30 13:47:29 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# define IN 0
# define OUT 1
# define ERR 2
# define UINT unsigned int
# define ULNG unsigned long
# define UCHR unsigned char

typedef enum t_bool
{
    false,
    true
}   t_bool;

typedef struct s_grid
{
    UINT    width;
    UINT    height;
    char    *src;
    UCHR    **map;
    UCHR    translate[3];
}   t_grid;

typedef struct	s_solution {
    UINT	size;
    UINT	x;
    UINT	y;
}   t_solution;

typedef	enum {
    empty,
    obstacle,
    fill,
}	t_block;

int             parse_grid(int fd, t_grid *grid);
void            process_grid(t_grid *grid, t_solution *solution);
void            free_grid(t_grid *grid);
static t_bool   fits(const t_solution *intent, const t_grid *grid);
static t_bool   fits_success(t_solution *intent, t_grid *grid);
static void     actualize_solution(t_solution *solution, t_solution *intent, t_grid *grid);
t_bool          find_solution(t_grid *grid, t_solution *solution);
static t_bool	dont_fit_basic(const t_solution *intent, const t_grid *grid);

#endif