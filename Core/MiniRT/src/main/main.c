/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:45:40 by ibour             #+#    #+#             */
/*   Updated: 2025/07/07 18:18:04 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

/**
 * The main function, what do you expect?
 *
 * @param argc The argument count.
 * @param argv The argument vector.
 * @return A status code, 0 if successful and 1 if it fails.
 */
int	main(const int argc, char **argv)
{
	t_scene	*scene;

	if (argc != 2)
		error_throw(ERROR_SYNTAX);
	scene = (t_scene *) malloc(sizeof(t_scene));
	if (!scene)
		error_throw(ERROR_MALLOC);
	init_data(scene);
	init_parse(scene, argv[1]);
	init_mlx(scene);
	render_scene(scene);
	init_hook(scene);
	exit_data(scene);
	return (0);
}
