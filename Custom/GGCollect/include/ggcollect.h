/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggcollect.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 08:55:40 by ibour             #+#    #+#             */
/*   Updated: 2025/05/12 09:08:02 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GGCOLLECT_H

# define GGCOLLECT_H

# include <stdlib.h>

# define HEAP_SIZE 1024 * 1024
# define MAX_ROOTS 1024

typedef struct s_gg_object
{
	size_t				size;
	int					marked;
	struct s_gg_object	*next;
	char				*data;
} t_gg_object;

typedef struct s_gg_data {
	t_gg_object	*heap;
	void		*roots[MAX_ROOTS];
	size_t		root_count;
} t_gg_data;

void	*gg_malloc(size_t size);

#endif
