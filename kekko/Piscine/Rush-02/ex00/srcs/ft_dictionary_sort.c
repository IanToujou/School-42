/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictionary_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:47:28 by ibour             #+#    #+#             */
/*   Updated: 2024/07/24 19:47:29 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_dictionary.h"

void	ft_swap_dictionary_entry(t_dict_entry *a, t_dict_entry *b)
{
	t_dict_entry	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_update_normal_flag(t_dict *dict)
{
	int				index;
	t_dict_entry	*entry;
	t_bool			normal;

	index = 0;
	while (index < dict->size)
	{
		entry = &dict->entries[index];
		normal = false;
		if (entry->value <= 20)
			normal = true;
		if (entry->value % 10 == 0)
			normal = true;
		entry->normal = normal;
		index++;
	}
}

void	ft_do_sort_dict(t_dict *dict, int start, int end,
						int (*func)(t_dict_entry*, t_dict_entry*))
{
	int				index;
	int				jndex;
	t_bool			swapped;
	t_dict_entry	*entries;

	entries = dict->entries;
	index = start;
	while (index < end)
	{
		jndex = start;
		swapped = false;
		while (jndex < end - index)
		{
			if ((*func)(&entries[jndex], &entries[jndex + 1]))
			{
				ft_swap_dictionary_entry(&entries[jndex], &entries[jndex + 1]);
				swapped = true;
			}
			jndex++;
		}
		index++;
		if (!swapped)
			break ;
	}
}

void	ft_sort_dictionary(t_dict *dict)
{
	int		index;
	int		index_of_zero;

	ft_update_normal_flag(dict);
	ft_do_sort_dict(dict, 0, dict->size - 1, &ft_sort_dict_f_normal);
	index = 0;
	index_of_zero = -1;
	while (index < dict->size)
	{
		if (dict->entries[index].value == 0)
		{
			index_of_zero = index;
			break ;
		}
		index++;
	}
	if (index_of_zero == -1)
		return ;
	ft_do_sort_dict(dict, index_of_zero, dict->size - 1, &ft_sort_dict_f_value);
	ft_do_sort_dict(dict, 0, index_of_zero, &ft_sort_dict_f_value);
}
