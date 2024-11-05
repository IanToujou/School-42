/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:59:56 by ibour             #+#    #+#             */
/*   Updated: 2024/11/05 11:00:45 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_stack_size(const t_stack *stack)
{
	size_t	size;

	size = 0;
	while (stack) {
		stack = stack->next;
		size++;
	}
	return (size);
}