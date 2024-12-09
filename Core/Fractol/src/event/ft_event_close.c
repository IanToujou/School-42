/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 06:27:46 by ibour             #+#    #+#             */
/*   Updated: 2024/12/09 08:32:37 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	ft_event_close(const t_engine *engine)
{
	mlx_destroy_image(engine->mlx, engine->image.mlx_image);
	mlx_destroy_window(engine->mlx, engine->window);
	exit(EXIT_SUCCESS);
}
