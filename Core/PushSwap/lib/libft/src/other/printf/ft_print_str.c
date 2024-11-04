/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:38:56 by ibour             #+#    #+#             */
/*   Updated: 2024/11/04 11:24:56 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

void	ft_print_str(char *str, int *i)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_print_char(*str, i);
		str++;
	}
}
