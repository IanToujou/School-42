/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_pb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:12:19 by ibour             #+#    #+#             */
/*   Updated: 2024/11/05 11:14:23 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_algo_pb(t_stack **stack_a, t_stack **stack_b, const int i)
{
	t_stack	*temp;

	if(!*stack_a)
		return ;
	temp = *stack_a;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = temp;
	if (i == 0)
		ft_handle_operation("pb");
}