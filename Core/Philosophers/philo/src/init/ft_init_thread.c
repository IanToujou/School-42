/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 07:08:52 by ibour             #+#    #+#             */
/*   Updated: 2025/01/23 08:51:18 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

static int  ft_monitor_last_meal(const t_philosopher *philosopher)
{
    if (ft_util_time() - philosopher->general->starting_time > philosopher->time_to_die) {
        philosopher->general->philosopher_dead = 1;
        printf("%d %d died\n", ft_util_time() - philosopher->general->starting_time, philosopher->id);
        return (0);
    }
    return (1);
}

static int  ft_monitor_death(const t_data *data)
{
    int i;

    i = 0;
    while (i < data->number_of_philosophers) {
        if (ft_monitor_last_meal(&data->philosophers[i]) == 0)
            return (0);
        i++;
    }
    return (1);
}

void    *ft_init_monitoring(void *arg)
{
    t_data  *data;

    data = (t_data *)arg;
    while (1) {
        pthread_mutex_lock(&data->mutex);
        if (ft_monitor_death(data) == 0) {
            usleep(100);
            return (pthread_mutex_unlock(&data->mutex), NULL);
        }
        pthread_mutex_unlock(&data->mutex);
        usleep(200);
    }
}

void    ft_init_join(const t_data *data)
{
    int i;

    i = 0;
    while (i < data->number_of_philosophers) {
        pthread_join(data->philosophers[i].thread_id, NULL);
        i++;
    }
}

void    ft_init_thread_main(t_data *data)
{
    int i;

    i = 0;
    data->starting_time = ft_util_time();
    while (i < data->number_of_philosophers)
    {
        if (pthread_create(&data->philosophers[i].thread_id, NULL, &ft_thread_philosopher, (void *) &data->philosophers[i]) != 0)
            ft_throw_error(ERROR_INIT_THREAD);
        i++;
    }
    i = 0;
    while (i < data->number_of_philosophers) {
        pthread_join(data->philosophers[i].thread_id, NULL);
        i++;
    }
}
