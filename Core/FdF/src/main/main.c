/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:32:10 by ibour             #+#    #+#             */
/*   Updated: 2025/07/17 09:38:29 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *) malloc(sizeof(t_data));
	init_mlx(data);
}
