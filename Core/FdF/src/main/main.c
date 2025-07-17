/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:32:10 by ibour             #+#    #+#             */
/*   Updated: 2025/07/17 10:40:13 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int main(const int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		error_throw(ERROR_SYNTAX);
	data = (t_data *) malloc(sizeof(t_data));
	if (!data)
		error_throw(ERROR_MALLOC);
	init_data(data);
	init_parse(data, argv[1]);
	init_mlx(data);
	gfx_render(data);
	init_hook(data);
	exit_data(data);
}
