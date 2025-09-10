/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gg_collect.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:08:46 by ibour             #+#    #+#             */
/*   Updated: 2025/09/09 14:52:52 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GG_COLLECT_H
# define GG_COLLECT_H

# include <stdlib.h>

typedef struct s_gg_node
{
	void				*ptr;
	size_t				size;
	struct s_gg_node	*next;
}	t_gg_node;

typedef struct s_gg_data
{
	t_gg_node	*head;
	size_t		alloc_count;
	size_t		size;
}	t_gg_data;

t_gg_data	*gg_init(void);
void		*gg_malloc(t_gg_data *data, size_t size);
void		*gg_calloc(t_gg_data *data, size_t count, size_t size);
void		*gg_realloc(t_gg_data *data, void *ptr, size_t new_size);
void		gg_free(t_gg_data *data, void *ptr);
void		gg_free_all(t_gg_data *data);

#endif