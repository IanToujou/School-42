/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:34:54 by ibour             #+#    #+#             */
/*   Updated: 2025/06/12 13:39:38 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_data	*init_data(void)
{
	t_data	*result;

	result = malloc(sizeof(t_data));
	if (!result)
		error_throw(ERR_MALLOC);
	result->map = NULL;
	result->player = NULL;
	result->mlx = NULL;
	result->win = NULL;
	return (result);
}
