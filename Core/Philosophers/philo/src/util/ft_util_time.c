/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:10:11 by ibour             #+#    #+#             */
/*   Updated: 2025/01/15 07:40:17 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void    ft_util_sleep(int time, t_philosopher *philosopher)
{
    int start;

    start = ft_util_time();
    while ((ft_util_time() - start) < time && ft_util_philosopher_is_dead(philosopher) == 0)
        usleep(50);
}

int     ft_util_time()
{
    static struct timeval t;

    gettimeofday(&t, NULL);
    return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}
