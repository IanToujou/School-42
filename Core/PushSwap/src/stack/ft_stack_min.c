/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:01:11 by ibour             #+#    #+#             */
/*   Updated: 2024/11/05 14:06:45 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_stack_min(const t_stack *stack)
{
	int	i;

	i = stack->num;
	while (stack) {
		if (stack->num < i)
			i = stack->num;
		stack = stack->next;
	}
	return (i);
}