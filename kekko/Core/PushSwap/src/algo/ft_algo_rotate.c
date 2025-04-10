/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:30:59 by ibour             #+#    #+#             */
/*   Updated: 2024/11/06 09:35:58 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_algo_rotate_ba(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_stack	*temp;

	temp = stack_b;
	i = ft_util_check_rrarrb_a(stack_a, stack_b, stack_b->num);
	while (temp)
	{
		if (i > ft_util_check_rarb_a(stack_a, stack_b, temp->num))
			i = ft_util_check_rarb_a(stack_a, stack_b, temp->num);
		if (i > ft_util_check_rrarrb_a(stack_a, stack_b, temp->num))
			i = ft_util_check_rrarrb_a(stack_a, stack_b, temp->num);
		if (i > ft_util_check_rarrb_a(stack_a, stack_b, temp->num))
			i = ft_util_check_rarrb_a(stack_a, stack_b, temp->num);
		if (i > ft_util_check_rrarb_a(stack_a, stack_b, temp->num))
			i = ft_util_check_rrarb_a(stack_a, stack_b, temp->num);
		temp = temp->next;
	}
	return (i);
}

int	ft_algo_rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_stack	*temp;

	temp = stack_a;
	i = ft_util_check_rrarrb(stack_a, stack_b, stack_a->num);
	while (temp)
	{
		if (i > ft_util_check_rarb(stack_a, stack_b, temp->num))
			i = ft_util_check_rarb(stack_a, stack_b, temp->num);
		if (i > ft_util_check_rrarrb(stack_a, stack_b, temp->num))
			i = ft_util_check_rrarrb(stack_a, stack_b, temp->num);
		if (i > ft_util_check_rarrb(stack_a, stack_b, temp->num))
			i = ft_util_check_rarrb(stack_a, stack_b, temp->num);
		if (i > ft_util_check_rrarb(stack_a, stack_b, temp->num))
			i = ft_util_check_rrarb(stack_a, stack_b, temp->num);
		temp = temp->next;
	}
	return (i);
}
