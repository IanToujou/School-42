/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gg_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:26:19 by ibour             #+#    #+#             */
/*   Updated: 2025/09/09 14:52:54 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/gg_collect.h"

/**
 * Creates and initializes the main data struct for garbage collection.
 * This function MUST be called before using any features of
 * the garbage collector.
 *
 * @return The new main data struct.
 */
t_gg_data	*gg_init(void)
{
	t_gg_data	*data;

	data = (t_gg_data *) malloc(sizeof(t_gg_data));
	data->size = 0;
	data->alloc_count = 0;
	data->head = NULL;
	return (data);
}
