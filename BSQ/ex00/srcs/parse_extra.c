/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:47:28 by ibour             #+#    #+#             */
/*   Updated: 2024/07/30 13:47:29 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h""

t_bool	read_full(const int fd, char **content, UINT *total)
{
	char	buffer[BUFFER_3M]; // todo add fixed size of 3Mbyte
	UINT	byte_read;

	if (read(fd, 0, 0) == -1)
		return (false);
	*total = 0;
	*content = NULL;
	byte_read = read(fd, buffer, BUFFER_3M);
	while (byte_read > 0)
	{
		*content = extend_array(*content, buffer, *total, *total + byte_read);
		if (*content == NULL)
			return (false);
		*total += byte_read;
		byte_read = read(fd, buffer, BUFFER_3M);
	}
	if (byte_read == 0)
		return (true);
	return (false);
}