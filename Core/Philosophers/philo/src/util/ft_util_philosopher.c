/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_philosopher.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 07:08:52 by ibour             #+#    #+#             */
/*   Updated: 2025/02/10 08:51:46 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

int ft_util_philosopher_is_dead(const t_philosopher *philosopher)
{
    pthread_mutex_lock(&philosopher->general->mutex);
    if (philosopher->general->philosopher_dead == 1)
    {
        pthread_mutex_unlock(&philosopher->general->mutex);
        return (1);
    }
    pthread_mutex_unlock(&philosopher->general->mutex);
    return (0);
}

int     ft_util_philosopher_take_forks(const t_philosopher* philosopher)
{
    if (philosopher->id % 2 == 0)
        pthread_mutex_lock(philosopher->right_fork);
    else
        pthread_mutex_lock(philosopher->left_fork);
    if (!ft_util_philosopher_is_dead(philosopher))
        ft_util_msg("has taken a fork", philosopher);
    if (philosopher->id % 2 == 0) {
        if (pthread_mutex_lock(philosopher->left_fork) != 0)
            return (pthread_mutex_unlock(philosopher->right_fork), 1);
        if (!ft_util_philosopher_is_dead(philosopher))
            ft_util_msg("has taken a fork", philosopher);
    } else {
        if (pthread_mutex_lock(philosopher->right_fork) != 0)
            return (pthread_mutex_unlock(philosopher->left_fork), 1);
        if (!ft_util_philosopher_is_dead(philosopher))
            ft_util_msg("has taken a fork", philosopher);
    }
    return (0);
}

void    ft_util_philosopher_eat(t_philosopher *philosopher)
{
    ft_util_msg("is eating", philosopher);
    pthread_mutex_lock(&philosopher->general->mutex);
    philosopher->last_meal = ft_util_time() - philosopher->general->starting_time;
    philosopher->time_to_die = philosopher->last_meal + philosopher->general->time_to_die;
    pthread_mutex_unlock(&philosopher->general->mutex);
    ft_util_sleep(philosopher->general->time_to_eat, philosopher);
    pthread_mutex_lock(&philosopher->general->mutex);
    if (philosopher->number_of_meals != -1)
        philosopher->number_of_meals++;
    pthread_mutex_unlock(&philosopher->general->mutex);
    pthread_mutex_unlock(philosopher->left_fork);
    pthread_mutex_unlock(philosopher->right_fork);
}

void    ft_util_philosopher_sleep(t_philosopher *philosopher)
{
    ft_util_msg("is sleeping", philosopher);
    ft_util_sleep(philosopher->general->time_to_sleep, philosopher);
}

void    ft_util_philosopher_think(const t_philosopher *philosopher)
{
    ft_util_msg("is thinking", philosopher);
}
