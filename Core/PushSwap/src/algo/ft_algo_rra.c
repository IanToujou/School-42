/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_rra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:22:02 by ibour             #+#    #+#             */
/*   Updated: 2024/11/05 11:23:44 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_algo_rra(t_stack **stack_a, const int i)
{
	t_stack	*temp;
	int		index;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	index = 0;
	temp = *stack_a;
	while ((*stack_a)->next)
	{
		*stack_a = (*stack_a)->next;
		index++;
	}
	(*stack_a)->next = temp;
	while (index > 1)
	{
		temp = temp->next;
		index--;
	}
	temp->next = NULL;
	if (i == 0)
		ft_handle_operation("rra");
}