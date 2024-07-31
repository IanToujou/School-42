/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:47:28 by ibour             #+#    #+#             */
/*   Updated: 2024/07/30 13:47:29 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

t_bool	find_solution(t_grid *grid, t_solution *solution)
{
	UINT		i;
	UINT		j;
	t_solution	intent;

	i = 0;
	solution->size = 0;
	intent.size = 1;
	while (i < grid->height - solution->size)
	{
		j = 0;
		while (j < grid->width - solution->size)
		{
			intent.x = j;
			intent.y = i;
			actualize_solution(solution, &intent, grid);
			j++;
		}
		i++;
	}
	if (solution->size)
		return (true);
	return (false);
}

void	actualize_solution(t_solution *sol, t_solution *in, t_grid *g)
{
	if (!fits(in, g))
		return ;
	sol->x = in->x;
	sol->y = in->y;
	sol->size++;
	in->size++;
	while (fits_success(in, g))
	{
		sol->size++;
		in->size++;
	}
}

t_bool	fits(const t_solution *intent, const t_grid *grid)
{
	UINT	i;
	UINT	i_max;
	UINT	j;
	UINT	j_max;

	if (dont_fit_basic(intent, grid))
		return (false);
	i = intent->y;
	i_max = i + intent->size;
	j_max = intent->x + intent->size;
	while (i < i_max)
	{
		j = intent->x;
		while (j < j_max)
		{
			if (grid->map[i][j] == grid->translate[obstacle])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

t_bool	fits_success(t_solution *intent, t_grid *grid)
{
	UINT	i;
	UINT	j;
	UINT	i_max;

	if (dont_fit_basic(intent, grid))
		return (false);
	i = intent->x;
	i_max = i + intent->size;
	j = intent->y + intent->size - 1;
	while (i < i_max)
	{
		if (grid->map[j][i] == grid->translate[obstacle])
			return (false);
		i++;
	}
	i = intent->y;
	i_max = i + intent->size - 1;
	j = intent->x + intent->size - 1;
	while (i < i_max)
	{
		if (grid->map[i][j] == grid->translate[obstacle])
			return (false);
		i++;
	}
	return (true);
}

t_bool	dont_fit_basic(const t_solution *intent, const t_grid *grid)
{
	return (intent->x + intent->size > grid->width
		|| intent->y + intent->size > grid->height);
}
