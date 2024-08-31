#include "libft.h"

/**
 * Clears
 *
 * @param lst
 * @param del
 */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	size_t	i;

	i = 0;
	while (lst[i])
	{
		lst[i]->content = NULL;
		lst[i]->next = NULL;
		free(*lst);
		i++;
	}
	lst = NULL;
}