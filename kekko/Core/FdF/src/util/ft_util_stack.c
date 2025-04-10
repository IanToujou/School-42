/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 02:55:51 by ibour             #+#    #+#             */
/*   Updated: 2024/12/27 02:56:17 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	ft_util_stack_push(t_coord_val **coords_stack, t_coord_val *new)
{
	if (coords_stack)
	{
		if (new)
			new->next = *coords_stack;
		*coords_stack = new;
	}
}

t_coord_val	*ft_util_stack_pop(t_coord_val **coords_stack)
{
	t_coord_val *top;

	top = NULL;
	if (coords_stack && *coords_stack)
	{
		top = *coords_stack;
		*coords_stack = (*coords_stack)->next;
	}
	return (top);
}

