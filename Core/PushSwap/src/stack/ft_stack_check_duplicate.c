/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_check_duplicate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:06:23 by ibour             #+#    #+#             */
/*   Updated: 2024/11/05 10:41:22 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_stack_check_duplicate(const t_stack *stack)
{
	t_stack *temp;

	while (stack) {
		temp = stack->next;
		while (temp) {
			if (stack->num == temp->num)
				return (1);
			temp = temp->next;
		}
		stack = stack->next;
	}
	return (0);
}