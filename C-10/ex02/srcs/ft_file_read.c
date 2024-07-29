/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:39:17 by ibour             #+#    #+#             */
/*   Updated: 2024/07/24 18:39:44 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "../includes/ft_tail.h"

/**
 * Read and prints the last 10 lines of a file.
 *
 * @param path The path of the file that should be read.
 * @return 1 when the file was read successfully. 0 on error.
 */
int	ft_read(char *path)
{
	int		file;
	int		size;
	int		index;
	int		jndex;
	char	buffer[BUFFER_SIZE];
	char	*lines[BUFFER_SIZE];

	file = open(path, O_RDWR);
	if (file != -1)
	{
		index = 0;
		jndex = 0;
		size = read(file, buffer, BUFFER_SIZE);
		printf("SIZE IS: %d", size);

		while(index < size) {
			if(buffer[index] == '\n') {
				printf("newline found at index %d.\n", index);
				jndex++;
			}
			else {
				lines[jndex][index] += buffer[index];
			}
			index++;
		}

		ft_putstr_buffer(OUT, buffer, size);
		return (1);
	}
	return (0);
}