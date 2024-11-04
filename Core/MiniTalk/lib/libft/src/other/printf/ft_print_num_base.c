/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:38:56 by ibour             #+#    #+#             */
/*   Updated: 2024/11/04 13:13:05 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

void	ft_print_num_base(unsigned long int p, char *base, int *i)
{
	int	length;

	length = ft_strlen(base);
	if (p / length)
		ft_print_num_base(p / length, base, i);
	ft_print_char(base[p % length], i);
}
