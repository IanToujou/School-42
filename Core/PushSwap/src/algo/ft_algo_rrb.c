/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_rrb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:51:14 by ibour             #+#    #+#             */
/*   Updated: 2024/11/05 13:52:10 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_algo_rrb(t_stack **stack_b, const int i)
{
	t_stack	*temp;
	int		index;

	if (!*stack_b || !(*stack_b)->next)
		return ;
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
		ft_handle_operation("rrb");
}