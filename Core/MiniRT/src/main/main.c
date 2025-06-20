/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:45:40 by ibour             #+#    #+#             */
/*   Updated: 2025/06/20 07:52:45 by ibour            ###   ########.fr       */
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
int main(const int argc, char **argv)
{
	t_scene scene;

	if (argc != 2)
		error_throw(ERROR_SYNTAX);
	init_parse(&scene, argv[1]);
	init_mlx(&scene);
	if (create_scene(argv[1], &scene))
		error_throw(ERROR_INIT_SCENE);
	render_scene(&scene);
	init_hook(&scene);
	return (0);
}
