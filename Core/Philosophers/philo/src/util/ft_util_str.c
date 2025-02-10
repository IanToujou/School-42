/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:44:49 by ibour             #+#    #+#             */
/*   Updated: 2025/02/10 10:32:23 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

char	*ft_util_str_get_name(const int num)
{
	if (num == 1)
		return ("Gustavo");
	if (num == 2)
		return ("Simon");
	if (num == 3)
		return ("Elliot");
	if (num == 4)
		return ("Gabrielle");
	if (num == 5)
		return ("Georges");
	if (num == 6)
		return ("Nawfel");
	if (num == 7)
		return ("Joao");
	if (num == 8)
		return ("Rabiya");
	if (num == 9)
		return ("Sam");
	return ("Nameless");
}

void	ft_util_msg(char *msg, const t_philosopher *philosopher)
{
	char	*name;

	if (!ft_util_philosopher_is_dead(philosopher))
	{
		name = ft_util_str_get_name(philosopher->id);
		pthread_mutex_lock(&philosopher->general->mutex);
		printf("\033[92m[t = %dms] Philosopher #%d (%s): %s\033[0m\n",
			ft_util_time()
			- philosopher->general->start, philosopher->id, name, msg);
		pthread_mutex_unlock(&philosopher->general->mutex);
	}
}

int	ft_util_str_is_num(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}
