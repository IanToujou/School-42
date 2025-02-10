/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_monitoring.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:29:35 by ibour             #+#    #+#             */
/*   Updated: 2025/02/10 10:30:09 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

static int	ft_monitor_last_meal(const t_philosopher *ph)
{
	char	*name;

	if (ft_util_time() - ph->general->start
		> ph->time_to_die)
	{
		ph->general->philosopher_dead = 1;
		name = ft_util_str_get_name(ph->id);
		printf("\033[91m[t = %dms] Philosopher #%d (%s): Dead \033[0m💀\n",
			ft_util_time() - ph->general->start, ph->id, name);
		return (-1);
	}
	return (0);
}

static int	ft_monitor_max_meals(t_data *data)
{
	int	i;

	if (data->number_of_meals == -1)
		return (0);
	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (data->philosophers[i].number_of_meals > data->number_of_meals)
		{
			data->philosopher_dead = 1;
			printf("\033[37mAll philosophers ate enough.\033[0m\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

static int	ft_monitor_death(const t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (ft_monitor_last_meal(&data->philosophers[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}

void	*ft_init_monitoring(void *arg)
{
	t_data	*data;

	data = (t_data *) arg;
	while (1)
	{
		pthread_mutex_lock(&data->mutex);
		if (ft_monitor_death(data) == -1 || ft_monitor_max_meals(data) == -1)
		{
			usleep(100);
			return (pthread_mutex_unlock(&data->mutex), NULL);
		}
		pthread_mutex_unlock(&data->mutex);
		usleep(200);
	}
}
