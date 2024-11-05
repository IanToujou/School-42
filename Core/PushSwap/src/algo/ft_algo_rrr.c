/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:47:11 by ibour             #+#    #+#             */
/*   Updated: 2024/11/05 13:49:56 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	ft_algo_rrr_sub(t_stack **stack_b, int i)
{
	t_stack	*temp;
	int		index;

	index = 0;
	temp = *stack_b;
	while ((*stack_b)->next)
	{
		index++;
		*stack_b = (*stack_b)->next;
	}
	(*stack_b)->next = temp;
	while (index > 1)
	{
		temp = temp->next;
		index--;
	}
	temp->next = NULL;
	if (i == 0)
		ft_handle_operation("rrr");
}

void	ft_algo_rrr(t_stack **stack_a, t_stack **stack_b, const int i)
{
	t_stack	*temp;
	int		index;

	if (!*stack_a || !((*stack_a)->next) || !*stack_b || !((*stack_b)->next))
		return ;
	index = 0;
	temp = *stack_a;
	while ((*stack_a)->next)
	{
		index++;
		*stack_a = (*stack_a)->next;
	}
	(*stack_a)->next = temp;
	while (index > 1)
	{
		temp = temp->next;
		index--;
	}
	temp->next = NULL;
	ft_algo_rrr_sub(stack_b, i);
}