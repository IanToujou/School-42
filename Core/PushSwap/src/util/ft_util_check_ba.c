/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_check_ba.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:47:33 by ibour             #+#    #+#             */
/*   Updated: 2024/11/05 17:12:38 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_util_check_rarb_a(t_stack *stack_a, t_stack *stack_b, int c)
{
	int	i;

	i = ft_stack_place_a(stack_a, c);
	if (i < ft_stack_index(stack_b, c))
		i = ft_stack_index(stack_b, c);
	return (i);
}

int	ft_util_check_rrarrb_a(t_stack *stack_a, t_stack *stack_b, int c)
{
	int	i;

	i = 0;
	if (ft_stack_place_a(stack_a, c))
		i = ft_stack_size(stack_a) - ft_stack_place_a(stack_a, c);
	if ((i < (ft_stack_size(stack_b) - ft_stack_index(stack_b, c)))
		&& ft_stack_index(stack_b, c))
		i = ft_stack_size(stack_b) - ft_stack_index(stack_b, c);
	return (i);
}

int	ft_util_check_rrarb_a(t_stack *stack_a, t_stack *stack_b, int c)
{
	int	i;

	i = 0;
	if (ft_stack_index(stack_b, c))
		i = ft_stack_size(stack_b) - ft_stack_index(stack_b, c);
	i = ft_stack_place_a(stack_a, c) + i;
	return (i);
}

int	ft_util_check_rarrb_a(t_stack *stack_a, t_stack *stack_b, int c)
{
	int	i;

	i = 0;
	if (ft_stack_place_a(stack_a, c))
		i = ft_stack_size(stack_a) - ft_stack_place_a(stack_a, c);
	i = ft_stack_index(stack_b, c) + i;
	return (i);
}
