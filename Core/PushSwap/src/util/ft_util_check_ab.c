/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_check_ab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:47:28 by ibour             #+#    #+#             */
/*   Updated: 2024/11/05 17:11:17 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_util_check_rarb(t_stack *stack_a, t_stack *stack_b, int c)
{
	int	i;

	i = ft_stack_place_b(stack_b, c);
	if (i < ft_stack_index(stack_a, c))
		i = ft_stack_index(stack_a, c);
	return (i);
}

int	ft_util_check_rrarrb(t_stack *stack_a, t_stack *stack_b, int c)
{
	int	i;

	i = 0;
	if (ft_stack_place_b(stack_b, c))
		i = ft_stack_size(stack_b) - ft_stack_place_b(stack_b, c);
	if ((i < (ft_stack_size(stack_a) - ft_stack_index(stack_a, c))) && ft_stack_index(stack_a, c))
		i = ft_stack_size(stack_a) - ft_stack_index(stack_a, c);
	return (i);
}

int	ft_util_check_rrarb(t_stack *stack_a, t_stack *stack_b, int c)
{
	int	i;

	i = 0;
	if (ft_stack_index(stack_a, c))
		i = ft_stack_size(stack_a) - ft_stack_index(stack_a, c);
	i = ft_stack_place_b(stack_b, c) + i;
	return (i);
}

int	ft_util_check_rarrb(t_stack *stack_a, t_stack *stack_b, int c)
{
	int	i;

	i = 0;
	if (ft_stack_place_b(stack_b, c))
		i = ft_stack_size(stack_b) - ft_stack_place_b(stack_b, c);
	i = ft_stack_index(stack_a, c) + i;
	return (i);
}