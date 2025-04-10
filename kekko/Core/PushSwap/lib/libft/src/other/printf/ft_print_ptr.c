/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:38:56 by ibour             #+#    #+#             */
/*   Updated: 2024/11/05 19:06:44 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

void	ft_print_ptr(void *ptr, int *i)
{
	unsigned long	p;

	p = *(unsigned long *) ptr;
	if (p)
	{
		ft_print_str("0x", i);
		ft_print_num_base(p, "0123456789abcdef", i);
	}
	else
		ft_print_str("(nil)", i);
}
