/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:32:10 by ibour             #+#    #+#             */
/*   Updated: 2025/09/10 17:49:56 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int main(const int argc, char **argv)
{
	t_gg_data	*gg_data;
	t_data		*data;

	if (argc != 2)
		error_throw(ERROR_SYNTAX);
	gg_data = gg_init();
	data = (t_data *) gg_malloc(gg_data, sizeof(t_data));
	data->gg_data = gg_data;
	if (!data)
		error_throw(ERROR_MALLOC);
	init_data(data);
	init_parse(data, argv[1]);
	init_mlx(data);
	// projection
	// placement info
	gfx_render(data);
	init_hook(data);
}
