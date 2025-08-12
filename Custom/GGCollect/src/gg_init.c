/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gg_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:26:19 by ibour             #+#    #+#             */
/*   Updated: 2025/08/12 11:26:39 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/gg_collect.h"

void	gg_init(t_gg_data *data)
{
	if (!data)
		return ;
	data->size = 0;
	data->alloc_count = 0;
	data->head = NULL;
}
