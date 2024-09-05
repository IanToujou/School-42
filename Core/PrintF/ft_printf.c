/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_printf.c >                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 23:31:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/31 23:31:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	va_list	args;
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (*str) {
		str++;
		i++;
	}
	va_end(args);
	return (i);
}
