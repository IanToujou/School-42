/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <ibour@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:42:26 by ibour             #+#    #+#             */
/*   Updated: 2024/10/25 15:24:46 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * Creates a new linked list and sets the content
 * of the first node to a given value.
 *
 * @param content The content to save.
 * @return The node of the newly created list.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*result;

	result = (t_list *) malloc(sizeof(t_list));
	if (!result)
		return (NULL);
	result->content = content;
	result->next = NULL;
	return (result);
}
