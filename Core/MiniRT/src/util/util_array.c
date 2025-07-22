/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:41:56 by ibour             #+#    #+#             */
/*   Updated: 2025/07/22 10:10:33 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	util_array_gnl_free(const int fd)
{
	char *temp;

	close(fd);
	temp = get_next_line(fd);
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
	}
}

void	util_array_free(void **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	util_array_count(void **array)
{
	int	count;

	count = 0;
	if (!array)
		return (0);
	while (array[count])
		count++;
	return (count);
}
