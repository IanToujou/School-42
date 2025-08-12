/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gg_collect.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:08:46 by ibour             #+#    #+#             */
/*   Updated: 2025/08/12 11:28:15 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GG_COLLECT_H
# define GG_COLLECT_H

#include <stdlib.h>

typedef struct s_gg_node {
	void *ptr;
	size_t size;
	struct s_gg_node *next;
}	t_gg_node;

typedef struct s_gg_data {
	t_gg_node *head;
	size_t alloc_count;
	size_t size;
}	t_gg_data;

#endif