/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:13:00 by ibour             #+#    #+#             */
/*   Updated: 2024/07/25 15:13:00 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_putstr(char *str, int out)
{
    int i;

    i = 0;
    while (*(str + i) != '\0')
    {
        ft_putchar((unsigned char)*(str + i), out);
        i++;
    }
}

void	ft_putstr_buf(char *str, int size)
{
    int i;

    i = -1;
    while (++i < size)
        ft_putchar((unsigned char)str[i], 1);
}

void	ft_putstr_headfile(char *filepath)
{
    ft_putstr("==> ", 1);
    ft_putstr(filepath, 1);
    ft_putstr(" <==\n", 1);
}
