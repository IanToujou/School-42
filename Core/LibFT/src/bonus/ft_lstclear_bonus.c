/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_lstclear.c >                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * Clears a list by removing the content,
 * setting it to NULL and freeing the memory.
 *
 * @param lst The list to clear.
 * @param del A function to delete the content.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*new;

	if (!lst)
		return ;
	while (*lst)
	{
		new = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = new;
	}
	*lst = 0;
}
