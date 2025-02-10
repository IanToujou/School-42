/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 07:08:52 by ibour             #+#    #+#             */
/*   Updated: 2025/02/10 10:41:55 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	ft_init_join(const t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_join(data->philosophers[i].thread_id, NULL);
		i++;
	}
}

void	ft_init_thread_main(t_data *data)
{
	int	i;

	i = 0;
	data->start = ft_util_time();
	while (i < data->number_of_philosophers)
	{
		pthread_create(&data->philosophers[i].thread_id, NULL,
			&ft_thread_philosopher, (void *) &data->philosophers[i]);
		i++;
	}
}
