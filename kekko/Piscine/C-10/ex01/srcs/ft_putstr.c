/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:53:39 by ibour             #+#    #+#             */
/*   Updated: 2024/07/24 19:53:39 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_putstr(char *str, int out)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i], out);
		i++;
	}
}

void	ft_putstr_buffer(char *str, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		ft_putchar(str[i], 1);
	}
}
