/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:44:49 by ibour             #+#    #+#             */
/*   Updated: 2025/02/10 08:12:54 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	ft_util_msg(char *msg, const t_philosopher *philosopher)
{
	if (!ft_util_philosopher_is_dead(philosopher))
	{
		pthread_mutex_lock(&philosopher->general->mutex);
		printf("%d %d %s\n", ft_util_time() - philosopher->general->starting_time, philosopher->id, msg);
		fflush(stdout);
		pthread_mutex_unlock(&philosopher->general->mutex);
	}
}

int	ft_util_str_is_num(const char *str) {
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}
