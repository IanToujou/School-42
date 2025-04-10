/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_check_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:10:28 by ibour             #+#    #+#             */
/*   Updated: 2024/11/06 09:39:14 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_stack_check_sort(t_stack *stack_a)
{
	int	i;

	i = stack_a->num;
	while (stack_a)
	{
		if (i > stack_a->num)
			return (0);
		i = stack_a->num;
		stack_a = stack_a->next;
	}
	return (1);
}
