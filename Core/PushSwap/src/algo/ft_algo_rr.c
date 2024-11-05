/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:14:51 by ibour             #+#    #+#             */
/*   Updated: 2024/11/05 13:33:00 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_algo_rr(t_stack **stack_a, t_stack **stack_b, const int i)
{
	t_stack	*temp;

	if (!*stack_a || !((*stack_a)->next) || !*stack_b || !((*stack_b)->next))
		return ;
	temp = *stack_a;
	*stack_a = ft_stack_last(*stack_a);
	(*stack_a)->next = temp;
	*stack_a = temp->next;
	temp->next = NULL;
	temp = *stack_b;
	*stack_b = ft_stack_last(*stack_b);
	(*stack_b)->next = temp;
	*stack_b = temp->next;
	temp->next = NULL;
	if (i == 0)
		ft_handle_operation("rr");
}