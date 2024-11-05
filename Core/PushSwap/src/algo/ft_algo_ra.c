/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_ra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:50:22 by ibour             #+#    #+#             */
/*   Updated: 2024/11/05 10:56:13 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_algo_ra(t_stack **stack_a, const int i)
{
	t_stack	*temp;

	if(!*stack_a || !(*stack_a)->next)
		return ;
	temp = ft_stack_last(*stack_a);
	(*stack_a)->next = temp;
	*stack_a = temp->next;
	temp->next = NULL;
	if (i == 0)
		ft_handle_operation("ra");
}