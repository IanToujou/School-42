/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:10:11 by ibour             #+#    #+#             */
/*   Updated: 2025/01/23 07:13:43 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void    *ft_thread_philosopher(void *args)
{
    t_philosopher *philosophers;

    philosophers = (t_philosopher *) args;
    while (philosophers->general->philosopher_dead == 0)
    {
        if (ft_util_philosopher_is_dead(philosophers))
            return (0);
        ft_util_philosopher_take_forks(philosophers);
        if (ft_util_philosopher_is_dead(philosophers))
        {
            pthread_mutex_unlock(philosophers->general->left_fork);
            pthread_mutex_unlock(philosophers->general->right_fork);
            return (0);
        }
        ft_util_philosopher_eat(philosophers);
        if (ft_util_philosopher_is_dead(philosophers))
            return (0);
        ft_util_philosopher_sleep(philosophers);
        if (ft_util_philosopher_is_dead(philosophers))
            return (0);
        ft_util_philosopher_think(philosophers);
    }
    return (0);
}
