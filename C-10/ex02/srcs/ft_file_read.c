/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:13:45 by ibour             #+#    #+#             */
/*   Updated: 2024/07/25 15:13:46 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ft.h"

int		ft_file_count(char *filepath)
{
    int		file;
    int		size;
    int		sizetot;
    char	buf[__BUFF];

    file = open(filepath, O_RDWR);
    if (file != -1)
    {
        sizetot = 0;
        while ((size = read(file, buf, __BUFF)) != 0)
            sizetot += size;
        return (sizetot);
    }
    else
        return (-1);
}

void	ft_file_get(char *filepath, int sizetot, int size)
{
    int		i;
    int		bufsize;
    int		file;
    char	buf[__BUFF];

    file = open(filepath, O_RDWR);
    i = 0;
    while ((bufsize = read(file, buf, __BUFF)) != 0 &&
            ((i + 1) * __BUFF < sizetot - size))
        i++;
    if (size >= sizetot)
        i = -1;
    else
        i = (sizetot - size) - (i * __BUFF) - 1;
    while (++i < __BUFF && i < bufsize)
        ft_putchar(buf[i], 1);
    while ((bufsize = read(file, buf, __BUFF)) != 0)
        ft_putstr_buf(buf, bufsize);
}
