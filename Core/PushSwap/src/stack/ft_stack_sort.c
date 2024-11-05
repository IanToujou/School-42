/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_sort_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:41:09 by ibour             #+#    #+#             */
/*   Updated: 2024/11/05 19:43:20 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_stack_sort_until_three(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*temp;

	while (ft_stack_size(*stack_a) > 3 && !ft_stack_check_sort(*stack_a))
	{
		temp = *stack_a;
		i = ft_algo_rotate_ab(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == ft_util_check_rarb(*stack_a, *stack_b, temp->num))
				i = ft_algo_push_rarb(stack_a, stack_b, temp->num, 'a');
			else if (i == ft_util_check_rrarrb(*stack_a, *stack_b, temp->num))
				i = ft_algo_push_rrarrb(stack_a, stack_b, temp->num, 'a');
			else if (i == ft_util_check_rarrb(*stack_a, *stack_b, temp->num))
				i = ft_algo_push_rarrb(stack_a, stack_b, temp->num, 'a');
			else if (i == ft_util_check_rrarb(*stack_a, *stack_b, temp->num))
				i = ft_algo_push_rrarb(stack_a, stack_b, temp->num, 'a');
			else
				temp = temp->next;
		}
	}
}

t_stack	*ft_stack_sort_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_stack_size(*stack_a) > 3 && !ft_stack_check_sort(*stack_a))
		ft_algo_pb(stack_a, &stack_b, 0);
	if (ft_stack_size(*stack_a) > 3 && !ft_stack_check_sort(*stack_a))
		ft_algo_pb(stack_a, &stack_b, 0);
	if (ft_stack_size(*stack_a) > 3 && !ft_stack_check_sort(*stack_a))
		ft_stack_sort_until_three(stack_a, &stack_b);
	if (!ft_stack_check_sort(*stack_a))
		ft_stack_sort_mini(stack_a);
	return (stack_b);
}

t_stack	**ft_stack_sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*temp;

	while (*stack_b)
	{
		temp = *stack_b;
		i = ft_algo_rotate_ba(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == ft_util_check_rarb_a(*stack_a, *stack_b, temp->num))
				i = ft_algo_push_rarb(stack_a, stack_b, temp->num, 'b');
			else if (i == ft_util_check_rarrb_a(*stack_a, *stack_b, temp->num))
				i = ft_algo_push_rarrb(stack_a, stack_b, temp->num, 'b');
			else if (i == ft_util_check_rrarrb_a(*stack_a, *stack_b, temp->num))
				i = ft_algo_push_rrarrb(stack_a, stack_b, temp->num, 'b');
			else if (i == ft_util_check_rrarb_a(*stack_a, *stack_b, temp->num))
				i = ft_algo_push_rrarb(stack_a, stack_b, temp->num, 'b');
			else
				temp = temp->next;
		}
	}
	return (stack_a);
}

void	ft_stack_sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	if (ft_stack_size(*stack_a) == 2)
		ft_algo_sa(stack_a, 0);
	else
	{
		stack_b = ft_stack_sort_b(stack_a);
		stack_a = ft_stack_sort_a(stack_a, &stack_b);
		i = ft_stack_index(*stack_a, ft_stack_min(*stack_a));
		if (i < ft_stack_size(*stack_a) - i)
		{
			while ((*stack_a)->num != ft_stack_min(*stack_a))
				ft_algo_ra(stack_a, 0);
		}
		else
		{
			while ((*stack_a)->num != ft_stack_min(*stack_a))
				ft_algo_rra(stack_a, 0);
		}
	}
}