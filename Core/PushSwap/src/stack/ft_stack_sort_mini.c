/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_sort_mini.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:59:59 by ibour             #+#    #+#             */
/*   Updated: 2024/11/06 09:39:43 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_stack_sort_mini(t_stack **stack_a)
{
	if (ft_stack_min(*stack_a) == (*stack_a)->num)
	{
		ft_algo_rra(stack_a, 0);
		ft_algo_sa(stack_a, 0);
	}
	else if (ft_stack_max(*stack_a) == (*stack_a)->num)
	{
		ft_algo_ra(stack_a, 0);
		if (!ft_stack_check_sort(*stack_a))
			ft_algo_sa(stack_a, 0);
	}
	else
	{
		if (ft_stack_index(*stack_a, ft_stack_max(*stack_a)) == 1)
			ft_algo_rra(stack_a, 0);
		else
			ft_algo_sa(stack_a, 0);
	}
}
