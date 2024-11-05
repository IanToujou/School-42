/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:55:04 by ibour             #+#    #+#             */
/*   Updated: 2024/11/05 16:51:43 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_stack_place_b(t_stack *stack_b, int num_push)
{
	int		i;
	t_stack	*temp;

	i = 1;
	if (num_push > stack_b->num && num_push < ft_stack_last(stack_b)->num)
		i = 0;
	else if (num_push > ft_stack_max(stack_b) || num_push < ft_stack_min(stack_b))
		i = ft_stack_index(stack_b, ft_stack_max(stack_b));
	else
	{
		temp = stack_b->next;
		while (stack_b->num < num_push || temp->num > num_push)
		{
			stack_b = stack_b->next;
			temp = stack_b->next;
			i++;
		}
	}
	return (i);
}

int	ft_stack_place_a(t_stack *stack_a, int num_push)
{
	int		i;
	t_stack	*temp;

	i = 1;
	if (num_push < stack_a->num && num_push > ft_stack_last(stack_a)->num)
		i = 0;
	else if (num_push > ft_stack_max(stack_a) || num_push < ft_stack_min(stack_a))
		i = ft_stack_index(stack_a, ft_stack_min(stack_a));
	else
	{
		temp = stack_a->next;
		while (stack_a->num > num_push || temp->num < num_push)
		{
			stack_a = stack_a->next;
			temp = stack_a->next;
			i++;
		}
	}
	return (i);
}