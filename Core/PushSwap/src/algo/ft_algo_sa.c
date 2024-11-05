/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_sa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:57:49 by ibour             #+#    #+#             */
/*   Updated: 2024/11/05 10:59:16 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_algo_sa(t_stack **stack_a, const int i)
{
	t_stack	*temp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	(*stack_a) = (*stack_a)->next;
	temp->next = (*stack_a)->next;
	(*stack_a)->next = temp;
	if (i == 0)
		ft_handle_operation("sa");
}