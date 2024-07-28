/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:06:50 by ibour             #+#    #+#             */
/*   Updated: 2024/07/24 14:06:51 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/display_file.h"

void	ft_putchar(const int out, const char c)
{
	write(out, &c, 1);
}

void	ft_putstr(const int out, const char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		ft_putchar(out, str[index]);
		index++;
	}
}
