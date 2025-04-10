/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_rotate_push.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:06:22 by ibour             #+#    #+#             */
/*   Updated: 2024/11/06 09:36:40 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_algo_push_rarb(t_stack **stack_a, t_stack **stack_b, int c, char s)
{
	if (s == 'a')
	{
		while ((*stack_a)->num != c && ft_stack_place_b(*stack_b, c) > 0)
			ft_algo_rr(stack_a, stack_b, 0);
		while ((*stack_a)->num != c)
			ft_algo_ra(stack_a, 0);
		while (ft_stack_place_b(*stack_b, c) > 0)
			ft_algo_rb(stack_b, 0);
		ft_algo_pb(stack_a, stack_b, 0);
	}
	else
	{
		while ((*stack_b)->num != c && ft_stack_place_a(*stack_a, c) > 0)
			ft_algo_rr(stack_a, stack_b, 0);
		while ((*stack_b)->num != c)
			ft_algo_rb(stack_b, 0);
		while (ft_stack_place_a(*stack_a, c) > 0)
			ft_algo_ra(stack_a, 0);
		ft_algo_pa(stack_a, stack_b, 0);
	}
	return (-1);
}

int	ft_algo_push_rrarrb(t_stack **stack_a, t_stack **stack_b, int c, char s)
{
	if (s == 'a')
	{
		while ((*stack_a)->num != c && ft_stack_place_b(*stack_b, c) > 0)
			ft_algo_rrr(stack_a, stack_b, 0);
		while ((*stack_a)->num != c)
			ft_algo_rra(stack_a, 0);
		while (ft_stack_place_b(*stack_b, c) > 0)
			ft_algo_rrb(stack_b, 0);
		ft_algo_pb(stack_a, stack_b, 0);
	}
	else
	{
		while ((*stack_b)->num != c && ft_stack_place_a(*stack_a, c) > 0)
			ft_algo_rrr(stack_a, stack_b, 0);
		while ((*stack_b)->num != c)
			ft_algo_rrb(stack_b, 0);
		while (ft_stack_place_a(*stack_a, c) > 0)
			ft_algo_rra(stack_a, 0);
		ft_algo_pa(stack_a, stack_b, 0);
	}
	return (-1);
}

int	ft_algo_push_rrarb(t_stack **stack_a, t_stack **stack_b, int c, char s)
{
	if (s == 'a')
	{
		while ((*stack_a)->num != c)
			ft_algo_rra(stack_a, 0);
		while (ft_stack_place_b(*stack_b, c) > 0)
			ft_algo_rb(stack_b, 0);
		ft_algo_pb(stack_a, stack_b, 0);
	}
	else
	{
		while (ft_stack_place_a(*stack_a, c) > 0)
			ft_algo_rra(stack_a, 0);
		while ((*stack_b)->num != c)
			ft_algo_rb(stack_b, 0);
		ft_algo_pa(stack_a, stack_b, 0);
	}
	return (-1);
}

int	ft_algo_push_rarrb(t_stack **stack_a, t_stack **stack_b, int c, char s)
{
	if (s == 'a')
	{
		while ((*stack_a)->num != c)
			ft_algo_ra(stack_a, 0);
		while (ft_stack_place_b(*stack_b, c) > 0)
			ft_algo_rrb(stack_b, 0);
		ft_algo_pb(stack_a, stack_b, 0);
	}
	else
	{
		while (ft_stack_place_a(*stack_a, c) > 0)
			ft_algo_ra(stack_a, 0);
		while ((*stack_b)->num != c)
			ft_algo_rrb(stack_b, 0);
		ft_algo_pa(stack_a, stack_b, 0);
	}
	return (-1);
}
