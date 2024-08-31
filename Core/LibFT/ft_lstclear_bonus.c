#include "libft.h"

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