/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:22:27 by ibour             #+#    #+#             */
/*   Updated: 2024/11/05 10:41:33 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*ft_stack_new(const int num)
{
	t_stack	*stack;

	stack = (t_stack *) malloc(sizeof(t_stack));
	if (!stack) {
		ft_handle_error("Memory allocation for the stack failed.", 1);
		return (NULL);
	}
	stack->num = num;
	stack->next = NULL;
	return (stack);
}