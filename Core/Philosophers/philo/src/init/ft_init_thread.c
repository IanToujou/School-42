/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 07:08:52 by ibour             #+#    #+#             */
/*   Updated: 2025/01/23 07:26:37 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void    ft_init_thread_main(t_data *data)
{
    int i;

    i = 0;
    data->starting_time = ft_util_time();
    while (i < data->number_of_philosophers)
    {
        if (pthread_create(&data->philosophers[i].thread_id, NULL, &ft_thread_philosopher, (void *) &data->philosophers[i]) != 0)
            ft_throw_error(ERROR_INIT_THREAD);
    }
}
