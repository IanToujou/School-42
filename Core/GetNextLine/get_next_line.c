/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < get_next_line.c >                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*buffer;
	int			bytes_read;

	buffer = ft_calloc(3 + 1, sizeof(char));
	buffer = malloc(4 * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, 3);
	if (fd < 0 || BUFFER_SIZE < 1 || bytes_read <= 0)
		return (NULL);
	return (buffer);
}
