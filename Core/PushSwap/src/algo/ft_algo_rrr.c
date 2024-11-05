/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:47:11 by ibour             #+#    #+#             */
/*   Updated: 2024/11/05 17:01:58 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_algo_rrr_sub(t_stack **stack_b, int j)
{
	t_stack	*temp;
	int		i;

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
		write(1, "rrr\n", 4);
}

void	ft_algo_rrr(t_stack **stack_a, t_stack **stack_b, int j)
{
	t_stack	*temp;
	int		i;

	if (!*stack_a || !((*stack_a)->next) || !*stack_b || !((*stack_b)->next))
		return ;
	i = 0;
	temp = *stack_a;
	while ((*stack_a)->next)
	{
		i++;
		*stack_a = (*stack_a)->next;
	}
	(*stack_a)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
	ft_algo_rrr_sub(stack_b, j);
}