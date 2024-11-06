/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:01:11 by ibour             #+#    #+#             */
/*   Updated: 2024/11/06 09:39:28 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_stack_min(t_stack *stack_a)
{
	int		i;

	i = stack_a->num;
	while (stack_a)
	{
		if (stack_a->num < i)
			i = stack_a->num;
		stack_a = stack_a->next;
	}
	return (i);
}
