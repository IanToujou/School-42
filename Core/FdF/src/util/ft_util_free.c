/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:24:49 by ibour             #+#    #+#             */
/*   Updated: 2024/12/13 11:44:20 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	ft_util_free(t_data *data)
{
	if (!data)
		return ;
	if (data->map)
		free(data->map);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
}
