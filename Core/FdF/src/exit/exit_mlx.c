/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:55:06 by ibour             #+#    #+#             */
/*   Updated: 2025/07/17 09:57:06 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	exit_mlx(t_data *data)
{
	if (!data || !data->mlx_ptr)
		return ;
	if (data->win_ptr)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	data->mlx_ptr = NULL;
}
