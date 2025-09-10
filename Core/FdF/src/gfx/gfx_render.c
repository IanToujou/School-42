/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:50:54 by ibour             #+#    #+#             */
/*   Updated: 2025/09/10 16:40:52 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	gfx_render(t_data *data)
{
	printf("D: %d\n", data->map.depth); fflush(stdout);
	printf("W: %d\n", data->map.width); fflush(stdout);

	printf("Array contents:\n");
	for (int i = 0; i < data->map.depth; i++)
	{
		for (int j = 0; j < data->map.width; j++)
		{
			printf("%d ", data->map.array[i][j]);
		}
		printf("\n");
	}
	fflush(stdout);

}
