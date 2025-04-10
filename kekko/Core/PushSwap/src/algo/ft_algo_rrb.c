/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_rrb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:51:14 by ibour             #+#    #+#             */
/*   Updated: 2024/11/06 09:36:07 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_algo_rrb(t_stack **stack_b, int j)
{
	t_stack	*temp;
	int		i;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	i = 0;
	temp = *stack_b;
	while ((*stack_b)->next)
	{
		i++;
		*stack_b = (*stack_b)->next;
	}
	(*stack_b)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
	if (j == 0)
		write(1, "rrb\n", 4);
}
