/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:01:22 by ibour             #+#    #+#             */
/*   Updated: 2024/11/05 19:31:50 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_stack_max(t_stack *stack_a)
{
	int		i;

	i = stack_a->num;
	while (stack_a)
	{
		if (stack_a->num > i)
			i = stack_a->num;
		stack_a = stack_a->next;
	}
	return (i);
}