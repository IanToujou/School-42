/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:55:29 by ibour             #+#    #+#             */
/*   Updated: 2025/09/10 18:11:48 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	exit_data(t_data *data)
{
	if (!data)
		return ;
	exit_array_2d_int(&data->map.array, data->map.depth);
	exit_array_2d_point(&data->map.points, data->map.depth);
	free(data);
}
