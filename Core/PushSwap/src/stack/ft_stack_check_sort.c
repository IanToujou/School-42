/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_check_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:10:28 by ibour             #+#    #+#             */
/*   Updated: 2024/11/05 10:41:17 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_stack_check_sort(const t_stack *stack)
{
	int	i;

	i = stack->num;
	while (stack) {
		if (i > stack->num)
			return (0);
		i = stack->num;
		stack = stack->next;
	}
	return (1);
}