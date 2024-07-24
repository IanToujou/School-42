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

#include "../includes/ft.h"

int ft_file_read(char *path)
{
	int file;
	int size;
	char	buffer[__BUFFER];

	file = open(path, O_RDWR);
	if (file != -1)
	{
		while ((size = read(file, buffer, __BUFFER)) != 0)
			ft_putstr_buffer(buffer, size);
		return (1);
	}
	else
		return (0);
}