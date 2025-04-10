/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:38:56 by ibour             #+#    #+#             */
/*   Updated: 2024/11/11 10:13:19 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

void	ft_print_num_unsigned(unsigned int num, int *i)
{
	ft_print_num_base(num, "0123456789", i);
}
