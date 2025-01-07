/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:19:53 by ibour             #+#    #+#             */
/*   Updated: 2025/01/07 19:25:26 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

static int	ft_init_philosophers(t_data *data) {
	int	i;

	i = 0;
	data->philosophers = malloc(sizeof(t_philosopher) * data->number_of_philosophers);
	if (!data->philosophers)
		return (-1);
	while (i < data->number_of_philosophers)
	{
		data->philosophers[i].id = i + 1;
		data->philosophers[i].left_fork = &data->fork_mutex[i];
		data->philosophers[i].right_fork = &data->fork_mutex[(i + 1)
			% data->number_of_philosophers];
		data->philosophers[i].general = data;
		data->philosophers[i].time_to_die = data->time_to_die;
		data->philosophers[i].time_to_eat = data->time_to_eat;
		data->philosophers[i].time_to_sleep = data->time_to_sleep;
		data->philosophers[i].last_meal = 0;
		data->philosophers[i].is_eating = 0;
		data->philosophers[i].number_of_meals = 0;
		i++;
	}
	return (0);
}

static int	ft_init_mutex(t_data *data)
{
	int	i;

	i = -1;
	data->fork_mutex
		= malloc(sizeof(pthread_mutex_t) * data->number_of_philosophers);
	if (!data->fork_mutex)
		return (-1);
	while (++i < data->number_of_philosophers)
		pthread_mutex_init(&data->fork_mutex[i], NULL);
	pthread_mutex_init(&data->mutex, NULL);
	return (0);
}

int	ft_init_data(t_data **data, char **argv)
{
	(*data) = malloc(sizeof(t_data));
	if (!(*data))
		return (-1);
	(*data)->number_of_philosophers = ft_util_atoi(argv[1]);
	(*data)->time_to_die = ft_util_atoi(argv[2]);
	(*data)->time_to_eat = ft_util_atoi(argv[3]);
	(*data)->time_to_sleep = ft_util_atoi(argv[4]);
	if (argv[5])
		(*data)->number_of_meals = ft_util_atoi(argv[5]);
	else
		(*data)->number_of_meals = -1;
	(*data)->philosopher_dead = 0;
	if (ft_init_mutex(*data) == -1)
		return (-1);
	if (ft_init_philosophers(*data) == -1)
		return (-1);
	return (0);
}
