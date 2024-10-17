/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_lstmap_bonus.c >                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * Iterates over a list and applies a given function
 * on the content of each node. Creates a new list
 * resulting of the successive applications of
 * the function.
 *
 * @param lst The list to iterate over.
 * @param f A function to apply.
 * @param del A function to delete the content of a
 * node, if needed.
 * @return
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*element;

	if (!lst || !f)
		return (NULL);
	new = 0;
	while (lst)
	{
		element = ft_lstnew(f(lst->content));
		if (!element)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, element);
		lst = lst->next;
	}
	return (new);
}
