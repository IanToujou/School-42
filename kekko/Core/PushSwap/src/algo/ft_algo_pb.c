/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_pb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:12:19 by ibour             #+#    #+#             */
/*   Updated: 2024/11/06 09:35:51 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_algo_pb(t_stack **stack_a, t_stack **stack_b, int j)
{
	t_stack	*temp;

	if (!*stack_a)
		return ;
	temp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = temp;
	if (j == 0)
		write(1, "pb\n", 3);
}
